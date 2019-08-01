// Native
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

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

int main(int argc, char** argv)
{
	// === Define the data ===
	string test_images_path = "C:\\Users\\oem\\Desktop\\Machine_Vision\\Program_PupilDetection\\Pupil detection_one_image\\images\\";
	//string img_1 = test_images_path + "light_center_during_1.bmp";
	string img_1 = test_images_path + "light_center_before_1.bmp";
	//string img_1 = test_images_path + "white.bmp";

	string HaarPathXML = "C:\\Users\\oem\\Desktop\\Machine_Vision\\haar\\trained_haars\\data_pos1.35k_neg_2.7k_w16h16\\cascade.xml";

	// === Read the data ===
	// General
	Mat _img_mtx          = imread(img_1, 0);
	int _GB               = 7;
	int _AT               = 31;
	int _number_of_points = 255;
	
	// Part Image analysis - PIA
	int _HorOrVer         = 1; // 0, 1 -> Horizontal, Vertical filtration
	int _PxBeg            = 100;
	int _PxEnd            = 300;
	
	// Haar detector - HFBCC
	int _lw_pad           = 0; // left
	int _rw_pad           = 0; // right
	int _tw_pad           = 0; // top 
	int _bw_pad           = 0; // bottom

	vector<int> _PxBegEnd = { _PxBeg, _PxEnd };
	vector<int> Paddings  = { _lw_pad, _rw_pad, _tw_pad, _bw_pad };

	// === Output information ===
	vector<float> X_Y, R_S;
	string out;

	// === Data control part 1/3 ===
	DT DynamicTest(_img_mtx, _GB, _AT, _number_of_points, _HorOrVer, _PxBegEnd);

	Mat img_mtx           = DynamicTest.checkImgExists(_img_mtx);
	int GB                = DynamicTest.checkOdd(_GB);
	int AT                = DynamicTest.checkOdd(_AT);

	// === Default values ===
	vector<int> img_wh    = { img_mtx.rows, img_mtx.cols };
	int tmp_X             = rint(img_wh[1] / 2);
	int tmp_Y             = rint(img_wh[0] / 2);
	int tmp_R             = 1;
	int tmp_S             = 1;

	// === Data control part 2/3 ===
	int HorOrVer          = DynamicTest.checkVerOrHor(_HorOrVer);
	vector<int> PxBegEnd  = DynamicTest.checkFilteringThresholdsOrder(_PxBegEnd);
	PxBegEnd              = DynamicTest.checkSizeOfTheThresholds(PxBegEnd, img_wh, HorOrVer);

	try {
		// === Main algorithm ===
		HFBCC HC(img_mtx, HaarPathXML, Paddings, img_wh);
		vector<int> detected_pupil     = HC.pupilDetectionHFBCC();
		vector<int> detected_pupil_pad = HC.addPad(detected_pupil);
		Mat img_pup                    = img_mtx(Rect(detected_pupil_pad[0], detected_pupil_pad[1], detected_pupil_pad[2], detected_pupil_pad[3]));
		
		AED img(img_pup, GB, AT);
		vector<Point> contour          = img.getBiggestContour();
		contour                        = HC.contourShift(contour, detected_pupil_pad[0], detected_pupil_pad[1]);

		if (!contour.empty()) {
			// === Data control part 3/3 ===
			int number_of_points       = DynamicTest.checkNumberOfPoints(contour, _number_of_points);
			
			// === SCENARIO 1 - AED + HFBCC + PIA ===
			Fit ft(contour, number_of_points);
			X_Y                        = ft.solveLinearEqSystem();
			R_S                        = ft.errors();

			int X                      = rint(X_Y[0]);
			int Y                      = rint(X_Y[1]);
			int R                      = rint(R_S[0]);
			int S                      = rint(R_S[1]);
			
			// Find Contour (FC)
			PIA FC(contour, detected_pupil_pad, HorOrVer, PxBegEnd[0], PxBegEnd[1]);
			vector<Point> contour      = FC.contourFilter();

			Vis VB(img_mtx, contour, X, Y, R, detected_pupil_pad[0], detected_pupil_pad[1], detected_pupil_pad[2], detected_pupil_pad[3], HorOrVer, PxBegEnd[0], PxBegEnd[1]);
			VB.showContourWithCircleWithRectangleWithPIA();

			ROTK output(1);
			out                        = output.returnCalculated(X, Y, R, S);
		}
		else {
			ROTK output(2);
			out                        = output.returnDefault(tmp_X, tmp_Y, tmp_R, tmp_S);
		}

		cout << out << endl;

	}
	catch (...) {
		ROTK output(3);
		out                            = output.returnDefault(tmp_X, tmp_Y, tmp_R, tmp_S);

		cout << out << endl;
	}

	return 0;
}