#ifndef GATEOR_H
#define GATEOR_H

#include "UmElement.h"
#include <QPainter>

class GateOr : public UmElement
{
    Q_OBJECT
public:
    explicit GateOr(QWidget *parent = 0, bool inversedOut = false);
    ~GateOr();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);

    bool inversedOut;
};


#endif // GATEOR_H
