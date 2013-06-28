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
	ppFrameLPCartesian = pFrameLPCartesian;
	ppFrameLPCortical = pFrameLPCortical;
	pFrameLPCartesian = frameLPCartesian;
	pFrameLPCortical = frameLPCortical;

	resize(frame, frameResized, cv::Size(FRAME_WIDTH, FRAME_HEIGHT));

	cv::cvtColor(frameResized, frameGray, CV_BGR2GRAY);

	frameLPCortical = lp->to_cortical(frameGray);
	frameLPCartesian = lp->to_cartesian(frameLPCortical);

	resize(frameLPCartesian, frameLPCartesian,
			cv::Size(FRAME_WIDTH * 2, FRAME_HEIGHT * 2));

	if (pFrameLPCartesian.size().width != 0) {
		absdiff(frameLPCortical, pFrameLPCortical, tdFrameLPCortical);
		absdiff(frameLPCartesian, pFrameLPCartesian, tdFrameLPCartesian);

		if (ppFrameLPCartesian.size().width != 0) {
			// 2nd order temporal difference: td2 = f(x) - 2*f(x-1) + f(x-2)
			td2FrameLPCortical = frameLPCortical - pFrameLPCortical;
			td2FrameLPCortical += ppFrameLPCortical;
			absdiff(td2FrameLPCortical, pFrameLPCortical, td2FrameLPCortical);

			td2FrameLPCartesian = frameLPCartesian - pFrameLPCartesian;
			td2FrameLPCartesian += ppFrameLPCartesian;
			absdiff(td2FrameLPCartesian, pFrameLPCartesian, td2FrameLPCartesian);
		}
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

}
