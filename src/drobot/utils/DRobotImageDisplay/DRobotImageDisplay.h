
#ifndef _DROBOT_DROBOTIMAGEDISPLAY_H_
#define _DROBOT_DROBOTIMAGEDISPLAY_H_

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QImage>
#include <QKeyEvent>

#include <boost/signals2/mutex.hpp>
#include <highgui.h>

namespace drobot
{

class DRobotImageDisplay : public QWidget
{
    Q_OBJECT

public:

    DRobotImageDisplay();

    ~DRobotImageDisplay();

    void
    imshow(std::string title, cv::Mat img);

    void
    paintEvent(QPaintEvent* e);

private:
	void
	convertToGrayscale(QImage* in);


protected:
    void close();


public slots:

	void
	display();

signals:
	void
	dataUpdated();

	void
	closed();


private:

    QImage* image;

    bool colorImage;

    bool imageInitialised;



    cv::Mat raw;

};


}

#endif
