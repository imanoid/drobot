
#include <boost/thread.hpp>

#include <QApplication>
#include <QDialog>
#include <QWidget>
#include <math.h>
#include "DRobotTimePlotter.h"


class DataProvider
{

public:

	DataProvider()
	{
		std::vector<std::string> labels;
		labels.push_back("plot1");

		plotter = new drobot::DRobotTimePlotter("test", 20, 20, 500, 300, labels);
		plotter->show();
	}


	void run()
	{
		double x;

		double y[1];

		for (int i=0; i<100; ++i)
		{
			x = i/50.0 - 1;
			y[0] = x*x;

			plotter->update(x, y);

			usleep(100000);
		}

	}

public:
	drobot::DRobotTimePlotter* plotter;
};


int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	DataProvider* p = new DataProvider();
	boost::thread* t = new boost::thread( boost::bind(&DataProvider::run, p) );

	DataProvider* p2 = new DataProvider();
	boost::thread* t2 = new boost::thread( boost::bind(&DataProvider::run, p2) );


	return application.exec();

}
