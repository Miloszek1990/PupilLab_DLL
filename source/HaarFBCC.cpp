// Native
#include <vector>
#include <cmath>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/HaarFBCC.h"

// === Initialization part ===
HFBCC::HFBCC(Mat imageBW, string HaarPathXML, vector<int> Paddings, vector<int> img_wh) :
	imageBW_(imageBW), 
	HaarPathXML_(HaarPathXML),
	Paddings_(Paddings),
	img_wh_(img_wh)
{}

HFBCC::~HFBCC()
{}

// === Detect pupil ===
vector<int> HFBCC::pupilDetectionHFBCC(Mat imageBW, string HaarPathXML)
{
	Mat img_mtx_BGR;
	CascadeClassifier pupil_cascade;
	vector<Rect> pupils;
	vector<int> pupil;

	//cvtColor(imageBW, img_mtx_BGR, COLOR_GRAY2BGR);

	pupil_cascade.load(HaarPathXML);

	pupil_cascade.detectMultiScale(imageBW, pupils, 1.2, 1, 0 | CASCADE_SCALE_IMAGE, Size(200, 200));

	pupil.push_back(pupils[0].x);
	pupil.push_back(pupils[0].y);
	pupil.push_back(pupils[0].width);
	pupil.push_back(pupils[0].height);
	/*
	for (size_t i = 0; i < pupils.size(); i++)
	{
		Point pt1(pupils[i].x, pupils[i].y);
		Point pt2(pupils[i].x + pupils[i].width, pupils[i].y + pupils[i].height);
		rectangle(img_mtx_BGR, pt1, pt2, Scalar(0, 255, 0));
	}
	*/

	return pupil;
}

vector<int> HFBCC::pupilDetectionHFBCC()
{
	return pupilDetectionHFBCC(imageBW_, HaarPathXML_);
}

// === Resize detected pupil only part by paddings ===
vector<int> HFBCC::addPad(vector<int> detected_pupil, vector<int> Paddings, vector<int> img_wh)
{
	vector<int> detected_pupil_new = detected_pupil;

	// Add paddings
	detected_pupil_new[0] = detected_pupil[0] - Paddings[0];               // x_new
	detected_pupil_new[1] = detected_pupil[1] - Paddings[2];               // y_new
	detected_pupil_new[2] = detected_pupil[2] + Paddings[0] + Paddings[1]; // w_new
	detected_pupil_new[3] = detected_pupil[3] + Paddings[2] + Paddings[3]; // h_new
	
	// Left top point
	// Left bottom point
	// Right top point
	// Right bottom point
	int new_pup_reg_coords[4][2] = { {detected_pupil_new[0], detected_pupil_new[1]},
							         {detected_pupil_new[0], detected_pupil_new[1] + detected_pupil_new[3]},
	                                 {detected_pupil_new[0] + detected_pupil_new[2], detected_pupil_new[1]}, 
							         {detected_pupil_new[0] + detected_pupil_new[2], detected_pupil_new[1] + detected_pupil_new[3]} };
	
	if (new_pup_reg_coords[0][0] < 0) { new_pup_reg_coords[0][0] = 0; };
	if (new_pup_reg_coords[0][1] < 0) { new_pup_reg_coords[0][1] = 0; };
	if (new_pup_reg_coords[1][0] < 0) { new_pup_reg_coords[1][0] = 0; };
	if (new_pup_reg_coords[1][1] > img_wh[1]) { new_pup_reg_coords[1][1] = img_wh[1]; };
	if (new_pup_reg_coords[2][0] > img_wh[0]) { new_pup_reg_coords[2][0] = img_wh[0]; };
	if (new_pup_reg_coords[2][1] < 0) { new_pup_reg_coords[2][1] = 0; };
	if (new_pup_reg_coords[3][0] > img_wh[0]) { new_pup_reg_coords[3][0] = img_wh[0]; };
	if (new_pup_reg_coords[3][1] > img_wh[1]) { new_pup_reg_coords[3][1] = img_wh[1]; };
	
	detected_pupil_new[0] = new_pup_reg_coords[0][0];
	detected_pupil_new[1] = new_pup_reg_coords[0][1];
	detected_pupil_new[2] = new_pup_reg_coords[2][0] - new_pup_reg_coords[0][0];
	detected_pupil_new[3] = new_pup_reg_coords[1][1] - new_pup_reg_coords[0][1];

	return detected_pupil_new;
}

vector<int> HFBCC::addPad(vector<int> detected_pupil)
{
	return addPad(detected_pupil, Paddings_, img_wh_);
}

// === Shift contour ===
vector<Point> HFBCC::contourShift(vector<Point> contour, int x_shift, int y_shift)
{
	for (int i = 0; i < contour.size(); i++)
	{
		contour[i].x = contour[i].x + x_shift;
		contour[i].y = contour[i].y + y_shift;
	}

	return contour;
}
