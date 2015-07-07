#include "UmLedWidget.h"

#include <QPainter>
#include <QMouseEvent>

UmLed::UmLed(QWidget *parent) : UmElement("", parent)
{
    checked = false;

    frame_size = 16; // Пикселей

    image = new QImage(":graphics/LedWidget");
    setFixedWidth(image->width());
    setFixedHeight(image->height());
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    this->addInputPort("DATA");
}

void UmLed::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    if((bool)getPortValue("DATA"))
    {
        p.drawImage(0, 0, *image, frame_size, 0, frame_size, frame_size);
    }
    else
    {
        p.drawImage(0, 0, *image, 0, 0, frame_size, frame_size);
    }
}

void UmLed::onInputUpdated(QString pinName)
{
    emit repaint();
}
