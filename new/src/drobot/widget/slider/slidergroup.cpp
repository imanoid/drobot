#include <iostream>
#include <boost/filesystem.hpp>

#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QDir>
#include <QtXml>

#include "slidergroup.h"
#include "slider.h"

namespace drobot {
namespace widget {
namespace slider {

SliderGroup::SliderGroup(std::string title, std::vector<device::channel::Channel*> channels, std::vector<double> mins, std::vector<double> maxs, std::vector<double> inits)
    : _title(title)
{
    std::vector<std::string> labels;
    for (std::vector<device::channel::Channel*>::iterator it = channels.begin(); it < channels.end(); it++)
        if (*it)
            labels.push_back((*it)->getName());

    QFormLayout* layout = new QFormLayout();
    this->setLayout(layout);

    for (size_t i = 0; i < labels.size(); i++) {
        Slider* slider = new Slider(mins[i], maxs[i], inits[i]);
        layout->addRow(new QLabel(labels[i].c_str()), slider);
        _sliders.push_back(slider);
    }

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

double SliderGroup::getValue(int index)
{
    return _sliders[index]->getValue();
}


double SliderGroup::operator[](int index)
{
    return _sliders[index]->getValue();
}

void SliderGroup::setValue(int index, double value)
{
    _sliders[index]->setValue(value);
}

void SliderGroup::reset()
{
}

void SliderGroup::load()
{
}

void SliderGroup::save()
{
    boost::filesystem::path path(QDir::homePath().toStdString());
    path /= ".drobot/";

    if (!boost::filesystem::exists(path)) {
        if (!boost::filesystem::create_directory(path)) {
            std::cerr << "failed to create directory " << path << std::endl;
            return;
        }
    }

    QFile file(QString((path / "sliders.xml").c_str()));
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

    for (std::vector<Slider*>::iterator it = _sliders.begin(); it < _sliders.end(); it++) {
        xmlWriter.writeStartElement("Slider");
        xmlWriter.writeTextElement("value", QString::number((*it)->getValue()));
        xmlWriter.writeTextElement("min", QString::number((*it)->getMinimum()));
        xmlWriter.writeTextElement("max", QString::number((*it)->getMaximum()));
        xmlWriter.writeTextElement("init", QString::number((*it)->getInit()));
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();
}

} // namespace slider
} // namespace widget
} // namespace drobot
