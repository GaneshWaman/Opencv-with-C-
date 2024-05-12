#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Convert Image to HSV Color Space
// Define the lower and upper bounds for the target color range
// Apply Thresholding to detect the color
// Display the results
// Global variables for trackbar positions

int hmax = 15, smax = 255, vmax = 255;
int hmin = 0, smin = 25, vmin = 169;

void main()
{
    // Declare variables to store HSV image and mask
    Mat carhsv, mask;

    // Read the input image (a Lamborghini car image)
    Mat car = imread("Resources/lambo.jpeg");

    // Convert the input image from BGR to HSV color space
    cvtColor(car, carhsv, COLOR_BGR2HSV);

    // Create a window for trackbars
    namedWindow("Trackbar");

    // Create trackbars for lower and upper HSV thresholds
    createTrackbar("Hue min", "Trackbar", &hmin, 179);
    createTrackbar("Hue max", "Trackbar", &hmax, 179);
    createTrackbar("Sat min", "Trackbar", &smin, 255);
    createTrackbar("Sat max", "Trackbar", &smax, 255);
    createTrackbar("Value min", "Trackbar", &vmin, 255);
    createTrackbar("Value max", "Trackbar", &vmax, 255);

    // while loop runs continuously to dynamically adjust trackbar and reflect changes in mask image
    while (true) {
        // Define the lower and upper bounds for the HSV color range based on trackbar positions
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        // Apply thresholding to create a binary mask containing pixels within the specified HSV range
        inRange(carhsv, lower, upper, mask);

        // Display the original image, the HSV image, and the mask
        imshow("car", car);
        imshow("carhsv", carhsv);
        imshow("Mask", mask);

        // Wait for a key press for 1 millisecond
        waitKey(1);
    }
}
