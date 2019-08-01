// Native
#include <vector>
#include <cmath>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/AdaptiveEdgeDetection.h"
#include "../include/CircleFit.h"

using namespace std;
using namespace cv;

// === Initialization part ===
Fit::Fit(vector<Point> edge_pixels, int number_of_points) : 
	edge_pixels_(edge_pixels), 
	number_of_points_(number_of_points)
{
}

Fit::~Fit()
{
}

// === Points to fit preparation ===
vector<Point> Fit::pointsToFitTheCircle(vector<Point> edge_pixels, int number_of_points)
{
	vector<Point> pupil_subvectors_centers;

	int beg_subvec = 0;
	int end_subvec = rint(edge_pixels.size() / number_of_points);
	for (int i = 0; i < number_of_points; i++)
	{
		//	Choose center Point of every sub_vector.
		//	Circle will be fitted to those points.
		pupil_subvectors_centers.push_back(edge_pixels[beg_subvec + rint((end_subvec - beg_subvec) / 2)]);
		//cout << beg_subvec + int((end_subvec - beg_subvec) / 2) << endl;

		beg_subvec = end_subvec + 1;
		end_subvec = (i + 2) * rint(edge_pixels.size() / number_of_points);
	}

	return pupil_subvectors_centers;
}

vector<Point> Fit::pointsToFitTheCircle(vector<Point> edge_pixels)
{
	return pointsToFitTheCircle(edge_pixels, number_of_points_);
}

vector<Point> Fit::pointsToFitTheCircle()
{
	return pointsToFitTheCircle(edge_pixels_, number_of_points_);
}

vector<int> Fit::takeThePointColumnFromVector_X(vector<Point> vector_to_divide)
{
	vector<int> one_column_vector;
	for (int i = 0; i < vector_to_divide.size(); i++) {
		one_column_vector.push_back(vector_to_divide[i].x);
	}

	return one_column_vector;
}

vector<int> Fit::takeThePointColumnFromVector_X()
{
	return takeThePointColumnFromVector_X(pointsToFitTheCircle());
}

vector<int> Fit::takeThePointColumnFromVector_Y(vector<Point> vector_to_divide)
{
	vector<int> one_column_vector;
	for (int i = 0; i < vector_to_divide.size(); i++) {
		one_column_vector.push_back(vector_to_divide[i].y);
	}

	return one_column_vector;
}

vector<int> Fit::takeThePointColumnFromVector_Y()
{
	return takeThePointColumnFromVector_Y(pointsToFitTheCircle());
}

// === Math methods ===
// Summing methods
float Fit::vectorSumInt(vector<int> v)
{
	float acc_sum = 0;
	for (int i = 0; i < v.size(); i++) {
		acc_sum += v[i];
	}

	return acc_sum;
}

float Fit::vectorSumFloat(vector<float> v)
{
	float acc_sum = 0;
	for (int i = 0; i < v.size(); i++) {
		acc_sum += v[i];
	}

	return acc_sum;
}

// Mean methods
// Takes vector of int's or float's, but always returns float -> it is average...
float Fit::vectorMeanInt(vector<int> v)
{
	float mean = vectorSumInt(v) / v.size();

	return mean;
}

float Fit::vectorMeanFloat(vector<float> v)
{
	float mean = vectorSumFloat(v) / v.size();

	return mean;
}

// STD methods
float Fit::vectorStandardDevInt(vector<int> v)
{
	float mean = vectorMeanInt(v);

	float std = 0;
	for (int i = 0; i < v.size(); i++) {
		std += (v[i] - mean) * (v[i] - mean);
	}

	std = sqrt(std / (v.size() - 1));

	return std;
}

float Fit::vectorStandardDevFloat(vector<float> v)
{
	float mean = vectorMeanFloat(v);

	float std = 0;
	for (int i = 0; i < v.size(); i++) {
		std += (v[i] - mean) * (v[i] - mean);
	}

	std = sqrt(std / (v.size() - 1));

	return std;
}

// === Fitting circle part === 
// Reduced coordinates of pupil
vector<float> Fit::reducedCoordinates(vector<int> v)
{
	// Pupil barycenter
	float coord_mean = vectorMeanInt(v);

	// Reduced coords
	vector<float> uv;
	for (int i = 0; i < v.size(); i++) {
		uv.push_back(v[i] - coord_mean);
	}

	return uv;
}

vector<float> Fit::linSysParams(vector<float> u, vector<float> v)
{
	vector<float> Suu;
	vector<float> Suv;
	vector<float> Svv;
	vector<float> Suuv;
	vector<float> Suvv;
	vector<float> Suuu;
	vector<float> Svvv;

	for (int i = 0; i < u.size(); i++) {

		Suu.push_back(u[i] * u[i]);
		Suv.push_back(u[i] * v[i]);
		Svv.push_back(v[i] * v[i]);
		Suuv.push_back(u[i] * u[i] * v[i]);
		Suvv.push_back(u[i] * v[i] * v[i]);
		Suuu.push_back(u[i] * u[i] * u[i]);
		Svvv.push_back(v[i] * v[i] * v[i]);
	}

	vector<float> params;
	params.push_back(vectorSumFloat(Suu));
	params.push_back(vectorSumFloat(Suv));
	params.push_back(vectorSumFloat(Svv));
	params.push_back(vectorSumFloat(Suuu));
	params.push_back(vectorSumFloat(Suvv));
	params.push_back(vectorSumFloat(Svvv));
	params.push_back(vectorSumFloat(Suuv));

	return params;
}

vector<float> Fit::linSysParams()
{
	vector<float> u = reducedCoordinates(takeThePointColumnFromVector_X());
	vector<float> v = reducedCoordinates(takeThePointColumnFromVector_Y());
	
	return linSysParams(u, v);
}

vector<float> Fit::solveLinearEqSystem(vector<float> LSParameters, vector<int> X_ax_of_contour, vector<int> Y_ax_of_contour)
{
	/*

	float A[2][2] = {
					{S[0], S[1]}, // |a, b|
					{S[1], S[2]}  // |c, d|
					};
	float B[2]    = {
					(S[3] + S[4]) / 2, // |e|
					(S[5] + S[6]) / 2  // |f|
					};

	for (int i = 0; i < 2; i++) {
		cout << B[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}

	Wr = (a * d - b * c)
	Wx = (e * d - b * f)
	Wy = (a * f - e * c)
	x = Wx / Wr
	y = Wy / Wr

	*/

	float Wr = (LSParameters[0] * LSParameters[2]) - (LSParameters[1] * LSParameters[1]);

	float x, y;
	if (Wr >= 1) {
		float uc = (LSParameters[2] * ((LSParameters[3] + LSParameters[4]) / 2) - LSParameters[1] * ((LSParameters[5] + LSParameters[6]) / 2)) / Wr;
		float vc = (LSParameters[0] * ((LSParameters[5] + LSParameters[6]) / 2) - LSParameters[1] * ((LSParameters[3] + LSParameters[4]) / 2)) / Wr;

		x = vectorMeanInt(X_ax_of_contour) + uc;
		y = vectorMeanInt(Y_ax_of_contour) + vc;
	}
	else {
		x = 0;
		y = 0;
	}

	vector<float> xy_pupil_center;
	xy_pupil_center.push_back(x);
	xy_pupil_center.push_back(y);

	return xy_pupil_center;
}

vector<float> Fit::solveLinearEqSystem(vector<float> LSParameters)
{
	vector<int> X_ax_of_contour_tmp = takeThePointColumnFromVector_X();
	vector<int> Y_ax_of_contour_tmp = takeThePointColumnFromVector_Y();

	return solveLinearEqSystem(LSParameters, X_ax_of_contour_tmp, Y_ax_of_contour_tmp);
}

vector<float> Fit::solveLinearEqSystem()
{
	return solveLinearEqSystem(linSysParams());
}

vector<float> Fit::errors(vector<float> XY_calc_center, vector<int> X_ax_of_contour, vector<int> Y_ax_of_contour)
{
	vector<float> Ri;
	for (int i = 0; i < X_ax_of_contour.size(); i++) {

		float a = (float)X_ax_of_contour[i] - XY_calc_center[0];
		float b = (float)Y_ax_of_contour[i] - XY_calc_center[1];

		Ri.push_back(sqrt((a * a) + (b * b)));
	}

	vector<float> Error_stats;

	Error_stats.push_back(vectorMeanFloat(Ri));
	Error_stats.push_back(vectorStandardDevFloat(Ri));
	//Error_stats.push_back(Error_stats[1] / Error_stats[0] * 100);

	return Error_stats;
}

vector<float> Fit::errors(vector<float> XY_calc_center)
{
	vector<int> X_ax_of_contour_tmp = takeThePointColumnFromVector_X();
	vector<int> Y_ax_of_contour_tmp = takeThePointColumnFromVector_Y();

	return errors(XY_calc_center, X_ax_of_contour_tmp, Y_ax_of_contour_tmp);
}

vector<float> Fit::errors()
{
	return errors(solveLinearEqSystem());
}