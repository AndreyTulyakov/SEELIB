#ifndef OUPUTPIN_H
#define OUPUTPIN_H

#include <QLinkedList>
#include "InputPin.h"

class OutputPin
{
public:
    OutputPin(QString name, uint value = false);
    ~OutputPin();

    void addSlavePin(InputPin* pin);
    void updateSlavePins();
    QLinkedList<InputPin*>* getSlavePinsList();
    void removeSlavePin(InputPin* pin);

    QString getName() const;

    uint getValue() const;
    void setValue(uint value);

private:
    QString name;
    uint value;
    QLinkedList<InputPin*> slavePins;
};

#endif // OUPUTPIN_H
