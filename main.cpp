// Native
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// LabVIEW headers
#include <extcode.h>
#include <fundtypes.h>
#include <platdefines.h>

// Own methods
#include "../include/DynamicTests.h"
#include "../include/AdaptiveEdgeDetection.h"
#include "../include/CircleFit.h"
#include "../include/HaarFBCC.h"
#include "../include/ReturnOfTheKing.h"
#include "../include/Visualization.h"
#include "../include/PartImageAnalysis.h"

using namespace std;
using namespace cv;

// === Dll entry point ===
BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(hModule);
	UNREFERENCED_PARAMETER(lpReserved);
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

// === Function to export as DLL ===
extern "C" __declspec(dllexport) char* PupilData(
	                                             const uint8_t *__arr[], 
	                                             const uint16_t __img_rows,
	                                             const uint16_t __img_cols,
												 uint8_t __AT, 
												 uint8_t __GB,
												 uint8_t __N_pts,
												 uint8_t __HorOrVer,
												 uint16_t __PxBeg,
												 uint16_t __PxEnd,
	                                             uint16_t __lw_pad,
	                                             uint16_t __rw_pad,
	                                             uint16_t __tw_pad,
	                                             uint16_t __bw_pad
                                                )
{
	// === Define the data ===
	string HaarPathXML                  = "C:\\Users\\oem\\Desktop\\Machine_Vision\\haar\\trained_haars\\data_pos1.35k_neg_2.7k_w16h16\\cascade.xml";

	// === Read the data ===
	// General
	int _img_rows                       = (int)__img_rows;
	int _img_cols                       = (int)__img_cols;

	Mat _img_mtx(Size(_img_rows, _img_cols), CV_8U, __arr);
	int _GB                             = (int)__GB;
	int _AT                             = (int)__AT;
	int _N_pts                          = (int)__N_pts;

	// Part Image analysis - PIA
	int _HorOrVer                       = (int)__HorOrVer; // 0, 1 -> Horizontal, Vertical filtration
	int _PxBeg                          = (int)__PxBeg;
	int _PxEnd                          = (int)__PxEnd;

	// Haar detector - HFBCC
	int _lw_pad                         = (int)__lw_pad; // left
	int _rw_pad                         = (int)__rw_pad; // right
	int _tw_pad                         = (int)__tw_pad; // top 
	int _bw_pad                         = (int)__bw_pad; // bottom

	vector<int> _PxBegEnd               = { _PxBeg, _PxEnd };
	vector<int> Paddings                = { _lw_pad, _rw_pad, _tw_pad, _bw_pad };

	// === Output information ===
	vector<float> X_Y, R_S;
	string out;

	// === Data control part 1/3 ===
	DT DynamicTest(_img_mtx, _GB, _AT, _N_pts, _HorOrVer, _PxBegEnd);

	Mat img_mtx                         = DynamicTest.checkImgExists(_img_mtx);
	int GB                              = DynamicTest.checkOdd(_GB);
	int AT                              = DynamicTest.checkOdd(_AT);

	// === Default values ===
	//vector<int> img_wh = { img_mtx.rows, img_mtx.cols };
	vector<int> img_wh                  = { _img_rows, _img_cols };
	int tmp_X                           = rint(img_wh[1] / 2);
	int tmp_Y                           = rint(img_wh[0] / 2);
	int tmp_R                           = 1;
	int tmp_S                           = 1;

	// === Data control part 2/3 ===
	int HorOrVer                        = DynamicTest.checkVerOrHor(_HorOrVer);
	vector<int> PxBegEnd                = DynamicTest.checkFilteringThresholdsOrder(_PxBegEnd);
	PxBegEnd                            = DynamicTest.checkSizeOfTheThresholds(PxBegEnd, img_wh, HorOrVer);

	try {
		// === Main algorithm ===
		HFBCC HC(img_mtx, HaarPathXML, Paddings, img_wh);
		vector<int> detected_pupil      = HC.pupilDetectionHFBCC();
		vector<int> detected_pupil_pad  = HC.addPad(detected_pupil);
		Mat img_pup                     = img_mtx(Rect(detected_pupil_pad[0], detected_pupil_pad[1], detected_pupil_pad[2], detected_pupil_pad[3]));

		AED img(img_pup, GB, AT);
		vector<Point> contour           = img.getBiggestContour();
		contour                         = HC.contourShift(contour, detected_pupil_pad[0], detected_pupil_pad[1]);

		if (!contour.empty()) {
			// === Data control part 3/3 ===
			int N_pts                   = DynamicTest.checkNumberOfPoints(contour, _N_pts);

			// === SCENARIO 1 - AED + HFBCC + PIA ===
			Fit ft(contour, N_pts);
			X_Y                         = ft.solveLinearEqSystem();
			R_S                         = ft.errors();

			int X                       = rint(X_Y[0]);
			int Y                       = rint(X_Y[1]);
			int R                       = rint(R_S[0]);
			int S                       = rint(R_S[1]);

			// Find Contour (FC)
			PIA FC(contour, detected_pupil_pad, HorOrVer, PxBegEnd[0], PxBegEnd[1]);
			vector<Point> contour       = FC.contourFilter();

			ROTK output(1);
			out                         = output.returnCalculated(X, Y, R, S);
		}
		else {
			ROTK output(2);
			out                         = output.returnDefault(tmp_X, tmp_Y, tmp_R, tmp_S);
		}

	}
	catch (...) {
		ROTK output(3);
		out                             = output.returnDefault(tmp_X, tmp_Y, tmp_R, tmp_S);
	}

	// === Change string to char table and return it as an DLL output ===
	char* C_pupil_data                  = new char[out.size() + 1];
	copy(out.begin(), out.end(), C_pupil_data);
	C_pupil_data[out.size()]            = '\0';

	return C_pupil_data;
}