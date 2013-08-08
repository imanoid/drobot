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

	double getValue()	{ return _value; }
	double getInitValue()	{ return _init; }
	double getMinimum()	{ return _min; }
	double getMaximum()	{ return _max; }

	void setValue(double value);

public slots:
	void updateSlider();

private:
	double _min;
	double _max;
	double _init;
	double _value;

	QLineEdit *_text;
	QSlider *_slider;
};

}

#endif
