#include "opencv2/opencv_modules.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/mat.hpp" 
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace cv;

Mat insertion_sort(Mat image, int height, int width)
{
	Mat cop;
	int p;
	Vec3b key;
	Vec3b val;
	VideoWriter video("akoutput.avi",cv::CAP_FFMPEG,cv::VideoWriter::fourcc('H', '2', '6', '4'),50,Size(200, 200),true);

	for(int i = 0; i < height; i++)
	{
		for(int j = 1; j < width; j++) /* needs to start at 1 because arrays begin at 0 */
		{
			key = image.at<Vec3b>(Point(j,i));

			p = j - 1;
			val = image.at<Vec3b>(Point(p,i));

			while(p > -1  && (val[0] > key[0])) /* checks greater than -1 because arrays have 0 index */
			{
				image.at<Vec3b>(Point(p+1, i)) = image.at<Vec3b>(Point(p,i)); 
				p--;
				val = image.at<Vec3b>(Point(p,i));
			}
			image.at<Vec3b>(Point(p+1,i)) = key;
			cop = image.clone();
			cvtColor(cop, cop, cv::COLOR_HSV2BGR);
			video << cop;
		}
	}
	return image;
}

int main(int, char**)
{
	int height = 200;
	int width = 200;
	int randscale = 180;
	//Mat hsv;
	Vec3b color;

	Mat hsv(height, width, CV_8UC3);
	//cvtColor(image1, hsv, cv::COLOR_BGR2HSV);

	/* initialzation */
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			color = hsv.at<Vec3b>(Point(j,i));
			color[0] = (rand() % randscale);
			color[1] = 255;
			color[2] = 255;
			hsv.at<Vec3b>(Point(j,i)) = color;
		}
	}

	hsv = insertion_sort(hsv, height, width);

	namedWindow("Display Window", WINDOW_AUTOSIZE);
	cvtColor(hsv, hsv, cv::COLOR_HSV2BGR);
	imshow("Display Window", hsv);
	waitKey(0);

	//image1.release();
	hsv.release();

	return 0;
}


