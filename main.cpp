#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main()
{
	std::string paths = "./input/*.png";
	std::vector<cv::String> filenames;
	cv::glob(paths, filenmaes, false);
	Mat img;
	for (size_t i = 0, i < filename.size(), i ++)
	{
		img = cv::imread(filename[i]);
	}
	return 0;
}
