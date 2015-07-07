#ifndef UMELEMENT_H
#define UMELEMENT_H

#include <QWidget>
#include <QMap>
#include <QString>

#include <InputPin.h>
#include <OutputPin.h>

class UmElement : public QWidget
{
    Q_OBJECT
public:
    explicit UmElement(QString name, QWidget *parent = 0);
    ~UmElement();

    QString getName();


    uint getPortValue(QString portname);
    void setOutputPortValue(QString portname, uint value);

    void setPositionCenter(int x, int y);
    void connectPins(QString outputPortName, InputPin* slavePin);
    InputPin* getInputPin(QString pinName);

protected:
    void addInputPort(QString name);
    void addOutputPort(QString name, uint value = false);


protected:
    QString name;
    QMap<QString,InputPin*> inputPorts;
    QMap<QString,OutputPin*> outputPorts;

signals:

public slots:
    virtual void onInputUpdated(QString pinName);

};

#endif // UMELEMENT_H
