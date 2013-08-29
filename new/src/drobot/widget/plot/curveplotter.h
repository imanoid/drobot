#ifndef DROBOT_WIDGET_PLOT_CURVEPLOTTER_H
#define DROBOT_WIDGET_PLOT_CURVEPLOTTER_H

#include <qwt/qwt_plot_curve.h>
#include "../../datalogger/datalogger.h"
#include <qwt/qwt_plot.h>
#include <qwt/qwt_legend.h>

namespace drobot {
namespace widget {
namespace plot {

class CurvePlotter : public QwtPlot, public datalogger::DataLogger {
Q_OBJECT

protected:
    std::vector<QwtPlotCurve*> _curves;
    QVector< double > _x;
    QVector< QVector<double> > _y;
public:
    CurvePlotter(std::string title, int x, int y, int width, int height, std::vector<device::channel::Channel*> channels, std::vector<QColor> colors);
    CurvePlotter(std::string title, int x, int y, int width, int height, std::vector<device::channel::Channel*> channels);
    virtual void log(long tick, std::map<device::channel::Channel*, double> values);
};

} // namespace plot
} // namespace widget
} // namespace drobot

#endif // DROBOT_WIDGET_PLOT_CURVEPLOTTER_H
