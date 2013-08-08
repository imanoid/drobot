
#include <boost/thread.hpp>

#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <math.h>
#include "DRobotImageDisplay.h"

#include <X11/Xlib.h>



class DataProvider
{

public:

	DataProvider()
	{
		display = new drobot::DRobotImageDisplay();
		display->show();
	}


	void run()
	{

		for (int i=0; i<100; ++i)
		{
			std::string str = "/home/hgmarques/Pictures/Roboy/angela1.JPG";

			if(i % 2 == 0)
				str = "/home/hgmarques/Pictures/Roboy/angela1.JPG";
			else
				str = "/home/hgmarques/Pictures/Roboy/angela2.JPG";

			cv::Mat img = cv::imread(str.c_str());
			display->imshow(img);

			usleep(10000);
		}

	}

public:
	drobot::DRobotImageDisplay* display;
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
