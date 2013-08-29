
#ifndef _DROBOT_DROBOTTIMEPLOTTER_H_
#define _DROBOT_DROBOTTIMEPLOTTER_H_

#include <string>
#include <vector>
#include <boost/thread.hpp>

#include <QObject>
#include <QApplication>
#include <QVector>
#include <QMainWindow>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

namespace drobot
{

class DRobotTimePlotter : public QObject
{
Q_OBJECT

public:

	DRobotTimePlotter(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels, std::vector<QColor> colors);
	DRobotTimePlotter(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels);

	virtual ~DRobotTimePlotter();

	void
	update(double time, double* values);

	void
	show();

public slots:

	void
	replot();

signals:
	void
	dataUpdated();


private:

	void init(std::string title, int x0, int y0, int width, int height, std::vector<std::string> labels, std::vector<QColor> colors);
	void
	attachPlotter();

protected:

	int width;

	int height;

	std::string title;

	std::vector<QwtPlotCurve*> curves;

	QVector< double > x;
	QVector< QVector<double> > y;

	boost::thread *thread;

	QwtPlot* plotter;


};

}

#endif
