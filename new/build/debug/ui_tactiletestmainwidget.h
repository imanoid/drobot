/********************************************************************************
** Form generated from reading UI file 'tactiletestmainwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TACTILETESTMAINWIDGET_H
#define UI_TACTILETESTMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace widget {

class Ui_MainWidget
{
public:
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;

    void setupUi(QScrollArea *drobot__experiment__tactileTest__widget__MainWidget)
    {
        if (drobot__experiment__tactileTest__widget__MainWidget->objectName().isEmpty())
            drobot__experiment__tactileTest__widget__MainWidget->setObjectName(QString::fromUtf8("drobot__experiment__tactileTest__widget__MainWidget"));
        drobot__experiment__tactileTest__widget__MainWidget->resize(400, 300);
        drobot__experiment__tactileTest__widget__MainWidget->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 298));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 130, 97, 31));
        drobot__experiment__tactileTest__widget__MainWidget->setWidget(scrollAreaWidgetContents);

        retranslateUi(drobot__experiment__tactileTest__widget__MainWidget);

        QMetaObject::connectSlotsByName(drobot__experiment__tactileTest__widget__MainWidget);
    } // setupUi

    void retranslateUi(QScrollArea *drobot__experiment__tactileTest__widget__MainWidget)
    {
        drobot__experiment__tactileTest__widget__MainWidget->setWindowTitle(QApplication::translate("drobot::experiment::tactileTest::widget::MainWidget", "ScrollArea", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("drobot::experiment::tactileTest::widget::MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

} // namespace widget
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace widget {
namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui
} // namespace widget
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

#endif // UI_TACTILETESTMAINWIDGET_H
