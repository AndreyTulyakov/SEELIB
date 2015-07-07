#include "ALU.h"
#include "math.h"
#include <QDebug>

ALU::ALU(QString name, int resolution, QWidget *parent) : UmElement(name, parent)
{
    this->setGeometry(this->x(),this->y(), 80 , 200);
    this->resolution = resolution;
    this->setToolTip("Арифметико-логическое устройство");

    label = new QLabel(this);
    label->setText(name + QString("\n%1-bit").arg(resolution));
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(2, 2, this->width()-4, 32);

    addInputPort("CN");
    addInputPort("A");
    addInputPort("B");
    addInputPort("S");
    addInputPort("M");

    addOutputPort("F", false);
    addOutputPort("CN+", false);

}

ALU::~ALU()
{

}

void ALU::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    painter.drawLine(0,36, this->width(), 36);

    painter.setPen(Qt::black);
    painter.drawText(10, 60, "Cn");
    painter.drawText(10, 90,  "A");
    painter.drawText(10, 120, "B");
    painter.drawText(10, 150, "S");
    painter.drawText(10, 180, "М");

    painter.drawText(60, 80, "F");
    painter.drawText(50, 180, "Cn+");
}

void ALU::onInputUpdated(QString pinName)
{

    uint a = getPortValue("A");
    uint b = getPortValue("B");
    uint opcode = getPortValue("S");
    bool cn = getPortValue("CN");
    bool mode = getPortValue("M");

    uint result = 0;
    bool cnPlus = false;

    if(mode == true)
    {
        cnPlus = makeLogicOperation(a,b,opcode,cn, &result);
    }
    else
    {
        cnPlus = makeArithmeticOperation(a,b,opcode,cn, &result);
    }

    setOutputPortValue("F", result);
    setOutputPortValue("CN+", cnPlus);
}

bool ALU::makeArithmeticOperation(uint A, uint B, uint S, bool cn, uint* result)
{
    unsigned int f;

    switch(S)
    {
    case 0:
        f = A;
        break;

    case 1:
        f = A | B;
        break;

    case 2:
        f = A | (~B);
        break;

    case 3:
        f = ~0;
        break;

    case 4:
        f = A + (A&(~B));
        break;

    case 5:
        f = (A | B) + (A&(~B));
        break;

    case 6:
        f = A - B - 1;
        break;

    case 7:
        f = (A & (~B)) - 1;
        break;

    case 8:
        f = A + (A&B);
        break;

    case 9:
        f = A + B;
        break;

    case 10:
        f = (A | (~B)) + (A&B);
        break;

    case 11:
        f = (A & B) - 1;
        break;

    case 12:
        f = A + A;
        break;

    case 13:
        f = (A | B)+ A;
        break;

    case 14:
        f = (A | (~B))+ A;
        break;

    case 15:
        f = A - 1;
        break;
    }

    f = f + (cn ? 1:0);
    *result = (uint)f;

    if(f > (pow(2,resolution) - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ALU::makeLogicOperation(uint A, uint B, uint S, bool cn, uint* result)
{
    switch(S)
    {
    case 0: // !A
        *result = ~A;
        break;

    case 1:
        *result = ~(A|B);
        break;

    case 2:
        *result = (~A)&B;
        break;

    case 3:
        *result = 0;
        break;

    case 4:
        *result = ~(A&B);
        break;

    case 5:
        *result = ~B;
        break;

    case 6: // Сложение по модулю 2
        *result = A^B;
        break;

    case 7:
        *result = A&(~B);
        break;

    case 8:
        *result = (~A) | B;
        break;

    case 9:
        *result = ~(A^B);
        break;

    case 10:
        *result = B;
        break;

    case 11:
        *result = A&B;
        break;

    case 12:
        *result = ~0;
        break;

    case 13:
        *result = A | (~B);
        break;

    case 14:
        *result = A | B;
        break;

    case 15:
        *result = A;
        break;
    }

    return false;
}

