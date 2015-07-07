#include "Summator.h"

Summator::Summator(QString name, QWidget *parent) : UmElement(name, parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 110);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 16);

    addInputPort("A");
    addInputPort("B");
    addInputPort("P");

    addOutputPort("S", false);
    addOutputPort("P+", true);
}

Summator::~Summator()
{
    delete label;
}

void Summator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    painter.drawLine(0,22, this->width(), 22);
    painter.drawLine(22,22, 22, this->height());
    painter.drawLine(this->width() - 22, 22, this->width() - 22, this->height());


    painter.setPen(Qt::black);
    painter.drawText(8, 40, "P");
    painter.drawText(8, 70,  "A");
    painter.drawText(8, 100,  "B");

    painter.drawText(67, 40, "S");
    painter.drawText(63, 100, "P+");
}

void Summator::onInputUpdated(QString pinName)
{
    bool p = getPortValue("P");
    bool a = getPortValue("A");
    bool b = getPortValue("B");

    if(p)
    {
        if(!a && !b)
        {
            setOutputPortValue("S", true);
            setOutputPortValue("P+", false);
        }

        if(a && !b)
        {
            setOutputPortValue("S", false);
            setOutputPortValue("P+", true);
        }

        if(!a && b)
        {
            setOutputPortValue("S", false);
            setOutputPortValue("P+", true);
        }

        if(a && b)
        {
            setOutputPortValue("S", true);
            setOutputPortValue("P+", true);
        }
    }
    else
    {
        if(!a && !b)
        {
            setOutputPortValue("S", false);
            setOutputPortValue("P+", false);
        }

        if(a && !b)
        {
            setOutputPortValue("S", true);
            setOutputPortValue("P+", false);
        }

        if(!a && b)
        {
            setOutputPortValue("S", true);
            setOutputPortValue("P+", false);
        }

        if(a && b)
        {
            setOutputPortValue("S", false);
            setOutputPortValue("P+", true);
        }
    }
}

