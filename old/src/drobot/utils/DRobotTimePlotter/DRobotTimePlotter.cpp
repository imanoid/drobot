
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>

#include "DRobotTimePlotter.h"


namespace drobot
{

DRobotTimePlotter::DRobotTimePlotter(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels, std::vector<QColor> colors)
{
	init(title, x0, y0, width, height, labels, colors);
}

DRobotTimePlotter::DRobotTimePlotter(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels)
{
	std::vector<QColor> colors;
	init(title, x0, y0, width, height, labels, colors);
}

DRobotTimePlotter::~DRobotTimePlotter()
{
}

void DRobotTimePlotter::init(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels, std::vector<QColor> colors)
{
	this->title = title;
	this->width = width;
	this->height = height;

	for(int i=0; i<labels.size(); i++)
	{
		QwtPlotCurve *curve = new QwtPlotCurve(labels[i].c_str());
		QColor color;

		if (i < colors.size())
			color = colors[i];
		else {
			int r = ((double) rand() / RAND_MAX) * 255;
			int g = ((double) rand() / RAND_MAX) * 255;
			int b = ((double) rand() / RAND_MAX) * 255;
			color.setRgb(r, g, b, 127);
		}

		QPen pen(color);
		pen.setWidth(1);
		curve->setPen(pen);
		curves.push_back(curve);

		QVector<double> vector;
		y.push_back(vector);
	}

	 QObject::connect(this, SIGNAL(dataUpdated()),
	                      this, SLOT(replot()));
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
	plotter->setWindowTitle(title.c_str());

	QwtLegend *legend = new QwtLegend(plotter);
	plotter->insertLegend(legend, QwtPlot::BottomLegend);
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
