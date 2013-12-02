#include "handmouthwidget.h"
#include "ui_handmouthwidget.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace widget {

HandMouthWidget::HandMouthWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::HandMouthWidget)
{
    ui->setupUi(this);
}

HandMouthWidget::~HandMouthWidget()
{
    delete ui;
}

}
}
}
}
