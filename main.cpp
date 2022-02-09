#include<opencv2\opencv.hpp>
#include<iostream>
#include"hist.h"

using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("1.jpg");
	
	equalhist(img);
	waitKey(0);
	return 0;
}
