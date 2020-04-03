#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\Files\\lena.jpg");//读取图像
	if (srcMat.empty())//检测是否读取成功
	{
		return -1;
	}
	//旋转-40℃，缩放尺度为
	float angle = -10.0, scale = 1;
	//旋转中心为图像中心
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	//获得变换矩阵
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());//对图像进行旋转处理
	cv::imshow("src", srcMat);//显示原图像
	cv::imshow("dst", dstMat);//显示旋转后图像
	waitKey(0);
}