#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
int main()
{
	cv::VideoCapture video("face-demographics-walking-and-pause.mp4");
	cv::CascadeClassifier faceDetector("haarcascade_frontalface_alt.xml");
	while (true) {
		cv::Mat img = cv::imread("lena.png");
		if (!video.read(img)) break;
		std::vector<cv::Rect> faces;
		faceDetector.detectMultiScale(img, faces);
		for (const cv::Rect face : faces) {
			cv::rectangle(img, face, cv::Scalar(0, 0, 255), 2);
			std::cout << face.x << ", " << face.y << std::endl;
		}
		cv::imshow("Image", img);
		cv::waitKey(10);
	}
}