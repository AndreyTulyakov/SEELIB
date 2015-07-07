#ifndef GATEAND_H
#define GATEAND_H

#include "UmElement.h"
#include <QPainter>

class GateAnd : public UmElement
{
    Q_OBJECT
public:
    explicit GateAnd(QWidget *parent = 0, bool inversedOut = false);
    ~GateAnd();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);

    bool inversedOut;
};

#endif // GATEAND_H
