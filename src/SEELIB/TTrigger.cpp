#include "TTrigger.h"
#include <QColor>

TTrigger::TTrigger(QString name, QWidget *parent) : UmElement(name, parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 80);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 16);

    addInputPort("T");
    addInputPort("CLK");

    addOutputPort("Q", false);
    addOutputPort("!Q", true);
}

TTrigger::~TTrigger()
{
    delete label;
}

void TTrigger::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    painter.drawLine(0,22, this->width(), 22);

    painter.setPen(Qt::black);
    painter.drawText(10, 40, "T");
    painter.drawText(10, 70,  "CLK");

    painter.drawText(60, 40, "Q");
    painter.drawText(57, 70, "!Q");

}

void TTrigger::onInputUpdated(QString pinName)
{
    bool t = getPortValue("T");
    bool clk = getPortValue("CLK");

    if(clk == true && t == true)
    {
        bool value = getPortValue("Q");
        setOutputPortValue("Q", !value);
        setOutputPortValue("!Q", value);
    }
}





