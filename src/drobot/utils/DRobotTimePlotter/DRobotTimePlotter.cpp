
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>

#include "DRobotTimePlotter.h"


namespace drobot
{

DRobotTimePlotter::DRobotTimePlotter(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels)
{
	this->title = title;
	this->width = width;
	this->height = height;

	for(int i=0; i<labels.size(); i++)
	{
		QwtPlotCurve *curve = new QwtPlotCurve(labels[i].c_str());
		curves.push_back(curve);

		QVector<double> vector;
		y.push_back(vector);
	}

	 QObject::connect(this, SIGNAL(dataUpdated()),
	                      this, SLOT(replot()));


}

DRobotTimePlotter::~DRobotTimePlotter()
{

}


void
DRobotTimePlotter::update(double time, double* values)
{
	x.push_back(time);

	for(int i=0; i<curves.size(); i++)
		y[i].push_back(values[i]);

	emit dataUpdated();

}

void
DRobotTimePlotter::replot()
{

	for(int i=0; i<curves.size(); i++)
		curves[i]->setSamples(x, y[i]);

	plotter->replot();
}



void
DRobotTimePlotter::show()
{

	plotter = new QwtPlot(QwtText(title.c_str()));
	plotter->setMinimumSize(width, height);
	plotter->setGeometry(20, 20, width, height);
	plotter->setAutoReplot(false);
	attachPlotter();
	plotter->show();


}


void
DRobotTimePlotter::attachPlotter()
{
	for(int i=0; i<curves.size(); i++)
		curves[i]->attach(plotter);

}




}
