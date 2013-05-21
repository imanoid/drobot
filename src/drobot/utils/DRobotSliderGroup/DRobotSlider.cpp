
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QStatusBar>
#include <qformlayout.h>
#include <QSlider>
#include <string.h>

#include <cv.h>

#include "DRobotSlider.h"


namespace drobot
{


DRobotSlider::DRobotSlider(std::string label, double init, double min, double max) : QWidget()
{

	QHBoxLayout* layout = new QHBoxLayout();

	this->setLayout(layout);

//	QLabel* qlabel = new QLabel(label.c_str());
	text = new QLineEdit(QString::number(init));
	text->setFixedSize(60,20);
	slider = new QSlider(Qt::Horizontal);
	slider->setMinimum(0);
	slider->setMaximum(1000);
	slider->setFixedSize(200,20);
	slider->setTickInterval(1000);

//	layout->addWidget(qlabel);
	layout->addWidget(slider);
	layout->addWidget(text);

	QObject::connect( slider, SIGNAL(valueChanged(int)),
		                      this, SLOT(updateSlider()));

	this->min = min;
	this->max = max;
	this->value = min;
	this->init = init;
	setValue(init);
}



DRobotSlider::~DRobotSlider()
{

}

double
DRobotSlider::getValue()
{
	return value;
}


double
DRobotSlider::getInitValue()
{
	return init;
}

double
DRobotSlider::getMinimumValue()
{
	return min;
}

double
DRobotSlider::getMaximumValue()
{
	return max;
}



void
DRobotSlider::setValue(double value)
{
	std::cerr << "Servo value " << value << ", " << (int) ((value - min) / (max - min) * 1000.0) << std::endl;
	slider->setValue((int) ((value - min) / (max - min) * 1000.0));
}




void
DRobotSlider::updateSlider()
{
	value = (double) slider->value() / 1000.0 * (max - min) + min;
	text->setText(QString::number(value));
}


}
