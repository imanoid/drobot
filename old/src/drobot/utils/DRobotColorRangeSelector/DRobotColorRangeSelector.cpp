
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QStatusBar>
#include <string.h>

#include <cv.h>

#include "DRobotColorRangeSelector.h"


namespace drobot
{


DRobotColorRangeSelector::DRobotColorRangeSelector() : QWidget(), Ui_DRobotColorRangeSelectorWidget()
{
	setupUi(this);

	QObject::connect( this->lredSlider, SIGNAL(valueChanged(int)),
		                      this, SLOT(lowerRedSliderChanged()));

	QObject::connect( this->lgreenSlider, SIGNAL(valueChanged(int)),
		                      this, SLOT(lowerGreenSliderChanged()));

	QObject::connect( this->lblueSlider, SIGNAL(valueChanged(int)),
		                      this, SLOT(lowerBlueSliderChanged()));

	QObject::connect( this->uredSlider, SIGNAL(valueChanged(int)),
		                      this, SLOT(upperRedSliderChanged()));

	QObject::connect( this->ugreenSlider, SIGNAL(valueChanged(int)),
		                      this, SLOT(upperGreenSliderChanged()));

	QObject::connect( this->ublueSlider, SIGNAL(valueChanged(int)),
		                      this, SLOT(upperBlueSliderChanged()));


	lredSlider->setMaximum(255);
	lredSlider->setMinimum(0);
	lredSlider->setValue(0);
	lgreenSlider->setMaximum(255);
	lgreenSlider->setMinimum(0);
	lblueSlider->setMaximum(255);
	lblueSlider->setMinimum(0);
	uredSlider->setMaximum(255);
	uredSlider->setMinimum(0);
	ugreenSlider->setMaximum(255);
	ugreenSlider->setMinimum(0);
	ublueSlider->setMaximum(255);
	ublueSlider->setMinimum(0);

	for (int i=0; i<6; i++)
		colorBounds[i] = 0;


}

DRobotColorRangeSelector::~DRobotColorRangeSelector()
{

}

int*
DRobotColorRangeSelector::getColorBounds()
{
	return colorBounds;
}

void
DRobotColorRangeSelector::lowerRedSliderChanged()
{
	colorBounds[0] = lredSlider->value();
	lredEdit->setText(QString::number(colorBounds[0]));
}

void
DRobotColorRangeSelector::lowerGreenSliderChanged()
{
	colorBounds[1] = lgreenSlider->value();
	lgreenEdit->setText(QString::number(colorBounds[1]));
}

void
DRobotColorRangeSelector::lowerBlueSliderChanged()
{
	colorBounds[2] = lblueSlider->value();
	lblueEdit->setText(QString::number(colorBounds[2]));
}

void
DRobotColorRangeSelector::upperRedSliderChanged()
{
	colorBounds[3] = uredSlider->value();
	uredEdit->setText(QString::number(colorBounds[3]));
}

void
DRobotColorRangeSelector::upperGreenSliderChanged()
{
	colorBounds[4] = ugreenSlider->value();
	ugreenEdit->setText(QString::number(colorBounds[4]));
}

void
DRobotColorRangeSelector::upperBlueSliderChanged()
{
	colorBounds[5] = ublueSlider->value();
	ublueEdit->setText(QString::number(colorBounds[5]));

}


}
