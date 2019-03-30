#include<opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("1.JPG");
	imshow("¡¾ÔØÈëµÄÍ¼Æ¬¡¿", img);
	waitKey(6000);
	return 0;
}