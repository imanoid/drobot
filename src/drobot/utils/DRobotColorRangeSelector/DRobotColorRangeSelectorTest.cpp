
#include <boost/thread.hpp>

#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <math.h>
#include "DRobotColorRangeSelector.h"

#include <X11/Xlib.h>



class DataProvider
{

public:

	DataProvider()
	{
		selector = new drobot::DRobotColorRangeSelector();
		selector->show();
	}


	void run()
	{
		int* colorBounds;

		while(true)
		{
			colorBounds = selector->getColorBounds();

			std::cerr << colorBounds[0] << "," <<
					colorBounds[1] << ", " << colorBounds[2] << " - " <<
					colorBounds[3] << ", " << colorBounds[4] << ", " << colorBounds[5] << std::endl;

			usleep(100000);
		}
	}

public:
	drobot::DRobotColorRangeSelector* selector;
};



int main(int argc, char *argv[])
{
    //XInitThreads();

	QApplication application(argc, argv);

	printf("PID of main: %d\n", getpid());
	  printf("The ID main thread is: %u\n", (unsigned int)pthread_self());


	 //drobot::DRobotImageDisplay display;
	 //display.show();

//	 cv::Mat img = cv::imread("/home/hgmarques/Pictures/Roboy/angela1.JPG");
//	 display.display(img);

	//	 QObject::connect(&display, SIGNAL(closed()),
	//                     &application, SLOT(quit()) );

	 DataProvider* p = new DataProvider();
	 boost::thread* t = new boost::thread( boost::bind(&DataProvider::run, p) );


	return application.exec();

}
