
#include<opencv2\opencv.hpp>
#include<iostream>
#include"hist.h"

using namespace cv;
using namespace std;

void equalhist(Mat img)//画灰度直方图
{
	imshow("原始图像", img);
	int channel_num = img.channels();
	Mat img2;
	if (channel_num == 3)//图像灰度化
	{

		cvtColor(img, img2, COLOR_RGB2GRAY);
	}
	else
	{
		img2 = img;
	}
	imshow("灰度图像", img2);
	Mat hist;//存放计算结果
	const int channels[1] = { 0 };
	float inRanges[2] = { 0,255 };
	const float* range[1] = { inRanges };
	const int bins[1] = { 256 };

	calcHist(&img2, 1, channels, Mat(), hist, 1, bins, range);
	int hist_w = 512;
	int hist_h = 400;
	int width = 2;
	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
	for (int i = 1; i <= hist.rows; i++)
	{
		rectangle(histImage, Point(width * (i - 1), hist_h - 1),
			Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
			Scalar(255, 255, 255), -1);
	}
	imshow("灰度直方图", histImage);


	//灰度均衡化
	Mat img3;
	equalizeHist(img2, img3);  //将图像直方图均衡化
	imshow("灰度均衡化图像", img3);
	calcHist(&img3, 1, channels, Mat(), hist, 1, bins, range);
	
	Mat histImage2 = Mat::zeros(hist_h, hist_w, CV_8UC3);
	for (int i = 1; i <= hist.rows; i++)
	{
		rectangle(histImage2, Point(width * (i - 1), hist_h - 1),
			Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
			Scalar(255, 255, 255), -1);
	}
	imshow("灰度均衡化直方图", histImage2);



}

