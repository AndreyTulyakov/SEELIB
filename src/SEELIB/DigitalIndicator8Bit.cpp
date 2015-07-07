#include "DigitalIndicator8Bit.h"


DigitalIndicator8Bit::DigitalIndicator8Bit(QString name, QWidget *parent) : UmElement(name, parent)
{
    setFixedWidth(120);
    setFixedHeight(100);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Times", 10));
    label->setGeometry(2, 2, (this->width()-4), 16);

    this->addInputPort("DATA");
}

DigitalIndicator8Bit::~DigitalIndicator8Bit()
{
    delete label;
}

void DigitalIndicator8Bit::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);

    painter.setBrush(QColor(0,64,0,255));
    painter.setPen(QPen(QColor(32,128,32,255),2));
    painter.drawRoundRect(6, 26, this->width()-12, this->height()-(12+26),3,3);

    painter.setFont(QFont("Times", 16));
    painter.setPen(QPen(QColor(64,192,64,255),2));

    painter.drawText(QRect(4,38, this->width()-8, 36),Qt::AlignCenter,getSymbols());
}

QString DigitalIndicator8Bit::getSymbols()
{
    uint result = getPortValue("DATA");
    char ar[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    if(result >= 256)
    {
        result = result % 256;
    }

    return QString("%1%2").arg(ar[result>>4]).arg(ar[0b00001111&result]);
}

void DigitalIndicator8Bit::onInputUpdated(QString pinName)
{
    emit repaint();
}


