#ifndef TUMBLERREGISTER_H
#define TUMBLERREGISTER_H

#include <UmElement.h>
#include <QLabel>
#include <QPaintEvent>
#include <QToolButton>
#include "UmTumblerWidget.h"

namespace Ui {
class TumblerRegister;
}

#define MAX_REGISTER_SIZE 32


class TumblerRegister : public UmElement
{
    Q_OBJECT

public:
    explicit TumblerRegister(QString name, int bits_count, QWidget *parent = 0);
    ~TumblerRegister();

    void fillBitsByValue(bool value);
    bool getBitValue(int bitIndex);
    void setBitValue(int bitIndex, bool value);

    int getCapacity();


private:
    void paintEvent(QPaintEvent *event);

private:
    QList<UmTumbler*>* bits_widgets;
    QLabel* label;

    void initRegisterGraphics(int bits_count);

public slots:
    void valueUpdated();
    void settingCall();

};

#endif // TUMBLERREGISTER_H
