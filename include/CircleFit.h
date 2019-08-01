#pragma once

using namespace std;
using namespace cv;

class Fit
{
	private:
		vector<Point> edge_pixels_;
		int number_of_points_;

	public:
		// === Initialization part ===
		Fit(vector<Point> edge_pixels, int number_of_points);
		~Fit();

		// === Points to fit preparation ===
		// Find the indexes of places to divide the pupil edge vector.
		// Because of used int() functions, last value always will be
		// smaller or equal than the number of pupil edge points.
		// Fixing this issiue by uniform distributon of
		// the division of rest to the obtained vector will slow down
		// the program and will not give better results
		vector<Point> pointsToFitTheCircle(vector<Point> edge_pixels, int number_of_points);
		vector<Point> pointsToFitTheCircle(vector<Point> edge_pixels);
		vector<Point> pointsToFitTheCircle();

		// Calculate the pupil central pixels coordinates.
		// Make two x and y vec from one - two column vec with coordinates - from vector of points
		// Twice - almost - the same, because I want to avoid IF statement in every loop iteration.
		// Maybe there is more inteligent way to do that, but nope.
		vector<int> takeThePointColumnFromVector_X(vector<Point> vector_to_divide);
		vector<int> takeThePointColumnFromVector_X();

		vector<int> takeThePointColumnFromVector_Y(vector<Point> vector_to_divide);
		vector<int> takeThePointColumnFromVector_Y();

		// === Maths methods part ===
		// Last part of name say what type vector elements are allowed in it.
		// -- Summing methods
		// Takes vector of int's or float's, and returns int or float.
		float vectorSumInt(vector<int> v);
		float vectorSumFloat(vector<float> v);

		// -- Mean methods
		// Takes vector of int's or float's, but always returns float -> it is average...
		float vectorMeanInt(vector<int> v);
		float vectorMeanFloat(vector<float> v);

		// -- STD methods
		// Calculate Standard deviation of vector of floats
		float vectorStandardDevInt(vector<int> v);
		float vectorStandardDevFloat(vector<float> v);

		// === !! Most important !! ===
		// === Fitting circle part ===
		// obtain the publicaation ...
		vector<float> reducedCoordinates(vector<int> v);

		vector<float> linSysParams(vector<float> u, vector<float> v);
		vector<float> linSysParams();

		// Most important!!
		// Find center 
		vector<float> solveLinearEqSystem(vector<float> LSParameters, vector<int> X_ax_of_contour, vector<int> Y_ax_of_contour);
		vector<float> solveLinearEqSystem(vector<float> LSParameters);
		vector<float> solveLinearEqSystem();

		// Most important!!
		// Find radius with error
		vector<float> errors(vector<float> XY_calc_center, vector<int> X_ax_of_contour, vector<int> Y_ax_of_contour);
		vector<float> errors(vector<float> XY_calc_center);
		vector<float> errors();
};