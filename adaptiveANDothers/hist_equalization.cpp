#include "hist_equalization.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>


void equalization(cv::Mat& image, cv::Mat& dest) {
cv::Mat hist;
    //std::cout << image.cols * image.rows;
    int histSize = 255;
    float range[] = {0, 256};
    const float* histRange[] = {range};
    bool uniform = true, accumulate = false;
    cv::calcHist(&image, 1, 0, cv::Mat(), hist, 1, &histSize, histRange, uniform, accumulate);
    int max = histSize;
    while (hist.at<float>(max) == 0) {
         --max;
    }
    cv::Mat_<float> temp(1,255);
    long long cc = 1;
    long long pxlcount = image.rows * image.cols;
    for (int i = 0; i < histSize; ++i) {
        temp.at<float>(i) = std::ceil((hist.at<float>(i) + cc) * max / pxlcount);
        cc += hist.at<float>(i);


    }
    //std::cout << temp;

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
                dest.at<uchar>(i, j) = temp.at<float>(image.at<uchar>(i, j));
        }
    }
}
