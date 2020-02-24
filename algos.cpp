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
/*
Mat merge(Mat image, int l, int m, int r)
{
	int n1 = m - l + 1; // left array length, includes n 
	int n2 = r - m;		// right array length 
	int i, j, k; //left side, right side, new index
	
	unsigned long  L[n1]; //initializing arrays with their respective lengths
	unsigned long  R[n2]; 

	//populating the arrays
	for(i = 0; i < n1; i++)
	{
		L[i] = A[l + i]; 
	}
	for(j = 0; j < n2; j++)
	{
		R[j] = A[m + 1 + j]; 
	}

	i = j = 0; //all indexes begin at 0
	k = l;

	// repopulates the array 
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	//fills the rest of the array 
	while(i < n1)
	{
		A[k] = L[i];
		i++; 
		k++;
	}

	while(j < n2)
	{
		A[k] = R[j];
		j++; 
		k++;
	}

}

Mat mergeSort(Mat image, int l, int r)
{
	Mat cop;
	int m;

	if(r > l)
	{
		m = l+(r-l)/2; 		  
		mergeSort(image, l, m);   // handles lef side of split 
		mergeSort(image, m+1, r); // handles right side of split 

		cop = merge(image, l, m, r); 	  // called after mergesort breaks each time 
	}
	return cop;
}

*/
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

	/*insertion sort test */
	hsv = insertion_sort(hsv, height, width);

	for(int i = 0; i < height; i++)
	{
		mergesort(hsv, 0, hsv.row(0));
	}

	namedWindow("Display Window", WINDOW_AUTOSIZE);
	cvtColor(hsv, hsv, cv::COLOR_HSV2BGR);
	imshow("Display Window", hsv);
	waitKey(0);

	//image1.release();
	hsv.release();

	return 0;
}


