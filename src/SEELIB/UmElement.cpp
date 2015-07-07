#include "UmElement.h"

#include <QDebug>

UmElement::UmElement(QString name, QWidget *parent) : QWidget(parent)
{
    this->name = name;
}

UmElement::~UmElement()
{

}

QString UmElement::getName()
{
    return name;
}

uint UmElement::getPortValue(QString portname)
{
    if(inputPorts.contains(portname))
    {
        return inputPorts.value(portname)->getValue();
    }

    if(outputPorts.contains(portname))
    {
        return outputPorts.value(portname)->getValue();
    }

    return false;
}

void UmElement::setOutputPortValue(QString portname, uint value)
{
    if(outputPorts.contains(portname))
    {
        outputPorts.value(portname)->setValue(value);
    }
    else
    {
         qDebug() << "UmElement::setOutputPortValue: portname[" << portname << "] not found!";
    }
}

void UmElement::setPositionCenter(int x, int y)
{
    setGeometry(x - geometry().width()/2,
                y - geometry().height()/2,
                geometry().width(),
                geometry().height());

}

void UmElement::connectPins(QString outputPortName, InputPin *slavePin)
{
    if(outputPorts.contains(outputPortName))
    {
        this->outputPorts.value(outputPortName)->addSlavePin(slavePin);
    }
    else
    {
        qDebug() << "UmElement::connectPins: outputPortName[" << outputPortName << "] not found!";
    }

}

InputPin *UmElement::getInputPin(QString pinName)
{
    if(inputPorts.contains(pinName))
    {
        return inputPorts.value(pinName);
    }
    else
    {
        qDebug() << "UmElement::getInputPin: port[" << pinName << "] not found!";
        return nullptr;
    }
}

void UmElement::onInputUpdated(QString pinName)
{

}

void UmElement::addInputPort(QString name)
{
    InputPin* pin = new InputPin(name);
    connect(pin, SIGNAL(valueChanged(QString)), this, SLOT(onInputUpdated(QString)));
    inputPorts.insert(name, pin);
}

void UmElement::addOutputPort(QString name, uint value)
{
    OutputPin* pin = new OutputPin(name, value);
    outputPorts.insert(name, pin);
}

