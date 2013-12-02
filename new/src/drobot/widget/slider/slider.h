#ifndef _DROBOT_WIDGET_SLIDER_SLIDER_H
#define _DROBOT_WIDGET_SLIDER_SLIDER_H

#include <QWidget>
#include <QLineEdit>
#include <QSlider>

namespace drobot {
namespace widget {
namespace slider {

class Slider : public QWidget
{
    Q_OBJECT

public:
    Slider(double init, double min, double max);
    Slider(double min, double max);
    ~Slider();
    
    double getValue()   { return _value; }
    double getInit()	{ return _init; }
    double getMinimum() { return _min; }
    double getMaximum() { return _max; }

    void setValue(double value);
    void updateSlider();
private:
    double _min, _max, _init, _value;
    QLineEdit *_text;
    QSlider *_slider;
};

} // namespace slider
} // namespace widget
} // namespace drobot

#endif // _DROBOT_WIDGET_SLIDER_SLIDER_H
