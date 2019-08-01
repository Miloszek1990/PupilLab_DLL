#pragma once

// Own parts

using namespace std;
using namespace cv;

/*
STRUCTURE OF RETURNING STRING
-> Returning methods and methodologies works like cascade. If even only one value fails, then default value will be returned
-> IMPORTANT: Update this description and methods if you want to add more features!
-> GENERAL:   "1st;2nd;3rd;4th;5th;...;Nth"

1st   = Pupil center X coordinate              [px] IMPORTANT: it should be always 1st
2nd   = Pupil center Y coordinate              [px] IMPORTANT: it should be always 2nd
3rd   = Pupil radius R                         [px] IMPORTANT: it should be always 3rd
4th   = Pupil radius standard deviation StdR   [px] IMPORTANT: it should be always 4th
5th   = ...
...   = ...
N-1th = Error status                          [0/1] IMPORTANT: it should be always pre-last
Nth   = Error reason                            0 - Not defined reason...
                                                1 - Everything is ok!
												2 - No closed contours found...
												3 - other unidentified error... :(
*/

class ROTK
{
	private:
		int reason_;

	public:
		// === Initialization part ===
		// status = true  (1)  -> it is okay - return obtained values
		// status = false (0)  -> error - return default value
		ROTK(int reason);
		~ROTK();

		// === Return default if error was detected ===
		string returnDefault(int tmp_X, int tmp_Y, int tmp_R, int tmp_S, int reason);
		string returnDefault(int tmp_X, int tmp_Y, int tmp_R, int tmp_S);

		// === Return true values ===
		// Values which was calculated by the program
		string returnCalculated(int X, int Y, int R, int S);

		// === Change string to char table ===
};