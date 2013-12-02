#ifndef _DROBOT_WIDGET_PLOT_CURVEPLOTTER_H
#define _DROBOT_WIDGET_PLOT_CURVEPLOTTER_H

#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_legend.h>

#include "../../datalogger/datalogger.h"

namespace drobot {
namespace widget {
namespace plot {

class CurvePlotter : public QwtPlot, public datalogger::DataLogger
{
    Q_OBJECT

protected:
    std::vector<QwtPlotCurve*> _curves;
    QVector< double > _x;
    QVector< QVector<double> > _y;
public:
    CurvePlotter(std::string title, int x, int y, int width, int height, std::vector<device::channel::Channel*> channels, std::vector<QColor> colors);
    CurvePlotter(std::string title, int x, int y, int width, int height, std::vector<device::channel::Channel*> channels);
    virtual void log(long tick, std::map<device::channel::Channel*, double> values);
public slots:
    void replot();
signals:
    void updateData();
};

} // namespace plot
} // namespace widget
} // namespace drobot

#endif // _DROBOT_WIDGET_PLOT_CURVEPLOTTER_H
