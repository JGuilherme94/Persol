#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types_c.h>

#include <iostream>
#include <string>

#pragma region | "classes"

class cnh_analysis;

#pragma endregion "classes"

#pragma region | "class cnh analysis"

struct analysis_cnh
{
    cv::CascadeClassifier cascade;
    cv::Mat image;
    cv::Mat frame;
    std::vector<cv::Rect> faces;
};

const static cv::Scalar colors[] =
{
    cv::Scalar(255,0,0),
    cv::Scalar(255,128,0),
    cv::Scalar(255,255,0),
    cv::Scalar(0,255,0),
    cv::Scalar(0,128,255),
    cv::Scalar(0,255,255),
    cv::Scalar(0,0,255),
    cv::Scalar(255,0,255)
};

class cnh_analysis
{
private:
    void detect_draw(cv::Mat& image, cv::CascadeClassifier& cascade);
protected:
    analysis_cnh analysis_struct_data;
public:
    cnh_analysis(const char* filepath);
    ~cnh_analysis();
    bool is_valid();
};

#pragma endregion "class cnh analysis"