#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	//Mat img = imread("D:/Ganesh/Machine Learning/Image_processing/img.JPG");

	Mat img;
	Mat img1 = imread("Resources/nikola.jpg");
	Mat cropped = img1(Rect(1000, 100, 4000, 3900));
	resize(cropped, img, Size(), 0.1, 0.1);

	Mat grayimg, imgblur, cannyimg, dilimg, erodeimg;
	// Converting img into grayscale
	cvtColor(img, grayimg, COLOR_BGR2GRAY);
	// kernal size, kernal std deviation in horizontal dir, kernal std deviation in vertical dir
	GaussianBlur(img, imgblur, Size(5, 5), 5,0); 
	// detecting Edge using Canny edge detector.
	// giving it Blur image is the Best practice.
	Canny(imgblur, cannyimg, 50,150);
	// Size of kernal always be positive and odd number (1,1)/(3,3)/(5,5) etc.
	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
	//Dilation: Increases the size of bright regions or objects in an image. 
	// It works by adding pixels to the boundaries of objects.
	dilate(cannyimg, dilimg, kernal);
	// Erosion: Reduces the size of bright regions or objects in an image. 
	// It works by removing pixels from the boundaries of objects.
	erode(cannyimg, erodeimg, kernal);

	imshow("Gray Image", grayimg);
	imshow("image", img);
	imshow("GaussianBlur image", imgblur);
	imshow("edge detection image", cannyimg);
	imshow("Dilated image", dilimg);
	imshow("Eroded image", erodeimg);

	waitKey(0);
}