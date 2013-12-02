#include "curveplotter.h"
#include <iostream>

namespace drobot {
namespace widget {
namespace plot {

CurvePlotter::CurvePlotter(std::string title, int x, int y, int width, int height, std::vector<device::channel::Channel*> channels, std::vector<QColor> colors) : DataLogger(channels), QwtPlot(QwtText(title.c_str())) {
    std::vector<std::string> labels;
    for (std::vector<device::channel::Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        if (*iChannel)
            labels.push_back((*iChannel)->getName());
    }

    for(unsigned int i=0; i<labels.size(); i++) {
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
        _curves.push_back(curve);

        QVector<double> vector;
        _y.push_back(vector);
    }

    QwtPlot::insertLegend(new QwtLegend(this), QwtPlot::BottomLegend);
    for(int i=0; i < _curves.size(); i++)
        _curves[i]->attach(this);
    QwtPlot::setGeometry(x, y, width, height);
    QObject::connect(this, SIGNAL(updateData()), this, SLOT(replot()));
}

CurvePlotter::CurvePlotter(std::string title, int x, int y, int width, int height, std::vector<device::channel::Channel*> channels) : CurvePlotter(title, x, y, width, height, channels, std::vector<QColor>()) {
}

void CurvePlotter::log(long tick, std::map<device::channel::Channel*, double> values) {
    if (getModulo() > 0 && tick % getModulo() != 0)
        return;

    _x.push_back(tick);
    for(int iChannel = 0; iChannel < _channels.size(); iChannel++) {
        device::channel::Channel* channel = _channels[iChannel];
        _y[iChannel].push_back(values[channel]);
    }

    if (_x.size() > getMaxValues() && getMaxValues() > 0) {
        _x.remove(0);
        for (int iY = 0; iY < _y.size(); iY++) {
            _y[iY].remove(0);
        }
    }
    emit updateData();
}

void CurvePlotter::replot() {
    for(int i=0; i < _curves.size(); i++) {
        _curves[i]->setSamples(_x, _y[i]);
    }
    QwtPlot::replot();
}

} // namespace plot
} // namespace widget
} // namespace drobot
