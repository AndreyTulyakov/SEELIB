#include "ClockGenerator.h"
#include <QPainter>

ClockGenerator::ClockGenerator(QString name, int tickPeriod, QWidget *parent) : UmElement(name, parent)
{
    setFixedWidth(160);
    setFixedHeight(80);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Times", 10));
    label->setGeometry(2, 2, (this->width()-4), 16);

    dial = new QDial(this);
    dial->setMinimum(0);
    dial->setMaximum(10);
    dial->setGeometry(16, 26 ,40,40);

    hzIndicator = new QLabel(this);
    hzIndicator->setText("");
    hzIndicator->setAlignment(Qt::AlignCenter);
    hzIndicator->setFont(QFont("Times", 10));
    hzIndicator->setGeometry(70, 36, 50, 20);

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTick()));
    connect(dial, SIGNAL(valueChanged(int)), this, SLOT(onHzChange(int)));
    onHzChange(dial->value());

    addOutputPort("CLK", false);

    tick = false;
}

ClockGenerator::~ClockGenerator()
{
    delete label;
}

void ClockGenerator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);

    if(tick)
    {
        painter.setBrush(QColor(128,128,255,255));
    }
    else
    {
        painter.setBrush(QColor(0,0,32,255));
    }

    painter.drawRect(this->width() - 24, 32 ,20,20);
}

void ClockGenerator::onTick()
{
    tick = !tick;
    emit repaint();
    setOutputPortValue("CLK", tick);
}

void ClockGenerator::onHzChange(int value)
{
    if(value == 0)
    {
        timer.stop();
    } else {
        timer.start(1000.0f * (1.0f/value));
    }

    hzIndicator->setText(QString("%1 Гц").arg(value/2.0f));
}

