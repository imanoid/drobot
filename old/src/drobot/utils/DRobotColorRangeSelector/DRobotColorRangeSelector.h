
#ifndef _DROBOT_DROBOTCOLORRANGESELECTOR_H_
#define _DROBOT_DROBOTCOLORRANGESELECTOR_H_

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QImage>
#include <QKeyEvent>

#include "ui_DRobotColorRangeSelector.h"

namespace drobot
{

class DRobotColorRangeSelector : public QWidget, Ui_DRobotColorRangeSelectorWidget
{
    Q_OBJECT

public:

    DRobotColorRangeSelector();

    ~DRobotColorRangeSelector();

    int* getColorBounds();



public slots:

	void
	lowerRedSliderChanged();

	void
	lowerGreenSliderChanged();

	void
	lowerBlueSliderChanged();

	void
	upperRedSliderChanged();

	void
	upperGreenSliderChanged();

	void
	upperBlueSliderChanged();


private:

    int colorBounds[6];

};


}

#endif
