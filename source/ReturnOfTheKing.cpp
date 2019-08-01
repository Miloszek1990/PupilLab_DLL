// Native
#include <vector>
#include <iostream>
#include <string>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

// Own parts
#include "../include/ReturnOfTheKing.h"

// === Initialization part ===
ROTK::ROTK(int reason) : 
	reason_(reason) 
{
}

ROTK::~ROTK() 
{
}

string ROTK::returnDefault(int tmp_X, int tmp_Y, int tmp_R, int tmp_S, int reason)
{
	return to_string(tmp_X) + ";" + to_string(tmp_Y) + ";" + to_string(tmp_R) + ";" + to_string(tmp_S) + ";" + to_string(0) + ";" + to_string(reason);

}

string ROTK::returnDefault(int tmp_X, int tmp_Y, int tmp_R, int tmp_S)
{
	return to_string(tmp_X) + ";" + to_string(tmp_Y) + ";" + to_string(tmp_R) + ";" + to_string(tmp_S) + ";" + to_string(0) + ";" + to_string(reason_);

}

string ROTK::returnCalculated(int X, int Y, int R, int S)
{
	return to_string(X) + ";" + to_string(Y) + ";" + to_string(R) + ";" + to_string(S) + ";" + to_string(1) + ";" + to_string(reason_);
}