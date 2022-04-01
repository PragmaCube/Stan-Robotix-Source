// #include <opencv2/imgproc.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>
// #include <opencv2/ximgproc.hpp>
// #include <vector>

// namespace rbtxcm
// {
//     class ImageProcessing
//     {
//         private:
//             cv::VideoCapture* mCamera;
//             cv::Mat* mImage;
//             cv::Ptr<cv::LineSegmentDetector> mLineSegmentDetector;
//             cv::Ptr<cv::ximgproc::FastLineDetector> mFastLineDetector;
//             void _update_image();

//         public:
//             ImageProcessing(int iCameraNum);
//             ~ImageProcessing();
//             cv::Mat getImage();
//             void setFastLineDetector(int iLenghtThreshold, int iDistanceThreshold, int iCannyThreshold1, int iCannyThreshold2, int iCannyApertureSize, bool iDoMerge);
//             std::vector<cv::Vec4f> getFastLines();
//             std::vector<cv::Vec4f> getLines(int iThreshold1, int iThreshold2);
//             std::vector<cv::Vec3f> getCircles(int iDistance, int iGradient1, int iGradient2, int iMinRadius, int iMaxRadius);

//     };
// }