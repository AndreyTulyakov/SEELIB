#include "DTrigger.h"
#include <QColor>

DTrigger::DTrigger(QString name, QWidget *parent) : UmElement(name, parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 80);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 16);

    addInputPort("D");
    addInputPort("CLK");

    addOutputPort("Q", false);
    addOutputPort("!Q", true);
}

DTrigger::~DTrigger()
{
    delete label;
}

void DTrigger::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    painter.drawLine(0,22, this->width(), 22);

    painter.setPen(Qt::black);
    painter.drawText(10, 40, "D");
    painter.drawText(10, 70,  "CLK");

    painter.drawText(60, 40, "Q");
    painter.drawText(57, 70, "!Q");

}

void DTrigger::onInputUpdated(QString pinName)
{
    bool d = getPortValue("D");
    bool clk = getPortValue("CLK");

    if(clk == true)
    {
        setOutputPortValue("Q", d);
        setOutputPortValue("!Q", !d);
    }
}





