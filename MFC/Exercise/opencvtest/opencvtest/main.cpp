#include<opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("1.JPG");
	imshow("�������ͼƬ��", img);
	waitKey(6000);
	return 0;
}