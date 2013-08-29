
#include <boost/thread.hpp>

#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <math.h>
#include "DRobotSliderGroup.h"

#include <X11/Xlib.h>



class DataProvider
{

public:

	DataProvider()
	{
		std::vector<std::string> labels;
		labels.push_back("slider 1");
		labels.push_back("slider 2");

		selector = new drobot::DRobotSliderGroup("TestWindow", labels, 5, 0, 100);
		selector->show();
	}


	void run()
	{

		while(true)
		{
			usleep(100000);
		}
	}

public:
	drobot::DRobotSliderGroup* selector;
};



int main(int argc, char *argv[])
{
    //XInitThreads();

	QApplication application(argc, argv);

	 DataProvider* p = new DataProvider();
	 boost::thread* t = new boost::thread( boost::bind(&DataProvider::run, p) );


	return application.exec();

}
