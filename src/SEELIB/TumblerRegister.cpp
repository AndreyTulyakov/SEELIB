#include "TumblerRegister.h"
#include <QDebug>
#include <QLine>
#include <QPainter>
#include <QMessageBox>

TumblerRegister::TumblerRegister(QString name, int bits_count, QWidget *parent) : UmElement(name, parent)
{
    label = new QLabel(this);
    label->setText(name);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Times", 10));

    addOutputPort("OUT", 0);

    if(bits_count > 0 && bits_count < MAX_REGISTER_SIZE)
    {
        // Создаем виджеты в зависимости от размера регистра
        initRegisterGraphics(bits_count);

        // Заполняем биты нулями
        fillBitsByValue(false);
    }
    else
    {
        qDebug() << "TumblerRegister(...): bad bits count\n";
    }


}

TumblerRegister::~TumblerRegister()
{
    for(int index = 0; index < bits_widgets->size(); index++)
    {
       delete bits_widgets->at(index);
    }
    delete label;
}

void TumblerRegister::fillBitsByValue(bool value)
{
    for(int index = 0; index < bits_widgets->size(); index++)
    {
        UmTumbler *currentWidget = bits_widgets->at(index);
        currentWidget->setChecked(value);
    }
}

bool TumblerRegister::getBitValue(int bitIndex)
{
    if(bitIndex > 0 && bitIndex < bits_widgets->size())
    {
        UmTumbler *currentWidget = bits_widgets->at(bitIndex);
        return currentWidget->isChecked();
    }
    return false;
}

void TumblerRegister::setBitValue(int bitIndex, bool value)
{
    if(bitIndex > 0 && bitIndex < bits_widgets->size())
    {
        UmTumbler *currentWidget = bits_widgets->at(bitIndex);
        return currentWidget->setChecked(value);
    }
}

int TumblerRegister::getCapacity()
{
    return bits_widgets->size();
}

void TumblerRegister::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(210,210,210,255));
    painter.setPen(Qt::lightGray);
    painter.drawRoundRect(0, 0, this->width()-1, this->height()-1,5,5);
    //painter.drawRect(0, 0, this->width()-1, this->height()-1);
    painter.drawLine(0,42, this->width(), 42);
}

void TumblerRegister::initRegisterGraphics(int bits_count)
{
    // Создаем список указателей на виджеты
    bits_widgets = new QList<UmTumbler*>();

    int tumblerSize = 32;
    float separationSpace = 10;

    int total_height = bits_count * (tumblerSize+separationSpace) - separationSpace;

    this->setGeometry(this->x(),this->y(), total_height+4, 81);
    label->setGeometry(2, 2, (this->width()-4), 16);

    for(int index = 0; index < bits_count; index++)
    {

        int backIndex = (bits_count - 1) - index;
        // Создаем виджет
        UmTumbler *currentWidget = new UmTumbler(this);
        currentWidget->setGeometry(1 + (separationSpace+tumblerSize)*backIndex, 48, 32, 32);

        // Добавляем в список

        QLabel *currentLabel = new QLabel(QString("[%1]").arg(index),this);
        currentLabel->setGeometry(1 + (separationSpace+tumblerSize)*backIndex, 24, 30, 16);
        currentLabel->setAlignment(Qt::AlignCenter);

        bits_widgets->append(currentWidget);
        // Добавляем на форму
        //ui->verticalLayout->addWidget(currentWidget);


        connect(currentWidget, SIGNAL(stateChanged()), this, SLOT(valueUpdated(void)));
    }
}

void TumblerRegister::valueUpdated()
{
    uint value = 0;

    for(int index = 0; index < bits_widgets->size(); index++)
    {
        uint ed = 1;
        uint mask = ed << index;

        if(bits_widgets->at(index)->isChecked())
        {
            value = value | mask;
        }
    }

    setOutputPortValue("OUT", value);
}

void TumblerRegister::settingCall()
{
    QMessageBox::information(this, "Настройка регистра", name + ": Пока не реализовано!");
}
