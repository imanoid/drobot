
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QStatusBar>
#include <string.h>

#include <cv.h>

#include "DRobotImageDisplay.h"


namespace drobot
{


DRobotImageDisplay::DRobotImageDisplay() : QWidget()
{
	imageInitialised = false;

	QObject::connect(this, SIGNAL(dataUpdated()),
		                      this, SLOT(display()),Qt::QueuedConnection);

}

DRobotImageDisplay::~DRobotImageDisplay()
{
	if ( image )
		delete image;

}


void DRobotImageDisplay::imshow(cv::Mat img)
{
	// Since OpenCV uses BGR order, we need to convert it to RGB
	QImage::Format format;


		if (img.type() == CV_8UC3)
		{
			colorImage = false;
			format = QImage::Format_RGB888;
			cv::cvtColor(img, img, CV_BGR2RGB);
		} else {

			format = QImage::Format_Indexed8;
			colorImage = false;
		}


	    if ( !imageInitialised && img.size().width != 0)
	    {
	    	image = new QImage(img.size().width, img.size().height, format);
	    	imageInitialised = true;
	    }


	    // TODO: needs a mutex here
	    raw = img;

	    emit dataUpdated();


}

void DRobotImageDisplay::display()
{

	if (!imageInitialised)
    	return;

	memcpy(image->scanLine(0), (unsigned char*)raw.data, image->width() * image->height() * raw.channels());

    resize(image->width(), image->height());

	update();
}

void DRobotImageDisplay::paintEvent(QPaintEvent* e)
{


	QPainter painter(this);

    // When no image has been loaded, there's nothing to draw.
    if (!imageInitialised || !image)
        return;

//	image = new QImage(raw.size().width, raw.size().height, QImage::Format_RGB888);


    if(image->format() == QImage::Format_Indexed8)
    	convertToGrayscale(image);

    painter.drawImage(QPoint(0, 0), *image);

    QWidget::paintEvent(e);


}


void
DRobotImageDisplay::close()
{
    emit closed();
}


void
DRobotImageDisplay::convertToGrayscale(QImage* in)
{
	if(in->format()!=QImage::Format_Indexed8)
		throw "format error";

	QVector<int> transform_table(256);

	for(int i=0;i<in->numColors();i++)
	{
		QRgb c1=in->color(i);
		int avg = qGray(c1);
		transform_table[i] = avg;
	}


	in->setNumColors(256);
	for(int i=0;i<256;i++)
		in->setColor(i,qRgb(i,i,i));

	for(int i=0;i<in->numBytes();i++)
	{
		in->bits()[i]=transform_table[in->bits()[i]];
	}
}

}
