#ifndef GATENOT_H
#define GATENOT_H

#include "UmElement.h"
#include <QPainter>

class GateNot : public UmElement
{
    Q_OBJECT
public:
    explicit GateNot(QWidget *parent = 0);
    ~GateNot();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);
};



#endif // GATENOT_H
