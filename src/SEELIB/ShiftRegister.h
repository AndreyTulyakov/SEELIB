#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include <UmElement.h>
#include <QLabel>
#include <QPaintEvent>
#include <QToolButton>
#include "UmLedWidget.h"


#define MAX_REGISTER_SIZE 32

class ShiftRegister : public UmElement
{
    Q_OBJECT
public:

    explicit ShiftRegister(QString name,int bits_count, QWidget *parent = 0);
    ~ShiftRegister();

    void fillBitsByValue(bool value);
    bool getBitValue(int bitIndex);

    QList<UmLed*>* bits_widgets;
    QLabel* label;

    void initRegisterGraphics(int bits_count);

private:
    void paintEvent(QPaintEvent *event);
    void updateIndicators(uint D);

public slots:
    void onInputUpdated(QString pinName);
    void settingCall();

signals:
    void valueUpdated();
};

#endif // SHIFTREGISTER_H
