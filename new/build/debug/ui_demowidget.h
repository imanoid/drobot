/********************************************************************************
** Form generated from reading UI file 'demowidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOWIDGET_H
#define UI_DEMOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

namespace drobot {
namespace experiment {
namespace demo {
namespace widget {

class Ui_DemoWidget
{
public:
    QWidget *scrollAreaWidgetContents;

    void setupUi(QScrollArea *drobot__experiment__demo__widget__DemoWidget)
    {
        if (drobot__experiment__demo__widget__DemoWidget->objectName().isEmpty())
            drobot__experiment__demo__widget__DemoWidget->setObjectName(QString::fromUtf8("drobot__experiment__demo__widget__DemoWidget"));
        drobot__experiment__demo__widget__DemoWidget->setWidgetResizable(true);
        drobot__experiment__demo__widget__DemoWidget->resize(400, 300);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        drobot__experiment__demo__widget__DemoWidget->setWidget(scrollAreaWidgetContents);

        retranslateUi(drobot__experiment__demo__widget__DemoWidget);

        QMetaObject::connectSlotsByName(drobot__experiment__demo__widget__DemoWidget);
    } // setupUi

    void retranslateUi(QScrollArea *drobot__experiment__demo__widget__DemoWidget)
    {
        drobot__experiment__demo__widget__DemoWidget->setWindowTitle(QApplication::translate("drobot::experiment::demo::widget::DemoWidget", "ScrollArea", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

} // namespace widget
} // namespace demo
} // namespace experiment
} // namespace drobot

namespace drobot {
namespace experiment {
namespace demo {
namespace widget {
namespace Ui {
    class DemoWidget: public Ui_DemoWidget {};
} // namespace Ui
} // namespace widget
} // namespace demo
} // namespace experiment
} // namespace drobot

#endif // UI_DEMOWIDGET_H
