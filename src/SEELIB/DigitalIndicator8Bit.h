#ifndef DIGITALINDICATOR8BIT_H
#define DIGITALINDICATOR8BIT_H

#include "UmElement.h"
#include <QLabel>
#include <QPainter>

class DigitalIndicator8Bit : public UmElement
{
public:
    DigitalIndicator8Bit(QString name, QWidget* parent);
    ~DigitalIndicator8Bit();

protected:
    void paintEvent(QPaintEvent *event);
    QString getSymbols();

    QLabel* label;

public slots:
    void onInputUpdated(QString pinName);
};


#endif // DIGITALINDICATOR8BIT_H
