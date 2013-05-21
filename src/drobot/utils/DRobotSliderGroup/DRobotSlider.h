
#ifndef _DROBOT_DROBOTSLIDER_H_
#define _DROBOT_DROBOTSLIDER_H_

#include <QSlider>
#include <QLineEdit>


namespace drobot
{

class DRobotSlider : public QWidget
{
    Q_OBJECT


public:

    DRobotSlider(std::string label, double init, double min, double max);

    ~DRobotSlider();

    double
    getValue();

    double
    getInitValue();

    double
    getMinimumValue();

    double
    getMaximumValue();


    void
    setValue(double value);


public slots:

	void
	updateSlider();


private:

	double min;
	double max;
	double init;
	double value;


	QLineEdit* text;
	QSlider* slider;




};


}

#endif
