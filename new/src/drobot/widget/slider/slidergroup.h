#ifndef SLIDERGROUP_H
#define SLIDERGROUP_H

#include <vector>
#include <string>

#include <QWidget>

#include "slider.h"
#include "../../device/channel/channel.h"

namespace drobot {
namespace widget {
namespace slider {

class SliderGroup : public QWidget
{
    Q_OBJECT

private:
    std::string _title;
    std::vector<Slider*> _sliders;

public:
    SliderGroup(std::string title, std::vector<device::channel::Channel*> channels, std::vector<double> mins, std::vector<double> maxs, std::vector<double> inits);

    double getValue(int index);
    double operator[](int index);

    void setValue(int index, double value);

public slots:
    void save();
    void load();
    void reset();
};

} // namespace slider
} // namespace widget
} // namespace drobot

#endif // SLIDERGROUP_H
