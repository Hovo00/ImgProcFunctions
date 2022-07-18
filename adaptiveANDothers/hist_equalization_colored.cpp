#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>

int main() {

    cv::Mat image = cv::imread("colored.jpeg", cv::IMREAD_COLOR);
    cv::Mat channels[3];
    cv::Mat dest[3];
    cv::split(image, channels);
    cv::equalizeHist(channels[0], dest[0]);
    cv::equalizeHist(channels[1], dest[1]);
    cv::equalizeHist(channels[2], dest[2]);
    std::vector<cv::Mat> temp;
    cv::Mat res;
    temp.push_back(dest[0]);
    temp.push_back(dest[1]);
    temp.push_back(dest[2]);
    cv::merge(temp, res);
    cv::imshow("original", image);
    cv::imshow("test", res);
    cv::waitKey(0);
}
