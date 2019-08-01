#pragma once

using namespace std;
using namespace cv;

class Vis
{
	private:
		Mat imageBW_;
		vector<Point> contour_;
		int Xc_, Yc_, R_;
		int pupil_X_beg_, pupil_Y_beg_, pupil_width_, pupil_hight_;
		int HorOrVer_, PxBeg_, PxEnd_;

	public:
		Vis(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight, int HorOrVer, int PxBeg, int PxEnd);
	    ~Vis();

		// Show image method - any
		void showImage(Mat imageBW); 
		void showImage();

		// Show image method - with conversion from BW to color
		void showCleanImage(Mat imageBW);
		void showCleanImage();

		// Show image with biggest contour
		void showContour(Mat imageBW, vector<Point> contour);
		void showContour();

		// Show image with fitted circle to pupil edge
		void showCircle(Mat imageBW, int Xc, int Yc, int R);
		void showCircle();

		// Show image with detected rectangle
		void showRect(Mat imageBW, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight);
		void showRect();

		// Show combined - contour with circle
		void showContourWithCircle(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R);
		void showContourWithCircle();

		// Show combined - contour with circle with rectangle
		void showContourWithCircleWithRectangle(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight);
		void showContourWithCircleWithRectangle();

		// Show combined - contour with circle with rectangle with PIA borders
		void showContourWithCircleWithRectangleWithPIA(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight, int HorOrVer, int PxBeg, int PxEnd);
		void showContourWithCircleWithRectangleWithPIA();
};