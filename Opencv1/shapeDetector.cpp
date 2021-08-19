#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void GetContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE );
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objectType;
	for (int i = 0; i < contours.size(); i++)
	{
		//Declering Area of the Object
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area>1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02*peri,true);


			//Drawing Contours :)
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			cout << conPoly[i].size() << endl;

			// Finding Edges
			int objCor = (int)conPoly[i].size();

			//Declaring Objects For Egde Count
			if (objCor == 3) { objectType = "Triangle"; }
			else if (objCor == 4) { objectType = "Rectangle"; }
			else if (objCor == 8) { objectType = "Circle"; }
			else { objectType = "Amorf"; }

			//Görsellik :D
			boundRect[i] = boundingRect(conPoly[i]);
			putText(img, objectType, boundRect[i].tl(), FONT_HERSHEY_DUPLEX, 0.50, Scalar(0, 69, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 0), 2);
		}
	}
}

// Importing Images
void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil;

	//Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur,Size(3,3),3,0);
	Canny(imgBlur,imgCanny,23,75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	GetContours(imgDil,img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilade", imgDil);*/
	waitKey(0);
	

}

//void main() {
//
//
//	VideoCapture cap(0);
//	Mat img;
//	Mat imgGray, imgBlur, imgCanny, imgDil;
//	
//	while (true)
//	{
//		cap.read(img);
//		cvtColor(img, imgGray, COLOR_BGR2GRAY);
//		GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
//		Canny(imgBlur, imgCanny, 23, 75);
//		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//		dilate(imgCanny, imgDil, kernel);
//		GetContours(imgDil, img);
//		imshow("Image", img);
//		waitKey(1);
//	}
//
//
//
//}