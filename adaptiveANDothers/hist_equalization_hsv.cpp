#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>

int main() {
    cv::Mat image = cv::imread("colored.jpeg", cv::IMREAD_COLOR);
    cv::imshow("original", image);
    cv::Mat HSVimage;
    cv::cvtColor(image, HSVimage, cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> HSVchannels;
    cv::split(HSVimage, HSVchannels);
    cv::equalizeHist(HSVchannels[2], HSVchannels[2]);
    cv::Mat result;
    cv::merge(HSVchannels, result);
    cv::cvtColor(result, result, cv::COLOR_HSV2BGR);
    cv::imshow("result", result);
    cv::waitKey(0);
}
