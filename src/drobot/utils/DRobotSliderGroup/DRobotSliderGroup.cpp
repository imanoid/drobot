
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QStatusBar>
#include <QPushButton>
#include <qformlayout.h>
#include <QSlider>
#include <qxmlstream.h>
#include <string.h>

#include <cv.h>

#include "DRobotSlider.h"
#include "DRobotSliderGroup.h"
#include "DRobotFileSystem/DRobotFileSystem.h"


namespace drobot
{


DRobotSliderGroup::DRobotSliderGroup(std::string title, std::vector<std::string> labels, double init, double min, double max) : QWidget()
{
	this->title = title;
	this->setWindowTitle(title.c_str());

	QFormLayout* layout = new QFormLayout();
	this->setLayout(layout);

	for(int i=0; i<labels.size(); i++)
	{
		DRobotSlider* slider = new DRobotSlider(labels[i], init, min, max);
		layout->addRow(new QLabel(labels[i].c_str()), slider);
		sliders.push_back(slider);
	}

	createButtonPanel(layout);
}


DRobotSliderGroup::DRobotSliderGroup(std::string title, std::vector<std::string> labels, std::vector<double> init, std::vector<double> min, std::vector<double> max) : QWidget()
{
	this->title = title;
	this->setWindowTitle(title.c_str());

	QFormLayout* layout = new QFormLayout();
	this->setLayout(layout);

	for(int i=0; i<labels.size(); i++)
	{
		DRobotSlider* slider = new DRobotSlider(labels[i], init[i], min[i], max[i]);
		layout->addRow(new QLabel(labels[i].c_str()), slider);
		sliders.push_back(slider);
	}

	createButtonPanel(layout);
}


DRobotSliderGroup::~DRobotSliderGroup()
{

}

double
DRobotSliderGroup::getValue(int index)
{
	return sliders[index]->getValue();
}


double
DRobotSliderGroup::operator[](int index)
{
	return sliders[index]->getValue();
}


void
DRobotSliderGroup::save()
{
	std::cerr << "save" << std::endl;

	QString path = QDir::homePath() + "/.sliders";
	if(!drobot::DRobotFileSystem::directoryExists(path.toStdString()))
	{
		drobot::DRobotFileSystem::createDirectory(path.toStdString());
	}

	QString filepath = QDir::homePath() + "/.sliders/" + QString(title.c_str()) + ".xml";

	QFile file(filepath);
	file.open(QIODevice::WriteOnly);

	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true);
	xmlWriter.writeStartDocument();

	xmlWriter.writeStartElement("SliderGroup");

	QRect geometry = this->geometry();

	xmlWriter.writeStartElement("Geometry");
	xmlWriter.writeTextElement("x0", QString::number(geometry.x()) );
	xmlWriter.writeTextElement("y0", QString::number(geometry.y()));
	xmlWriter.writeTextElement("width", QString::number(geometry.width()));
	xmlWriter.writeTextElement("height", QString::number(geometry.height()) );
	xmlWriter.writeEndElement();

	xmlWriter.writeStartElement("Sliders");

	for(int i=0; i<sliders.size(); i++)
	{
		xmlWriter.writeStartElement("Slider");
		xmlWriter.writeTextElement("value", QString::number(sliders[i]->getValue()));
		xmlWriter.writeTextElement("init", QString::number(sliders[i]->getInitValue()));
		xmlWriter.writeTextElement("min", QString::number(sliders[i]->getMinimumValue()));
		xmlWriter.writeTextElement("max", QString::number(sliders[i]->getMaximumValue()));
		xmlWriter.writeEndElement();

	}

	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();

	file.close();

}

void
DRobotSliderGroup::load()
{
	std::cerr << "load" << std::endl;

	QString filepath = QDir::homePath() + "/.sliders/" + QString(title.c_str()) + ".xml";

	if(!drobot::DRobotFileSystem::fileExists(filepath.toStdString()))
	{
		std::cerr << "File: " << filepath.toStdString() << " does not exist. Slider parameters won't be loaded for " << title << " window " << std::endl;
		return;
	}




}

void
DRobotSliderGroup::reset()
{
	std::cerr << "reset" << std::endl;


}


void
DRobotSliderGroup::createButtonPanel(QFormLayout* layout)
{
	QPushButton* resetBtn = new QPushButton("Reset");
	QPushButton* loadBtn = new QPushButton("Load");
	QPushButton* saveBtn = new QPushButton("Save");

	QHBoxLayout* buttonLayout = new QHBoxLayout();
	buttonLayout->addWidget(resetBtn);
	buttonLayout->addWidget(loadBtn);
	buttonLayout->addWidget(saveBtn);

	layout->addRow(new QLabel(""), buttonLayout);

	QObject::connect( resetBtn, SIGNAL(clicked()),
			this, SLOT(reset()));

	QObject::connect( loadBtn, SIGNAL(clicked()),
			this, SLOT(load()));

	QObject::connect( saveBtn, SIGNAL(clicked()),
			this, SLOT(save()));


}

}
