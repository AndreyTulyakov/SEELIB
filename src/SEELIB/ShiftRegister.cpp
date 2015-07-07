#include "ShiftRegister.h"
#include <QDebug>
#include <QPainter>
#include <QMessageBox>

ShiftRegister::ShiftRegister(QString name, int bits_count, QWidget *parent) : UmElement(name, parent)
{
    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Times", 10));

    if(bits_count > 0 && bits_count < MAX_REGISTER_SIZE)
    {
        // Создаем виджеты в зависимости от размера регистра
        initRegisterGraphics(bits_count);

        // Заполняем биты нулями
        fillBitsByValue(false);
    }
    else
    {
        qDebug() << "ShiftRegister(...): bad bits count\n";
    }

    addInputPort("MR"); // Очистка
    addInputPort("SL"); // Входной бит при сдвиге влево
    addInputPort("SR"); // Входной бит при сдвиге вправо
    addInputPort("CLK"); // Синхровход
    addInputPort("D"); // Данные вход
    addInputPort("S0");  // Задание режима работы
    addInputPort("S1");  // Задание режима работы

    addOutputPort("Q", 0);

}

ShiftRegister::~ShiftRegister()
{
    for(int index = 0; index < bits_widgets->size(); index++)
    {
       delete bits_widgets->at(index);
    }
    delete label;
}

void ShiftRegister::fillBitsByValue(bool value)
{
    for(int index = 0; index < bits_widgets->size(); index++)
    {
        UmLed *currentWidget = bits_widgets->at(index);
        currentWidget->getInputPin("DATA")->setValue(value);
    }
}

bool ShiftRegister::getBitValue(int bitIndex)
{
    if(bitIndex > 0 && bitIndex < bits_widgets->size())
    {
        UmLed *currentWidget = bits_widgets->at(bitIndex);
        return currentWidget->getInputPin("DATA")->getValue();
    }
    return false;
}


void ShiftRegister::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,10,10);
    painter.drawLine(0,24, this->width(), 24);

    painter.drawLine(29, 24, 29, this->height());
    painter.drawLine(this->width() - 26, 24, this->width() - 26, this->height());

    painter.setPen(Qt::black);
    painter.drawText(10, 40, "D");
    painter.drawText(8, 70,  "SL");
    painter.drawText(8, 100,  "SR");
    painter.drawText(6, 130, "CLK");
    painter.drawText(8, 160,  "S0");
    painter.drawText(8, 190,  "S1");
    painter.drawText(8, 220,  "MR");

    painter.drawText(this->width() - 18, 40, "Q");
}

void ShiftRegister::updateIndicators(uint D)
{
    int bitCount = bits_widgets->size();

    for(int i=0; i < bitCount; i++)
    {
        uint mask = 1 << i;
        bool value = D & mask;
        bits_widgets->at(i)->getInputPin("DATA")->setValue(value);
    }
    setOutputPortValue("Q", D);
}

void ShiftRegister::onInputUpdated(QString pinName)
{
    uint D  = getInputPin("D")->getValue();
    uint Q = getPortValue("Q");
    bool S0 = getInputPin("S0")->getValue();
    bool S1 = getInputPin("S1")->getValue();
    bool SL = getInputPin("SL")->getValue();
    bool SR = getInputPin("SR")->getValue();
    bool MR = getInputPin("MR")->getValue();
    bool CLK = getInputPin("CLK")->getValue();


    // Если очистка
    if(MR)
    {
        for(int i=0; i<bits_widgets->size(); i++)
        {
            bits_widgets->at(i)->getInputPin("DATA")->setValue(false);
        }
        setOutputPortValue("Q", 0);
    }
    else
    {

        if(CLK && pinName == "CLK")
        {
            // Блокировка
            if(S0 == false && S1 == false)
            {
                // None

            }

            // Сдвиг влево
            if(S0 == true && S1 == false)
            {

                uint value = Q >> 1;
                if(SR)
                {
                    value = value | (1 << (sizeof(uint)-1));
                }

                updateIndicators(value);
            }

            // Сдвиг вправо
            if(S0 == false && S1 == true)
            {
                uint mask = 1;

                // Подготовка правильной маски типа b00001111
                for(int i=1; i < bits_widgets->size(); i++)
                {
                    mask = mask << 1;
                    mask |= 1;
                }

                uint value = Q << 1;

                if(SL)
                {
                    value = value | 1;
                }

                value &= mask;

                uint overValue = pow(2,bits_widgets->size())-1;

                if(value > overValue)
                    value = overValue;

                updateIndicators(value);
            }

            // Параллельная загрузка
            if(S0 == true && S1 == true)
            {

                updateIndicators(D);
            }
        }

    }

    emit valueUpdated();
}

void ShiftRegister::initRegisterGraphics(int bits_count)
{
    // Создаем список указателей на виджеты
    bits_widgets = new QList<UmLed*>();

    int tumblerSize = 16;
    float separationSpace = 10;

    int totalHeight = 24 + bits_count * (tumblerSize+separationSpace) - separationSpace;

    this->setGeometry(this->x(),this->y(), 116 , 280);//totalHeight+4);
    label->setGeometry(2, 2, (this->width()-4), 16);

    for(int index = 0; index < bits_count; index++)
    {
        // Создаем виджет
        UmLed *currentWidget = new UmLed(this);
        currentWidget->setGeometry(60, 28 + 30 * index, tumblerSize, tumblerSize);

        // Добавляем в список

        QLabel *currentLabel = new QLabel(QString("%1").arg(index),this);
        currentLabel->setGeometry(38, 27 + 30 * index, tumblerSize-1, 16);
        currentLabel->setAlignment(Qt::AlignCenter);

        bits_widgets->append(currentWidget);
    }
}

void ShiftRegister::settingCall()
{
    QMessageBox::information(this, "Настройка регистра", name + ": Пока не реализовано!");
}

