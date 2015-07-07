#include "UmButton.h"
#include <QDebug>

UmButton::UmButton(QWidget *parent) : UmElement("", parent)
{
    frame_size = 32;
    image = new QImage(":graphics/ButtonWidget");
    setFixedWidth(image->width()/2+10);
    setFixedHeight(image->height());
    //setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    label = 0;

    addOutputPort("OUT", false);
}

UmButton::UmButton(QString labelname, QWidget *parent) : UmElement(labelname, parent)
{
    frame_size = 32;
    image = new QImage(":graphics/ButtonWidget");
    setFixedWidth(image->width()/2+10);
    setFixedHeight(image->height()+20);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    label = new QLabel(this);
    label->setText(labelname);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Times", 10));
    label->setGeometry(2, 2, (this->width()-4), 16);
    addOutputPort("OUT", false);
}

UmButton::~UmButton()
{
    if(label != 0)
    {
        delete label;
    }
}

void UmButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);

    if((bool)getPortValue("OUT"))
    {
        painter.drawImage(5, this->height()-image->height(), *image, frame_size, 0, frame_size, frame_size);
    }
    else
    {
        painter.drawImage(5, this->height()-image->height(), *image, 0, 0, frame_size, frame_size);
    }
}

void UmButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        setOutputPortValue("OUT", true);
        emit repaint();
    }
}

void UmButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        setOutputPortValue("OUT", false);
        emit repaint();
    }
}

