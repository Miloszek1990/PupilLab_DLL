#pragma once

using namespace std;
using namespace cv;

class DT
{
	public:
		// === Initialization part ===
		DT(Mat img, int val_GB, int val_AT, int val_number_of_points, int HorOrVer, vector<int> PxBegEnd);
		~DT();

		// === Input safety analysis ===

		// Check if the image as a matrix exists.
		// It is important becouse real time application might be killed by empty image object.
		// TO DO. For right now it returns 512 x 512 px matix of 255 vals - TO GENERALIZATION.
		Mat checkImgExists(Mat img);

		// Check if the number is odd. 
		// It is important, becouse DLL version of the program may work in real time in LabVIEW.
		// And becouse of that some methods of OpenCV take only odd nmbers as parameters
		// it is cruicial to check the number is odd - if not increaseit by 1.
		// Such approach wont kill the DLL if person  make a mistake in real time application.
		int checkOdd(int val);

		// Check if the number of point is not bigger than half of this value.
		// If it is, then divide it to two, and so on...
		int checkNumberOfPoints(vector<Point> contour, int number_of_points);

		// Check VerOrHor proper value.
		// 0 -> Horizontal filtration of contour.
		// 1 -> Vertical filtration of contour (default after test).
		int checkVerOrHor(int HorOrVer);

		// Check filtering thresholds.
		// Firstly check the order - if beg is after end -> swap them.
		vector<int> checkFilteringThresholdsOrder(vector<int> PxBegEnd);
		// Secondly check the size of the thresholds
		vector<int> checkSizeOfTheThresholds(vector<int> PxBegEnd, vector<int> img_wh, int HorOrVer);
};