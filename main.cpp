#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <sys/stat.h>

int main()
{
	mkdir("./output", 0777); 
	
	std::string paths = "./input/*.png";
	std::vector<cv::String> filenames;

	std::string path;
	size_t num = 0;
	std::string outpath;

	cv::glob(paths, filenames, false);
	cv::Mat img;
	cv::Mat gray, binary;
	std::vector<std::vector<cv::Point>> lunkuo;
	std::vector<cv::Point> lun;
	std::vector<cv::Vec4i> xi;
	for (size_t i = 0; i < filenames.size(); i ++)
	{
		outpath = "./output/";
		path = filenames[i];
		img = cv::imread(path);
		cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
		cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY);
		cv::findContours(binary, lunkuo, xi, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		for (size_t j = 0; j < lunkuo.size(); j ++)
		{
			if (cv::contourArea(lunkuo[j]) < 100)
			{
				continue;
			}
			double c = cv::arcLength(lunkuo[i], true);
			cv::approxPolyDP(lunkuo[i], lun, 0.02 * c, true);
			if (lun.size() == 4)
			{
				cv::drawContours(img, lunkuo, (int)j, cv::Scalar(0, 255, 0), 2);
			}
		}
		num = path.find_last_of("/\\");
		outpath += path.substr(num + 1);
		cv::imwrite(outpath, img);
	}
	return 0;
}
