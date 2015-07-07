#include "OutputPin.h"

OutputPin::OutputPin(QString name, uint value)
{
    this->name = name;
    this->value = value;
}

OutputPin::~OutputPin()
{

}

void OutputPin::addSlavePin(InputPin *pin)
{
    if(pin != nullptr)
    {
        slavePins.append(pin);
        updateSlavePins();
    }
}

void OutputPin::updateSlavePins()
{
    for(QLinkedList<InputPin*>::iterator iter = slavePins.begin(); iter != slavePins.end(); ++iter)
    {
        (*iter)->setValue(this->value);
    }
}

QLinkedList<InputPin *> *OutputPin::getSlavePinsList()
{
    return &slavePins;
}

void OutputPin::removeSlavePin(InputPin *pin)
{
    slavePins.removeAll(pin);
}

QString OutputPin::getName() const
{
    return name;
}

uint OutputPin::getValue() const
{
    return value;
}

void OutputPin::setValue(uint value)
{
    this->value = value;
    updateSlavePins();
}

