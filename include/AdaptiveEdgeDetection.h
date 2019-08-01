#pragma once

using namespace std;
using namespace cv;

class AED
{
	private:
		// === Attributes ===
		Mat img_;
		int GB_;
		int AT_;

	public:
		// === Initialization part ===
		AED(Mat img, int GB, int AT);
		~AED();

		// === Help functions ===
		// Show Mat object - show image
		void printImage(Mat img);
		void printImage();

		// === Laplace part ===
		// Extracts laplace image in the Adaptive Edge Detection way
		Mat laplaceImage(Mat img, int GB, int AT);
		Mat laplaceImage(Mat img, int GB);
		Mat laplaceImage(Mat img);
		Mat laplaceImage();

		// === Suzuki part ===
		// Extracts the contours from Laplace image with 3 px size aperture
		vector<vector<Point>> pupilEdge(Mat LaplaceMtx);
		vector<vector<Point>> pupilEdge();

		// === Biggest contour extraction ===
		// Find longest contour and match it as a exact pupil edge coordinate list/vector
		vector<Point> getBiggestContour(vector<vector<Point>> contours);
		vector<Point> getBiggestContour();
};