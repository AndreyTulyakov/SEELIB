#ifndef ALU_H
#define ALU_H

#include "UmElement.h"
#include <QLabel>
#include <QPainter>

class ALU : public UmElement
{
public:
    ALU(QString name, int resolution, QWidget *parent = 0);
    ~ALU();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);

    bool makeArithmeticOperation(uint A, uint B, uint S, bool cn, uint *result);
    bool makeLogicOperation(uint A, uint B, uint S, bool cn, uint *result);

    QLabel* label;
    int resolution;
};

#endif // ALU_H
