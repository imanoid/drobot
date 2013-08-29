
#ifndef _DROBOT_DROBOTSLIDERGROUP_H_
#define _DROBOT_DROBOTSLIDERGROUP_H_

#include <QMainWindow>
#include <QFormLayout>

#include <vector>
#include <string>

#include "DRobotSlider.h"

namespace drobot
{

class DRobotSliderGroup : public QWidget
{
    Q_OBJECT


public:

    DRobotSliderGroup(std::string title, std::vector<std::string> labels, double init, double min, double max);

    DRobotSliderGroup(std::string title, std::vector<std::string> labels, std::vector<double> init, std::vector<double> min, std::vector<double> max);

    ~DRobotSliderGroup();

    double
    getValue(int index);

    double
    operator[](int index);

public slots:
    void
    save();

    void
    load();

    void
    reset();

private:
    void createButtonPanel(QFormLayout* layout);

private:

    std::vector<DRobotSlider*> sliders;
    std::string title;

};


}

#endif
