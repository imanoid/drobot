#include <QHBoxLayout>

#include "slider.h"

namespace drobot {
namespace widget {
namespace slider {

Slider::Slider(double min, double max, double init)
{
    this->setLayout(new QHBoxLayout());
    QLayout* layout = this->layout();

    _text = new QLineEdit(QString::number(init));
    _text->setFixedSize(60, 20);
    _slider = new QSlider(Qt::Horizontal);
    _slider->setMinimum(0);
    _slider->setMaximum(1000);
    _slider->setFixedSize(200, 20);
    _slider->setTickInterval(1000);

    layout->addWidget(_slider);
    layout->addWidget(_text);

    QObject::connect(_slider, SIGNAL(valueChanged(int)),
             this, SLOT(updateSlider()));

    _min = min;
    _max = max;
    _value = init;
    _init = init;
    setValue(init);
}

Slider::Slider(double min, double max) : Slider(min, max, min + ((max - min) / 2.0))
{
}

Slider::~Slider()
{
    delete _text;
    delete _slider;
}

void Slider::setValue(double value)
{
    _value = value;
    _slider->setValue((int) ((value - _min) / (_max - _min) * 1000.0));
    _text->setText(QString::number(value));
}

void Slider::updateSlider()
{
    _value = (double) _slider->value() / 1000.0 * (_max - _min) + _min;
    _text->setText(QString::number(_value));
}

} // namespace slider
} // namespace widget
} // namespace drobot
