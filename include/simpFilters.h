#ifndef SIMP_FILTERS_H
#define SIMP_FILTERS_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdexcept>

#define IS_IMAGE // 用于图像去噪

using namespace cv;
using namespace std;

/************************ 全局函数 *************************/
void runFilters(const Mat& img);
double computePSNR(const Mat &img1, const Mat &img2);
Mat addGaussNoise(const Mat &img, int stddev);

#endif
