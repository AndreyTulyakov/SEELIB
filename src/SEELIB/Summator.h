#ifndef SUMMATOR_H
#define SUMMATOR_H

#include "UmElement.h"
#include <QLabel>
#include <QPainter>

class Summator : public UmElement
{
public:
    Summator(QString name, QWidget *parent = 0);
    ~Summator();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);

    QLabel* label;
};

#endif // SUMMATOR_H
