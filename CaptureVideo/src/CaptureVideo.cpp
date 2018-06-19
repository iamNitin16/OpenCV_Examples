/* File: VideoCapture.cpp
*  A simple cpp program to capture video from webcam ofyour 
*  laptop or desktop using OpenCV Library.
*/

#include <iostream>

/* Header Files for OpenCV libraries */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {
	/* object of VideoCapture Class */
	/* 0 is passed for first camera i.e. webcam in most devices */
	VideoCapture cap(0);

	if(!cap.isOpened()) {
		cout << "Error in opening camera, exiting" << endl;
		return -1;
	}

	Mat frame;

	/* Infinite loop for Continuous Video */
	for (;;) {
		cap >> frame; // get a frame from camera
		imshow("Video", frame);
		if(waitKey(33) >= 0) break;
	}

	cap.release(); // release the camera

	return 0;
}