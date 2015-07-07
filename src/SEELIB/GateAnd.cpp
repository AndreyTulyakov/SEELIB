#include "GateAnd.h"

GateAnd::GateAnd(QWidget *parent, bool inversedOut) : UmElement("AND", parent)
{
    this->inversedOut = inversedOut;
    this->setGeometry(this->x(),this->y(), 80 , 65);

    addInputPort("A");
    addInputPort("B");

    addOutputPort("F", false);
}

GateAnd::~GateAnd()
{

}

void GateAnd::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRect(0, 0, this->width()-1, this->height()-1);
    painter.drawLine(22,0, 22, this->height());
    painter.drawLine(this->width() - 22, 0, this->width() - 22, this->height());

    painter.setPen(Qt::black);

    if(inversedOut)
        painter.drawRect(this->width()-4, 30, 3, 4);


    painter.drawText(37,35, "&");

    painter.drawText(8, 20, "A");
    painter.drawText(8, 50, "B");

    painter.drawText(67,36, "F");
}

void GateAnd::onInputUpdated(QString pinName)
{
    bool a = getPortValue("A");
    bool b = getPortValue("B");
    bool result = a & b;
    if(inversedOut)
        result = !result;

    setOutputPortValue("F", result);
}

