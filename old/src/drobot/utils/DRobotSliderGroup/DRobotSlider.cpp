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
	_text = new QLineEdit(QString::number(init));
	_text->setFixedSize(60,20);
	_slider = new QSlider(Qt::Horizontal);
	_slider->setMinimum(0);
	_slider->setMaximum(1000);
	_slider->setFixedSize(200,20);
	_slider->setTickInterval(1000);

//	layout->addWidget(qlabel);
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

DRobotSlider::~DRobotSlider()
{

}

void DRobotSlider::setValue(double value)
{
	std::cerr << "Servo value " << value << ", " << (int) ((value - _min) / (_max - _min) * 1000.0) << std::endl;
	_value = value;
	_slider->setValue((int) ((value - _min) / (_max - _min) * 1000.0));
	_text->setText(QString::number(value));
}

void DRobotSlider::updateSlider()
{
	_value = (double) _slider->value() / 1000.0 * (_max - _min) + _min;
	_text->setText(QString::number(_value));
}

}
