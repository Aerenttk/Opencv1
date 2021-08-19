#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


// Basic Funtions in one photo
//void main() {
//
//string path = "Resources/test.png";
//Mat img = imread(path);
//Mat imgGray,imgBlur, imgCanny, imgDil, imgErode;
//cvtColor(img, imgGray, COLOR_BGR2GRAY);
//GaussianBlur(img, imgBlur,Size(7,7),7,0);
//Canny(imgBlur,imgCanny,23,75);

//Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//dilate(imgCanny, imgDil, kernel);
//erode(imgDil, imgErode, kernel);

//imshow("Image", img);
////imshow("Image Gray", imgGray);
////imshow("Image Blur", imgBlur);
//imshow("Canny Image", imgCanny);
//imshow("Image Dialation", imgDil);
//imshow("Image Erode", imgErode);
//	waitKey(0);
//	
//
//}

// Basic Funtions in cam
void main() {
	VideoCapture cap(0);
	Mat img2;
	Mat imgGray2, imgBlur2, imgCanny2, imgDil2, imgErode2;
	while (true)
	{
		cap.read(img2);

		imshow("Image", img2);
		cvtColor(img2, imgGray2, COLOR_BGR2GRAY);
		//imshow("Image Gray", imgGray);
		//GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
		//imshow("Image Blur", imgBlur);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		Canny(img2, imgCanny2, 23, 75);
		imshow("Canny Image", imgCanny2);
		dilate(imgCanny2, imgDil2, kernel);
		imshow("Image Dialation", imgDil2);
		erode(imgDil2, imgErode2, kernel);
		imshow("Image Erode", imgErode2);
		waitKey(1);

	}

}