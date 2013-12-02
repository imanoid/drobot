#ifndef HANDMOUTHWIDGET_H
#define HANDMOUTHWIDGET_H

#include <QScrollArea>

namespace drobot {
namespace experiment {
namespace handmouth {
namespace widget {

namespace Ui {
class HandMouthWidget;
}

class HandMouthWidget : public QScrollArea
{
    Q_OBJECT
    
public:
    explicit HandMouthWidget(QWidget *parent = 0);
    ~HandMouthWidget();
    
private:
    Ui::HandMouthWidget *ui;
};

}
}
}
}

#endif // HANDMOUTHWIDGET_H
