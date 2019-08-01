// Native
#include <vector>
#include <cmath>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/DynamicTests.h"

// === Initialization part ===
DT::DT(Mat img, int val_GB, int val_AT, int val_number_of_points, int HorOrVer, vector<int> PxBegEnd)
{
}

DT::~DT()
{
}

Mat DT::checkImgExists(Mat img)
{
	if (!img.data)
	{
		Mat img(512, 512, CV_8SC1, Scalar::all(255));
	}

	return img;
}

int DT::checkOdd(int val)
{
	if (val % 2 == 0)
	{
		val = val + 1;
	}
	else
	{
		val = val;
	}

	return val;
}

int DT::checkNumberOfPoints(vector<Point> contour, int number_of_points)
{
	int N;

	if (number_of_points >= rint(contour.size() / 2)) {
		//cout << "Number of points to fit the circle is bigger than half of all points." << endl;

		while (number_of_points > rint(contour.size() / 2)) {
			//cout << number_of_points << endl;
			number_of_points = rint(number_of_points / 2);
		}
		N = number_of_points;
		//cout << N << endl;
	}
	else if (number_of_points < 3) {
		//cout << "Number of points to fit the circle is lower than 3 points." << endl;
		//cout << "Three points are crucial and minimal for circle fitting in this method." << endl;
		N = 3;
	}
	else {
		//cout << "Number of points to fit the circle is ok." << endl;
		N = number_of_points;
	}
	return N;
}

int DT::checkVerOrHor(int HorOrVer)
{
	if (HorOrVer == 0)
	{
		HorOrVer = 0;
	}
	else {
		HorOrVer = 1;
	}

	return HorOrVer;
}

vector<int> DT::checkFilteringThresholdsOrder(vector<int> PxBegEnd)
{
	vector<int> new_vec;

	if (PxBegEnd[0] > PxBegEnd[1]) 
	{
		new_vec.push_back(PxBegEnd[1]);
		new_vec.push_back(PxBegEnd[0]);
	}
	else {
		new_vec = PxBegEnd;
	}

	return new_vec;
}

vector<int> DT::checkSizeOfTheThresholds(vector<int> PxBegEnd, vector<int> img_wh, int HorOrVer)
{
	// Set default thresholds of beg and end.  
	vector<int> new_vec = {0};
	if (HorOrVer == 0)
	{
		new_vec.push_back(img_wh[0]);
	}
	else 
	{
		new_vec.push_back(img_wh[1]);
	}

	// Beg threshold check
	// 1 case - check if the first element is not smaller than zero or image size.
	if (HorOrVer == 0)
	{
		if (PxBegEnd[0] > 0 && PxBegEnd[0] < img_wh[0]) 
		{
			new_vec[0] = PxBegEnd[0];
		}
	}
	else
	{
		if (PxBegEnd[0] > 0 && PxBegEnd[0] < img_wh[1])
		{
			new_vec[0] = PxBegEnd[0];
		}
	}

	// 2 case - check if the first element is not greather than size of the image
	if (HorOrVer == 0)
	{
		if (PxBegEnd[1] > 0 && PxBegEnd[1] < img_wh[0])
		{
			new_vec[1] = PxBegEnd[1];
		}
	}
	else
	{
		if (PxBegEnd[1] > 0 && PxBegEnd[1] < img_wh[1])
		{
			new_vec[1] = PxBegEnd[1];
		}
	}

	return new_vec;
}