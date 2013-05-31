#include <iostream>
#include <fstream>
#include <sstream>
#include <dc1394/dc1394.h>

#include "DRobotVision.h"
#include "capture/DRobotCaptureDevices.h"

namespace drobot {

DRobotVision::DRobotVision() {

	capture = new DRobotDC1394Device();

	lp = new cv::LogPolar_Adjacent(FRAME_WIDTH, FRAME_HEIGHT,
			cv::Point2i(FRAME_WIDTH / 2, FRAME_HEIGHT / 2)); //, 50, 3, 0.25, 1, 70, 0);

	capture->start();

	std::cerr << "Capturing from constructor" << std::endl;
	usleep(200000);

}

DRobotVision::~DRobotVision() {

}

cv::Mat DRobotVision::getFrame() {
	frame = capture->getFrame();

	return frame;
}

void DRobotVision::applyTransforms() {
	pFrameLPCartesian = frameLPCartesian;
	pFrameLPCortical = frameLPCortical;

	resize(frame, frameResized, cv::Size(FRAME_WIDTH, FRAME_HEIGHT));

	cv::cvtColor(frameResized, frameGray, CV_BGR2GRAY);

	frameLPCortical = lp->to_cortical(frameGray);
	frameLPCartesian = lp->to_cartesian(frameLPCortical);

	resize(frameLPCartesian, frameLPCartesian,
			cv::Size(FRAME_WIDTH * 2, FRAME_HEIGHT * 2));

	if (pFrameLPCartesian.size().width != 0) {
		absdiff(pFrameLPCortical, frameLPCortical, tdFrameLPCortical);
		absdiff(pFrameLPCartesian, frameLPCartesian, tdFrameLPCartesian);
	}
}

double DRobotVision::getTDPixelActivity() {
	if (tdFrameLPCartesian.size().width == 0)
		return 0;

	unsigned char*pixels = (unsigned char*) tdFrameLPCortical.data;

	int size = tdFrameLPCortical.cols * tdFrameLPCortical.rows;

	double activity = 0;

	for (int i = 0; i < size; i++)
		activity += (int) pixels[i];

	return activity;

}

}
