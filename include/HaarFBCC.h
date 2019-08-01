#pragma once

using namespace std;
using namespace cv;

class HFBCC 
{
	private:
		Mat imageBW_;
		string HaarPathXML_;
		vector<int> Paddings_;
		vector<int> img_wh_;

	public:
		HFBCC(Mat imageBW, string HaarPathXML, vector<int> Paddings, vector<int> img_wh);
		~HFBCC();
		
		// === Detect pupil ===
		vector<int> pupilDetectionHFBCC(Mat imageBW, string HaarPathXML);
		vector<int> pupilDetectionHFBCC();

		// === Resize detected pupil only part by paddings ===
		vector<int> addPad(vector<int> detected_pupil, vector<int> Paddings, vector<int> img_wh);
		vector<int> addPad(vector<int> detected_pupil);

		// === Shift contour ===
		vector<Point> contourShift(vector<Point> contour, int x_shift, int y_shift);

};