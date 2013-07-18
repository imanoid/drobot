#include <iostream>
#include <fstream>
#include <sstream>
#include <dc1394/dc1394.h>

#include "DRobotVision.h"
#include "capture/DRobotCaptureDevices.h"

namespace drobot {

DRobotVision::DRobotVision()
{
	capture = new DRobotDC1394Device();
	init();
}

DRobotVision::DRobotVision(int idx, int fps)
{
	capture = new DRobotDC1394Device(idx, fps);
	init();
}

DRobotVision::~DRobotVision() {

}

void DRobotVision::init()
{
	lp = new cv::LogPolar_Adjacent(FRAME_WIDTH, FRAME_HEIGHT,
			cv::Point2i(FRAME_WIDTH / 2, FRAME_HEIGHT / 2)); //, 50, 3, 0.25, 1, 70, 0);

	capture->start();

	usleep(200000);
}

cv::Mat DRobotVision::getFrame() {
	frame = capture->getFrame();

	// provide resized and grayscale version of image for further processing
	resize(frame, frameResized, cv::Size(FRAME_WIDTH, FRAME_HEIGHT));
	cv::cvtColor(frameResized, frameGray, CV_BGR2GRAY);

	return frame;
}

void DRobotVision::applySegmentation(cv::Scalar minThresh, cv::Scalar maxThresh)
{
	cv::cvtColor(frameResized, frameHsv, CV_BGR2HSV);

	// H is allowed to wrap around
	if (minThresh[0] > maxThresh[0]) {
		double tmp = minThresh[0];
		minThresh[0] = 0.0;
		inRange(frameHsv, minThresh, maxThresh, frameFiltered);
		minThresh[0] = tmp;
		maxThresh[1] = 180;
		inRange(frameHsv, minThresh, maxThresh, frameTmp);
		bitwise_or(frameFiltered, frameTmp, frameFiltered);
	} else {
		inRange(frameHsv, minThresh, maxThresh, frameFiltered);
	}

	GaussianBlur(frameFiltered, frameFiltered, cv::Size(9, 9), 0.0);

	std::vector<cv::Vec3f> circles;
	HoughCircles(frameFiltered, circles, CV_HOUGH_GRADIENT, 2,
		     frameFiltered.rows / 4, 200, 20, 11, 18);

	// just take the first one
	if (circles.size() > 0) {
		cv::Point center(cvRound(circles[0][0]), cvRound(circles[0][1]));
		int radius = cvRound(circles[0][2]);
//		std::cerr << "  x/y/r: " << center << " " << radius << std::endl;
		lastCenter = center;
		lastRadius = radius;
	}

	// draw the circle center
//	circle(frameResized, lastCenter, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
	// draw the circle outline
	circle(frameResized, lastCenter, lastRadius, cv::Scalar(0, 0, 255), -1, 8, 0);

	frameSegmented = cv::Mat::zeros(frameFiltered.size(), CV_8UC1);
	circle(frameSegmented, lastCenter, lastRadius, cv::Scalar(255, 255, 255), -1, 8, 0);
}

void DRobotVision::applyTransforms()
{
	ppFrameLPCartesian = pFrameLPCartesian;
	ppFrameLPCortical = pFrameLPCortical;
	pFrameLPCartesian = frameLPCartesian;
	pFrameLPCortical = frameLPCortical;

	frameLPCortical = lp->to_cortical(frameGray);
	frameLPCartesian = lp->to_cartesian(frameLPCortical);

	pFrameSegLPCartesian = frameSegLPCartesian;
	pFrameSegLPCortical = frameSegLPCortical;

	frameSegLPCortical = lp->to_cortical(frameSegmented);
	frameSegLPCartesian = lp->to_cartesian(frameSegLPCortical);

	resize(frameLPCartesian, frameLPCartesian,
			cv::Size(FRAME_WIDTH * 2, FRAME_HEIGHT * 2));
	resize(frameSegLPCartesian, frameSegLPCartesian,
			cv::Size(FRAME_WIDTH * 2, FRAME_HEIGHT * 2));

	if (pFrameLPCartesian.size().width != 0) {
		absdiff(frameLPCortical, pFrameLPCortical, tdFrameLPCortical);
		absdiff(frameLPCartesian, pFrameLPCartesian, tdFrameLPCartesian);

		/*
		if (ppFrameLPCartesian.size().width != 0) {
			// 2nd order temporal difference: td2 = f(x) - 2*f(x-1) + f(x-2)
			td2FrameLPCortical = frameLPCortical - pFrameLPCortical;
			td2FrameLPCortical += ppFrameLPCortical;
			absdiff(td2FrameLPCortical, pFrameLPCortical, td2FrameLPCortical);

			td2FrameLPCartesian = frameLPCartesian - pFrameLPCartesian;
			td2FrameLPCartesian += ppFrameLPCartesian;
			absdiff(td2FrameLPCartesian, pFrameLPCartesian, td2FrameLPCartesian);
		}
		*/
	}

	if (pFrameSegLPCartesian.size().width != 0) {
		absdiff(frameSegLPCortical, pFrameSegLPCortical, tdFrameSegLPCortical);
		absdiff(frameSegLPCartesian, pFrameSegLPCartesian, tdFrameSegLPCartesian);
	}
}

double DRobotVision::getTDPixelActivity(cv::Mat tdFrame) {
	if (tdFrame.size().width == 0)
		return 0;

	unsigned char *pixels = (unsigned char *) tdFrame.data;
	int size = tdFrame.cols * tdFrame.rows;

	double activity = 0;

	for (int i = 0; i < size; i++)
		activity += (int) pixels[i];

	return activity;
}

double DRobotVision::getTDPixelActivity() {
	return getTDPixelActivity(tdFrameLPCortical);
}

double DRobotVision::getTD2PixelActivity() {
	return getTDPixelActivity(td2FrameLPCortical);
}

cv::Point DRobotVision::getLastBallCenter()
{
	return lastCenter;
}

}
