#include "image_processing.h"

namespace rbtxcm
{
    void ImageProcessing::_update_image()
    {
        *mCamera >> *mImage;
    }

    ImageProcessing::ImageProcessing(int iCameraNum)
    {
        mCamera = new cv::VideoCapture(iCameraNum);
        mImage = new cv::Mat;
        mLineSegmentDetector = cv::createLineSegmentDetector(cv::LSD_REFINE_STD);
        mFastLineDetector = cv::ximgproc::createFastLineDetector();
    }

    ImageProcessing::~ImageProcessing()
    {
        delete mCamera;
        delete mImage;
        mLineSegmentDetector.release();
        mFastLineDetector.release();
    }

    cv::Mat ImageProcessing::getImage()
    {
        return *mImage;
    }

    std::vector<cv::Vec3f> ImageProcessing::getCircles(int iDistance, int iGradient1, int iGradient2, int iMinRadius, int iMaxRadius)
    {
        _update_image();
        std::vector<cv::Vec3f> wCircles;
        cv::Mat wImage;
        cv::cvtColor(*mImage, wImage, cv::COLOR_BGR2GRAY);
        cv::medianBlur(wImage, wImage, 5);
        cv::HoughCircles(wImage, wCircles, cv::HOUGH_GRADIENT, 1, 
                         wImage.rows/iDistance,
                         iGradient1, iGradient2,
                         iMinRadius, iMaxRadius        
        );
        return wCircles;
    }

    std::vector<cv::Vec4f> ImageProcessing::getLines(int iThreshold1, int iThreshold2)
    {
        _update_image();
        std::vector<cv::Vec4f> wLines;
        cv::Mat wImage;
        cv::Canny(*mImage, wImage, iThreshold1, iThreshold2, 3);
        mLineSegmentDetector->detect(wImage, wLines);
        return wLines;
    }

    void ImageProcessing::setFastLineDetector(int iLenghtThreshold, int iDistanceThreshold, int iCannyThreshold1, int iCannyThreshold2, int iCannyApertureSize, bool iDoMerge)
    {
        mFastLineDetector = cv::ximgproc::createFastLineDetector(iLenghtThreshold, iDistanceThreshold, iCannyThreshold1, iCannyThreshold2, iCannyApertureSize, iDoMerge);
    }

    std::vector<cv::Vec4f> ImageProcessing::getFastLines()
    {
        _update_image();
        cv::Mat wImage;
        std::vector<cv::Vec4f> wLines;
        cv::cvtColor(*mImage, wImage, cv::COLOR_BGR2GRAY);
        mFastLineDetector->detect(wImage, wLines);
        return wLines;
    }

}