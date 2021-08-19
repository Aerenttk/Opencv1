#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <json/json.h>
#include <fstream>
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

int main() {


	//VideoCapture cap(0);
	//Mat img;
	//while (true)
	//{
	//	cap.read(img);
	//	CascadeClassifier faceCascade;
	//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	//	vector<Rect> faces;
	//	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	//	for (int i = 0; i < faces.size(); i++) {
	//		putText(img, "Face", faces[i].tl(), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
	//		;			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 255, 0), 3);
	//	}

	//	imshow("Image", img);
	//	waitKey(1);
	//}

	ifstream json("./Resources/antispoofing_model.json");
	string actualJson = "";
	if (json.is_open())
	{
		while (getline(json, actualJson)) { }
		json.close();
	}
	actualJson.erase(std::remove_if(actualJson.begin(), actualJson.end(), isspace),actualJson.end());

	const std::string rawJson = actualJson;
	const auto rawJsonLength = static_cast<long int>(rawJson.length());
	JSONCPP_STRING err;
	Json::Value root;

	
	Json::CharReaderBuilder builder;
	const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
		&err)) {
		std::cout << "error" << std::endl;
		return 0;
	}
	const std::string name = root.asString();

	std::cout << name << std::endl;
	return 1;
}