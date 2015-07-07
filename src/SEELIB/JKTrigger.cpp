#include "JKTrigger.h"

JKTrigger::JKTrigger(QString name, QWidget *parent) : UmElement(name, parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 110);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 16);

    addInputPort("J");
    addInputPort("CLK");
    addInputPort("K");

    addOutputPort("Q", false);
    addOutputPort("!Q", true);
}

JKTrigger::~JKTrigger()
{
    delete label;
}

void JKTrigger::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    painter.drawLine(0,22, this->width(), 22);

    painter.setPen(Qt::black);
    painter.drawText(10, 40, "J");
    painter.drawText(10, 70,  "K");
    painter.drawText(10, 100,  "CLK");

    painter.drawText(60, 40, "Q");
    painter.drawText(57, 70, "!Q");
}

void JKTrigger::onInputUpdated(QString pinName)
{
    bool j = getPortValue("J");
    bool k = getPortValue("K");
    bool c = getPortValue("CLK");

    if(c)
    {
        if(j == true && k == false)
        {
            setOutputPortValue("Q", true);
            setOutputPortValue("!Q", false);
            return;
        }

        if(j == true && k == true)
        {
            bool value = getPortValue("Q");
            setOutputPortValue("Q", !value);
            setOutputPortValue("!Q", value);
            return;
        }

        if(j == false && k == true)
        {
            setOutputPortValue("Q", false);
            setOutputPortValue("!Q", true);
            return;
        }
    }
}

