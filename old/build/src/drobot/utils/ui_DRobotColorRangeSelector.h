/********************************************************************************
** Form generated from reading UI file 'DRobotColorRangeSelector.ui'
**
** Created: Wed Jun 5 15:49:22 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROBOTCOLORRANGESELECTOR_H
#define UI_DROBOTCOLORRANGESELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DRobotColorRangeSelectorWidget
{
public:
    QGroupBox *groupBox;
    QSlider *lredSlider;
    QLabel *label_3;
    QLabel *label_6;
    QSlider *lblueSlider;
    QSlider *lgreenSlider;
    QLabel *label_5;
    QLineEdit *lredEdit;
    QLineEdit *lgreenEdit;
    QLineEdit *lblueEdit;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QLabel *label_7;
    QSlider *uredSlider;
    QSlider *ugreenSlider;
    QLabel *label_4;
    QSlider *ublueSlider;
    QLineEdit *uredEdit;
    QLineEdit *ublueEdit;
    QLineEdit *ugreenEdit;

    void setupUi(QWidget *DRobotColorRangeSelectorWidget)
    {
        if (DRobotColorRangeSelectorWidget->objectName().isEmpty())
            DRobotColorRangeSelectorWidget->setObjectName(QString::fromUtf8("DRobotColorRangeSelectorWidget"));
        DRobotColorRangeSelectorWidget->resize(514, 218);
        groupBox = new QGroupBox(DRobotColorRangeSelectorWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 201));
        groupBox->setBaseSize(QSize(0, 0));
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        lredSlider = new QSlider(groupBox);
        lredSlider->setObjectName(QString::fromUtf8("lredSlider"));
        lredSlider->setGeometry(QRect(10, 50, 160, 29));
        lredSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 141, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 141, 21));
        lblueSlider = new QSlider(groupBox);
        lblueSlider->setObjectName(QString::fromUtf8("lblueSlider"));
        lblueSlider->setGeometry(QRect(10, 150, 160, 29));
        lblueSlider->setOrientation(Qt::Horizontal);
        lgreenSlider = new QSlider(groupBox);
        lgreenSlider->setObjectName(QString::fromUtf8("lgreenSlider"));
        lgreenSlider->setGeometry(QRect(10, 100, 160, 29));
        lgreenSlider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 80, 141, 21));
        lredEdit = new QLineEdit(groupBox);
        lredEdit->setObjectName(QString::fromUtf8("lredEdit"));
        lredEdit->setGeometry(QRect(180, 50, 41, 27));
        lredEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lredEdit->setReadOnly(false);
        lgreenEdit = new QLineEdit(groupBox);
        lgreenEdit->setObjectName(QString::fromUtf8("lgreenEdit"));
        lgreenEdit->setGeometry(QRect(180, 100, 41, 27));
        lgreenEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblueEdit = new QLineEdit(groupBox);
        lblueEdit->setObjectName(QString::fromUtf8("lblueEdit"));
        lblueEdit->setGeometry(QRect(180, 150, 41, 27));
        lblueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_2 = new QGroupBox(DRobotColorRangeSelectorWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 10, 231, 191));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 130, 141, 21));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 141, 21));
        uredSlider = new QSlider(groupBox_2);
        uredSlider->setObjectName(QString::fromUtf8("uredSlider"));
        uredSlider->setGeometry(QRect(10, 50, 160, 29));
        uredSlider->setOrientation(Qt::Horizontal);
        ugreenSlider = new QSlider(groupBox_2);
        ugreenSlider->setObjectName(QString::fromUtf8("ugreenSlider"));
        ugreenSlider->setGeometry(QRect(10, 100, 160, 29));
        ugreenSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 141, 21));
        ublueSlider = new QSlider(groupBox_2);
        ublueSlider->setObjectName(QString::fromUtf8("ublueSlider"));
        ublueSlider->setGeometry(QRect(10, 150, 160, 29));
        ublueSlider->setOrientation(Qt::Horizontal);
        uredEdit = new QLineEdit(groupBox_2);
        uredEdit->setObjectName(QString::fromUtf8("uredEdit"));
        uredEdit->setGeometry(QRect(180, 50, 41, 27));
        uredEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        uredEdit->setReadOnly(false);
        ublueEdit = new QLineEdit(groupBox_2);
        ublueEdit->setObjectName(QString::fromUtf8("ublueEdit"));
        ublueEdit->setGeometry(QRect(180, 150, 41, 27));
        ublueEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ugreenEdit = new QLineEdit(groupBox_2);
        ugreenEdit->setObjectName(QString::fromUtf8("ugreenEdit"));
        ugreenEdit->setGeometry(QRect(180, 100, 41, 27));
        ugreenEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(DRobotColorRangeSelectorWidget);

        QMetaObject::connectSlotsByName(DRobotColorRangeSelectorWidget);
    } // setupUi

    void retranslateUi(QWidget *DRobotColorRangeSelectorWidget)
    {
        DRobotColorRangeSelectorWidget->setWindowTitle(QApplication::translate("DRobotColorRangeSelectorWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DRobotColorRangeSelectorWidget", "Lower bound", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "Red:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "Blue:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "Green:", 0, QApplication::UnicodeUTF8));
        lredEdit->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "0", 0, QApplication::UnicodeUTF8));
        lgreenEdit->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "0", 0, QApplication::UnicodeUTF8));
        lblueEdit->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "0", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DRobotColorRangeSelectorWidget", "Lower bound", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "Blue:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "Green:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "Red:", 0, QApplication::UnicodeUTF8));
        uredEdit->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "0", 0, QApplication::UnicodeUTF8));
        ublueEdit->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "0", 0, QApplication::UnicodeUTF8));
        ugreenEdit->setText(QApplication::translate("DRobotColorRangeSelectorWidget", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DRobotColorRangeSelectorWidget: public Ui_DRobotColorRangeSelectorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROBOTCOLORRANGESELECTOR_H
