#ifndef INPUTPIN_H
#define INPUTPIN_H

#include <QString>
#include <QObject>

class InputPin : public QObject
{
    Q_OBJECT

public:
    InputPin(QString name);
    ~InputPin();

    QString getName() const;

    uint getValue() const;
    void setValue(uint value);

signals:
    valueChanged(QString name);

private:
    QString name;
    uint value;
};

#endif // INPUTPIN_H
