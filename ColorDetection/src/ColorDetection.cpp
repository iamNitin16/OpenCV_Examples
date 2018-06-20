/* File: ColorDetection.cpp
*  A CPP program file to detect an object from a continuous
*  video stream by converting rgb to hsv and adjusting hsv value.
*/

#include <iostream>

/* Header file for opencv */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;

char * trackbar_window_name = "trackbars";

/* Function: on_trackbar_change
*  Callback function to handle changes in Trackbars.
*
*  Parameters: void
*  Returns: void
*/

void on_trackbar_change (int val, void * event) {

}

/* Function: init_trackbars
*  A function to create different trackbars to easily change
*  value of HSV in a hsv_frame.
*
*  Parameters: void
*  Returns: void
*/
void init_trackbars () {
	namedWindow(trackbar_window_name, WINDOW_AUTOSIZE);
	createTrackbar("H_MIN", trackbar_window_name, &H_MIN, H_MAX, on_trackbar_change);
	createTrackbar("H_MAX", trackbar_window_name, &H_MAX, H_MAX, on_trackbar_change);
	createTrackbar("S_MIN", trackbar_window_name, &S_MIN, S_MAX, on_trackbar_change);
	createTrackbar("S_MAX", trackbar_window_name, &S_MAX, S_MAX, on_trackbar_change);
	createTrackbar("V_MIN", trackbar_window_name, &V_MIN, V_MAX, on_trackbar_change);
	createTrackbar("V_MAX", trackbar_window_name, &V_MAX, V_MAX, on_trackbar_change);
}

int main(int argc, char ** argv) {
	/* capture via webcam, 0 - is for first camera which is webcam */
	VideoCapture cap(0);
	if(!cap.isOpened()) {
		cout << "Error in opening webcam" << endl;
		return -1;
	}

	/* mar object to store video frames */
	Mat rgb_frame;
	Mat hsv_frame;
	vector<Mat> hsv_channels;

	namedWindow("RGB Video", WINDOW_AUTOSIZE);
	namedWindow("HSV Video", WINDOW_AUTOSIZE);
	namedWindow("H Video", WINDOW_AUTOSIZE);
	namedWindow("S Video", WINDOW_AUTOSIZE);
	namedWindow("V Video", WINDOW_AUTOSIZE);

	init_trackbars();

	/* continuously capture video frames */
	while (1) {
		cap >> rgb_frame;
		
		cvtColor(rgb_frame, hsv_frame, CV_BGR2HSV);

		split(hsv_frame, hsv_channels);

		imshow("RGB Video", rgb_frame);
		imshow("HSV Video", hsv_frame);
		imshow("H Video", hsv_channels[0]);
		imshow("S Video", hsv_channels[1]);
		imshow("V Video", hsv_channels[2]);
		if(waitKey(33) >= 0) break; // if user press any key exit
	}

	cap.release();

	return 0;
}