/* File: ColorDetection.cpp
*  A CPP program file to detect an object from a continuous
*  video stream by converting rgb to hsv and adjusting hsv value.
*/

#include <iostream>

/* Header file for opencv */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main(int argc, char ** argv) {
	/* capture via webcam, 0 - is for first camera which is webcam */
	cv::VideoCapture cap(0);
	if(!cap.isOpened()) {
		cout << "Error in opening webcam" << endl;
		return -1;
	}

	/* mar object to store video frames */
	cv::Mat rgb_frame;
	cv::Mat hsv_frame;

	cv::namedWindow("RGB Video", WINDOW_AUTOSIZE);
	cv::namedWindow("HSV Video", WINDOW_AUTOSIZE);

	/* continuously capture video frames */
	while (1) {
		cap >> frame;
		cv::cvtColor(rgb_frame, hsv_frame, CV_BGR2HSV);
		cv::imshow("RGB Video", rgb_frame);
		cv::imshow("HSV Video", hsv_frame);
		if(waitKey(33) >= 0) break; // if user press any key exit
	}

	cap.release();

	return 0;
}