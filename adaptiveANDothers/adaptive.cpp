#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

int main() {
	cv::Mat img = cv::imread("Images.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat image = img.clone();
	const int N = 21;
	int i = 0;
	int j = 0;
        while (i < image.rows - N) {
	    while(j < image.cols - N){
		int thresh = 0;
		int sum = 0;
		for (int ii = i; ii < i + N; ++ii) {
			for (int jj = j; jj < j + N; ++jj) {
				sum += image.at<uchar>(ii, jj);	
			}
		}
		thresh = sum / (N * N);
		for (int ii = i; ii < i + N; ++ii) {
                        for (int jj = j; jj < j + N; ++jj) {
                                image.at<uchar>(ii, jj) = image.at<uchar>(ii, jj) > thresh ? 255 : 0;
                        }
                }
		j += N;
	    }
		i += N;
		j = 0;
	}
	cv::Mat dest;
	cv::adaptiveThreshold(img, dest, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 0);
	cv::imshow("myadaptive", image);
	cv::imshow("original", img);
	cv::imshow("opencv", dest);
	cv::waitKey(0);	
}
