#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;


// Importing Images
//void main() {
//
//	string path = "Resources/SN850373.JPG";
//	Mat img = imread(path);
//	CascadeClassifier faceCascade;
//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//	vector<Rect> faces;
//	faceCascade.detectMultiScale(img, faces, 1.1, 10);
//	for (int i = 0; i < faces.size(); i++) {
//		putText(img, "Face", faces[i].tl(), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
//		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 255, 0),3);
//	}
//	
//	imshow("Image", img);
//	waitKey(0);
//	
//
//}

//Importing Videos

//void main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true)
//	{
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);
//	}
//
//
//
//}

//Importing Webcam

void main() {


	VideoCapture cap(0);
	Mat img;
	while (true)
	{
		cap.read(img);
		CascadeClassifier faceCascade;
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");

		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++) {
			putText(img, "Face", faces[i].tl(), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
;			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 255, 0),3);
		}

		imshow("Image", img);
		waitKey(1);
	}
}