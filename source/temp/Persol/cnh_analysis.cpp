#include "include/CV_analysis.hpp"

using namespace std;
using namespace cv;

#pragma region | "class cnh analysis"

#pragma region | "contructors"

cnh_analysis::cnh_analysis(const char* filepath)
{
    analysis_struct_data.cascade.load("D:\\G5\\Repositorys\\GITHUB\\Persol\\thirdparty\\etc\\haarcascades\\haarcascade_frontalface_default.xml");
    string inputName = filepath;
    analysis_struct_data.image = imread(samples::findFileOrKeep(inputName), IMREAD_COLOR);
    if (analysis_struct_data.image.empty())
	{
		cout << "Could not read " << inputName << endl;
	}
	else
	{
		analysis_struct_data.frame = analysis_struct_data.image.clone();
		detect_draw(analysis_struct_data.frame, analysis_struct_data.cascade);
	}
}

cnh_analysis::~cnh_analysis()
{
}

#pragma endregion "contructors"

#pragma region | "functions"

void cnh_analysis::detect_draw(cv::Mat& image, cv::CascadeClassifier& cascade)
{
    double t = 0;

	Mat gray;

	cvtColor(analysis_struct_data.image, gray, COLOR_BGR2GRAY);

	t = (double)getTickCount();
	cascade.detectMultiScale(gray, analysis_struct_data.faces,
		1.1, 2, CASCADE_SCALE_IMAGE,
		Size(30, 30));

	t = (double)getTickCount() - t;
	printf("detection time = %g ms\n", t * 1000 / getTickFrequency());

	for (size_t i = 0; i < analysis_struct_data.faces.size(); i++)
	{
		Rect r = analysis_struct_data.faces[i];
		rectangle(analysis_struct_data.image, Point(cvRound(r.x), cvRound(r.y)),
			Point(cvRound((r.x + r.width - 1)), cvRound((r.y + r.height - 1))),
			colors[i % 8], 1, 8, 0);
	}

	imshow("result", analysis_struct_data.image);
}

bool cnh_analysis::is_valid()
{
	if (!analysis_struct_data.faces.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

#pragma endregion "functions"

#pragma endregion "class cnh analysis"