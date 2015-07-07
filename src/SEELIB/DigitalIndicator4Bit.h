#ifndef DIGITALINDICATOR4BIT_H
#define DIGITALINDICATOR4BIT_H

#include "UmElement.h"
#include <QLabel>
#include <QPainter>

class DigitalIndicator4Bit : public UmElement
{
public:
    DigitalIndicator4Bit(QString name, QWidget* parent);
    ~DigitalIndicator4Bit();

protected:
    void paintEvent(QPaintEvent *event);
    char getSymbol();

    QLabel* label;

public slots:
    void onInputUpdated(QString pinName);
};

#endif // DIGITALINDICATOR4BIT_H
