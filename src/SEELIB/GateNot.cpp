#include "GateNot.h"

GateNot::GateNot(QWidget *parent) : UmElement("NOT", parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 65);

    addInputPort("A");
    addOutputPort("F", false);
}

GateNot::~GateNot()
{

}

void GateNot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRect(0, 0, this->width()-1, this->height()-1);
    painter.drawLine(22,0, 22, this->height());
    painter.drawLine(this->width() - 22, 0, this->width() - 22, this->height());

    painter.setPen(Qt::black);

    painter.drawRect(this->width()-4, 30, 3, 4);

    painter.drawText(37,35, "1");
    painter.drawText(8, 36, "A");
    painter.drawText(67,36, "F");
}

void GateNot::onInputUpdated(QString pinName)
{
    setOutputPortValue("F", !getPortValue("A"));
}

