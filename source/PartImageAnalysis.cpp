// Native
#include <vector>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/PartImageAnalysis.h"

using namespace std;
using namespace cv;

// === Initialization part ===
PIA::PIA(vector<Point> edge_pixels, vector<int> detected_pupil, int HorOrVer, int PxBeg, int PxEnd) :
	edge_pixels_(edge_pixels), 
	detected_pupil_(detected_pupil),
	HorOrVer_(HorOrVer),
	PxBeg_(PxBeg),
	PxEnd_(PxEnd)

{
}

PIA::~PIA()
{
}

vector<Point> PIA::contourFilterVer(vector<Point> edge_pixels, int PxBeg, int PxEnd)
{
	vector<Point> new_edge_pixels = {};

	for (int i = 0; i < edge_pixels.size(); i++) 
	{
		if (PxBeg < edge_pixels[i].x && PxEnd > edge_pixels[i].x)
		{
			new_edge_pixels.push_back(edge_pixels[i]);
		}
	}

	return new_edge_pixels;
}

vector<Point> PIA::contourFilterVer() 
{
	return contourFilterVer(edge_pixels_, PxBeg_, PxEnd_);
}

vector<Point> PIA::contourFilterHor(vector<Point> edge_pixels, int PxBeg, int PxEnd)
{
	vector<Point> new_edge_pixels = {};

	for (int i = 0; i < edge_pixels.size(); i++)
	{
		if (PxBeg < edge_pixels[i].y && PxEnd > edge_pixels[i].y)
		{
			new_edge_pixels.push_back(edge_pixels[i]);
		}
	}

	return new_edge_pixels;
}

vector<Point> PIA::contourFilterHor()
{
	return contourFilterHor(edge_pixels_, PxBeg_, PxEnd_);
}

vector<Point> PIA::contourFilter(vector<Point> edge_pixels, int PxBeg, int PxEnd, int HorOrVer)
{
	vector<Point> contour;

	if (HorOrVer == 0)
	{
		contour = contourFilterHor(edge_pixels, PxBeg, PxEnd);
	}
	else 
	{
		contour = contourFilterVer(edge_pixels, PxBeg, PxEnd);
	}

	return contour;
}

vector<Point> PIA::contourFilter() 
{
	return contourFilter(edge_pixels_, PxBeg_, PxEnd_, HorOrVer_);
}

