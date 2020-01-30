#include "opencv2/opencv_modules.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/mat.hpp" 
#include "opencv2/highgui.hpp"

using namespace cv;

int main(int, char**)
{
	int height = 1080;
	int width = 1920;
	Vec3b color0, color1, color2, color3;

	Mat image1(height, width, CV_8UC3, Scalar(100, 100, 100));

	/* initialzation */
	for(int i = 0; i < (height / 10); i++)
	{
		for(int j = 0; j < (width / 10); j++)
		{
			color0 = image1.at<Vec3b>(Point(i,j));
			color1 = image1.at<Vec3b>(Point(i + 100,j + 100));
			color2 = image1.at<Vec3b>(Point(i + 200,j + 200));
			color3 = image1.at<Vec3b>(Point(i + 300,j + 300));

			color0[0] = 50;
			color0[1] = 50;
			color0[2] = 50;

			color1[0] = 120;
			color1[1] = 120;
			color1[2] = 120;

			color2[0] = 180;
			color2[1] = 180;
			color2[2] = 180;

			color3[0] = 120;
			color3[1] = 220;
			color3[2] = 220;

			image1.at<Vec3b>(Point(i,j)) = color0;
			image1.at<Vec3b>(Point(i + 100,j + 100)) = color1;
			image1.at<Vec3b>(Point(i + 200,j + 200)) = color2;
			image1.at<Vec3b>(Point(i + 300,j + 300)) = color3;
		}
	}

	namedWindow("Display Window", WINDOW_AUTOSIZE);
	imshow("Display Window", image1);
	waitKey(0);

	image1.release();

	return 0;
} 