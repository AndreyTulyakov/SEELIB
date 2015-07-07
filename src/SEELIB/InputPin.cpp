#include "InputPin.h"

InputPin::InputPin(QString name)
{
    this->name = name;
    this->value = false;
}

InputPin::~InputPin()
{

}

QString InputPin::getName() const
{
    return name;
}

uint InputPin::getValue() const
{
    return value;
}

void InputPin::setValue(uint value)
{
    this->value = value;
    emit valueChanged(name);
}




