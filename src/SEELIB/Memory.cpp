#include "Memory.h"
#include "math.h"

Memory::Memory(QString name, int inputPins, int ouputPins, QWidget *parent) : UmElement(name, parent)
{
    this->wordSize = ouputPins;
    this->wordCount = pow(2,inputPins);
    data = new bool[wordSize*wordCount];

    this->setGeometry(this->x(),this->y(), 80 , 160);

    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 16);

}

Memory::~Memory()
{
    delete data;
}


bool Memory::getValue(int wordNumber, int byteNumber)
{
    return data[wordNumber*wordSize+byteNumber];
}

void Memory::setValue(int wordNumber, int byteNumber, bool value)
{
    data[wordNumber*wordSize+byteNumber] = value;
}

bool Memory::getValue(int offset)
{
    return data[offset];
}

void Memory::setValue(int offset, bool value)
{
    data[offset] = value;
}


void Memory::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(0, 0, this->width()-1, this->height()-1);
    painter.drawLine(0,42, this->width(), 42);
}
