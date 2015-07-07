#include "RSTrigger.h"

RSTrigger::RSTrigger(QString name, QWidget *parent) : UmElement(name, parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 80);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 16);

    addInputPort("S");
    addInputPort("R");

    addOutputPort("Q", false);
    addOutputPort("!Q", true);
}

RSTrigger::~RSTrigger()
{
    delete label;
}

void RSTrigger::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    painter.drawLine(0,22, this->width(), 22);

    painter.setPen(Qt::black);
    painter.drawText(10, 40, "S");
    painter.drawText(10, 70, "R");

    painter.drawText(60, 40, "Q");
    painter.drawText(57, 70, "!Q");
}

void RSTrigger::onInputUpdated(QString pinName)
{
    bool s = getPortValue("S");
    bool r = getPortValue("R");

    if(s == true && r == false)
    {
        setOutputPortValue("Q", true);
        setOutputPortValue("!Q", false);
        return;
    }

    if(s == false && r == true)
    {
        setOutputPortValue("Q", false);
        setOutputPortValue("!Q", true);
        return;
    }

    if(s == true && r == true)
    {
        setOutputPortValue("Q", false);
        setOutputPortValue("!Q", false);
        return;
    }

    if(s == false && r == false)
    {
        // None
        return;
    }
}

