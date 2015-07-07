#include "UmTumblerWidget.h"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

UmTumbler::UmTumbler(QWidget *parent): UmElement("", parent)
{
    checked = false;
    frame_size = 32;
    image = new QImage(":graphics/TumblerWidget");
    setFixedWidth(image->width()/2);
    setFixedHeight(image->height());
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    label = 0;

    addOutputPort("OUT", false);
}

UmTumbler::UmTumbler(QString labelname, QWidget *parent) : UmElement(labelname, parent)
{
    checked = false;
    frame_size = 32;
    image = new QImage(":graphics/TumblerWidget");
    setFixedWidth(image->width()/2);
    setFixedHeight(image->height()+20);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    label = new QLabel(this);
    label->setText(labelname);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Times", 10));
    label->setGeometry(2, 2, (this->width()-4), 16);
    addOutputPort("OUT", false);
}

UmTumbler::~UmTumbler()
{
    if(label != 0)
    {
        delete label;
    }
}

void UmTumbler::setChecked(bool value)
{
    checked = value;
    setOutputPortValue("OUT", value);
    emit repaint();
    emit stateChanged();
}

bool UmTumbler::isChecked()
{
    return checked;
}

void UmTumbler::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);

    if(checked)
    {
        painter.drawImage(0, this->height()-image->height(), *image, frame_size, 0, frame_size, frame_size);
    }
    else
    {
        painter.drawImage(0, this->height()-image->height(), *image, 0, 0, frame_size, frame_size);
    }
}

void UmTumbler::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        setChecked(!isChecked());
    }
    QWidget::mousePressEvent(event);
}
