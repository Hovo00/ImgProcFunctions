#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "hist_equalization.h"


int main() {

    cv::Mat image = cv::imread("histequal.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat dest = image.clone();
    equalization(image, dest);
    cv::imshow("original", image);
    cv::imshow("equaled", dest);
    cv::waitKey(0);

}

