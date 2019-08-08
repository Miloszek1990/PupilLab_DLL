#pragma once

using namespace std;
using namespace cv;

class PIA
{
	private:
		vector<Point> edge_pixels_;
		int HorOrVer_;
		int PxBeg_, PxEnd_;

	public:
		// === Initialization part ===
		PIA(vector<Point> edge_pixels, int HorOrVer, int PxBeg, int PxEnd);
		~PIA();

		// === Contour points filtering ===
		vector<Point> contourFilterVer(vector<Point> edge_pixels, int PxBeg, int PxEnd);
		vector<Point> contourFilterVer();

		vector<Point> contourFilterHor(vector<Point> edge_pixels, int PxBeg, int PxEnd);
		vector<Point> contourFilterHor();

		vector<Point> contourFilter(vector<Point> edge_pixels, int PxBeg, int PxEnd, int HorOrVer);
		vector<Point> contourFilter();
};