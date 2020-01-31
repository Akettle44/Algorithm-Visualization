#include "opencv2/opencv_modules.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/mat.hpp" 
#include "opencv2/highgui.hpp"

using namespace cv;

int main(int, char**)
{
	int height = 720;
	int width = 720;
	//Mat hsv;
	Vec3b color;

	Mat hsv(height, width, CV_8UC3);
	//cvtColor(image1, hsv, cv::COLOR_BGR2HSV);

	/* initialzation */
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < height; j++)
		{
			color = hsv.at<Vec3b>(Point(i,j));
			color[0] = i / 4;
			color[1] = 255;
			color[2] = 255;
			hsv.at<Vec3b>(Point(i,j)) = color;
		}
	}

	namedWindow("Display Window", WINDOW_AUTOSIZE);
	cvtColor(hsv, hsv, cv::COLOR_HSV2BGR);
	imshow("Display Window", hsv);
	waitKey(0);

	//image1.release();
	hsv.release();

	return 0;
} 