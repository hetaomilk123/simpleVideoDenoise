#include "simpFilters.h"

/************************ 全局函数 *************************/
void runFilters(const Mat& img){
	/* 显示原始图像 */
	namedWindow("原始图像", 0);
	imshow("原始图像", img);	

	/* 给图像加高斯噪声(0, 20)，并显示噪声图像 */
	Mat nImg = addGaussNoise(img, 20); 
	namedWindow("噪声图像", 0);
	imshow("噪声图像", nImg);
	
	/* 应用去噪算法 */
	Mat dst;
	fastNlMeansDenoising(nImg, dst);

	/* 显示去噪后的结果图 */
	namedWindow("去噪后的结果图", 0);
	imshow("去噪后的结果图", dst);

	waitKey(0);
}
double computePSNR(const Mat &img1, const Mat &img2){
	cv::Mat img1_gray, img2_gray;
	cv::Mat img1_16s, img2_16s;
	cv::Scalar s;
	double mse, psnr;

	// グレースケールに変換
	cv::cvtColor(img1, img1_gray, CV_BGR2GRAY);
	cv::cvtColor(img2, img2_gray, CV_BGR2GRAY);

	//符号有り16bitに変換
	img1_gray.convertTo(img1_16s, CV_16S);
	img2_gray.convertTo(img2_16s, CV_16S);

	// MSE, PSNR算出
	img1_16s -= img2_16s;
	s = sum(img1_16s.mul(img1_16s));
	mse = s[0]/img1_16s.rows/img1_16s.cols;
	psnr = 10*log10(255*255/mse);

	return psnr;
}
Mat addGaussNoise(const Mat &img, int stddev){
	Mat noisy = img.clone();
	Mat noise(img.size(), img.type());
	randn(noise, 0, stddev);
	noisy += noise;
	return noisy;
}
