// Native
#include <vector>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/AdaptiveEdgeDetection.h"

using namespace std;
using namespace cv;

// === Initialization part ===
AED::AED(Mat img, int GB, int AT) : 
	img_(img), 
	GB_(GB), 
	AT_(AT)
{
}

AED::~AED()
{
}

// === Help functions ===
void AED::printImage(Mat img)
{
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", img);
	waitKey(0);
}

void AED::printImage()
{
	printImage(img_);
}

// === Laplacian part ===
Mat AED::laplaceImage(Mat img, int GB, int AT)
{
	// Create a destination Mat object
	Mat pre_filt;
	Mat adaptive;
	Mat laplace;

	// Process the image
	GaussianBlur(img, pre_filt, Size(GB, GB), 0, 0);
	adaptiveThreshold(pre_filt, adaptive, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, AT, 1);
	Laplacian(adaptive,laplace, CV_8UC1); //CV_64F CV_8UC1

	return laplace;
}

Mat AED::laplaceImage(Mat img, int GB)
{
	return laplaceImage(img, GB, AT_);
}

Mat AED::laplaceImage(Mat img)
{
	return laplaceImage(img, GB_, AT_);
}

Mat AED::laplaceImage()
{
	return laplaceImage(img_, GB_, AT_);
}

// === Suzuki part ===
vector<vector<Point>> AED::pupilEdge(Mat laplaceMtx)
{
	// Define attributes
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	
	// Find contours
	findContours(laplaceMtx, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	return contours;
}

vector<vector<Point>> AED::pupilEdge()
{
	return pupilEdge(laplaceImage());
}

vector<Point> AED::getBiggestContour(vector<vector<Point>> contours)
{
	vector<Point> biggest_one = {};

	if (!contours.empty()) {
		int largest_area = 0; // initialize the largest area
		int lci = 0; // initialize the largest contour index
		for (int i = 0; i < contours.size(); i++) {
			// Iterate through each contour. 
			int a = contourArea(contours[i], false); // Find the area of contour
			if (a > largest_area) {
				largest_area = a;
				lci = i; // Store the index of largest contour
			}
		}

		biggest_one = contours[lci];
	}

	return biggest_one;
}

vector<Point> AED::getBiggestContour()
{
	return getBiggestContour(pupilEdge());
}