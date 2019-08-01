// Native
#include <vector>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/Visualization.h"

// === Initialization part ===
Vis::Vis(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight, int HorOrVer, int PxBeg, int PxEnd) :
	imageBW_(imageBW), 
	contour_(contour), 
	Xc_(Xc), 
	Yc_(Yc), 
	R_(R), 
	pupil_X_beg_(pupil_X_beg), 
	pupil_Y_beg_(pupil_Y_beg), 
	pupil_width_(pupil_width), 
	pupil_hight_(pupil_hight),
	HorOrVer_(HorOrVer),
	PxBeg_(PxBeg),
	PxEnd_(PxEnd)
{}

Vis::~Vis()
{}

// === Visualization base ===
void Vis::showImage(Mat imageBW)
{
	namedWindow("Display window", WINDOW_AUTOSIZE);    // Create a window for display.
	imshow("Display window", imageBW);                 // Show our image inside it.
	waitKey(0);                                        // Wait for some button
}

void Vis::showImage()
{
	showImage(imageBW_);
}

void Vis::showCleanImage(Mat imageBW) 
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);  

	showImage(imageBW);
}

void Vis::showCleanImage()
{
	showCleanImage(imageBW_);
}

// === Visualise contour ===
void Vis::showContour(Mat imageBW, vector<Point> contour) 
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);

	vector<vector<Point>> c;
	c.push_back(contour);

	drawContours(color_image, c, -1, Scalar(255, 0, 255), 1, 8);

	showImage(color_image);
}

void Vis::showContour()
{
	showContour(imageBW_, contour_);
}

// === Visualise circle ===
void Vis::showCircle(Mat imageBW, int Xc, int Yc, int R)
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);

	circle(color_image, Point(Xc, Yc), R, Scalar(0, 255, 0), 1);

	showImage(color_image);
}

void Vis::showCircle()
{
	showCircle(imageBW_, Xc_, Yc_, R_);
}

// === Visualise rectangle ===
void Vis::showRect(Mat imageBW, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight)
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);

	Point pt1(pupil_X_beg, pupil_Y_beg);
	Point pt2(pupil_X_beg + pupil_width, pupil_Y_beg + pupil_hight);
	rectangle(color_image, pt1, pt2, cv::Scalar(0, 255, 0));

	showImage(color_image);
}

void Vis::showRect()
{
	showRect(imageBW_, pupil_X_beg_, pupil_Y_beg_, pupil_width_, pupil_hight_);
}

// Show combined - contour with circle
void Vis::showContourWithCircle(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R)
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);

	vector<vector<Point>> c;
	c.push_back(contour);

	drawContours(color_image, c, -1, Scalar(255, 0, 255), 1, 8);
	circle(color_image, Point(Xc, Yc), R, Scalar(0, 255, 0), 1);

	showImage(color_image);
}

void Vis::showContourWithCircle()
{
	showContourWithCircle(imageBW_, contour_, Xc_, Yc_, R_);
}

// Show combined - contour with circle with rectangle
void Vis::showContourWithCircleWithRectangle(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight)
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);

	vector<vector<Point>> c;
	c.push_back(contour);

	drawContours(color_image, c, -1, Scalar(255, 0, 255), 1, 8);
	circle(color_image, Point(Xc, Yc), R, Scalar(0, 255, 0), 1);

	Point pt1(pupil_X_beg, pupil_Y_beg);
	Point pt2(pupil_X_beg + pupil_width, pupil_Y_beg + pupil_hight);
	rectangle(color_image, pt1, pt2, cv::Scalar(255, 255, 0));

	showImage(color_image);
}

void Vis::showContourWithCircleWithRectangle()
{
	showContourWithCircleWithRectangle(imageBW_, contour_, Xc_, Yc_, R_, pupil_X_beg_, pupil_Y_beg_, pupil_width_, pupil_hight_);
}

void Vis::showContourWithCircleWithRectangleWithPIA(Mat imageBW, vector<Point> contour, int Xc, int Yc, int R, int pupil_X_beg, int pupil_Y_beg, int pupil_width, int pupil_hight, int VerOrHor, int PxBeg, int PxEnd)
{
	Mat color_image;
	cvtColor(imageBW, color_image, COLOR_GRAY2BGR);

	vector<vector<Point>> c;
	c.push_back(contour);

	drawContours(color_image, c, -1, Scalar(255, 0, 255), 1, 8);
	circle(color_image, Point(Xc, Yc), R, Scalar(0, 255, 0), 1);

	Point pt1(pupil_X_beg, pupil_Y_beg);
	Point pt2(pupil_X_beg + pupil_width, pupil_Y_beg + pupil_hight);
	rectangle(color_image, pt1, pt2, cv::Scalar(255, 255, 0));


	if (VerOrHor == 0) 
	{
		line(color_image, Point(0, PxBeg), Point(imageBW.cols, PxBeg), Scalar(0, 0, 255), 1);
		line(color_image, Point(0, PxEnd), Point(imageBW.cols, PxEnd), Scalar(0, 0, 255), 1);
	} 
	else 
	{
		line(color_image, Point(PxBeg, 0), Point(PxBeg, imageBW.rows), Scalar(0, 0, 255), 1);
		line(color_image, Point(PxEnd, 0), Point(PxEnd, imageBW.rows), Scalar(0, 0, 255), 1);
	}

	showImage(color_image);
}

void Vis::showContourWithCircleWithRectangleWithPIA()
{
	showContourWithCircleWithRectangleWithPIA(imageBW_, contour_, Xc_, Yc_, R_, pupil_X_beg_, pupil_Y_beg_, pupil_width_, pupil_hight_, HorOrVer_, PxBeg_, PxEnd_);
}