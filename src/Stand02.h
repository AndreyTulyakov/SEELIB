#ifndef STAND02_H
#define STAND02_H

#include <QMainWindow>
#include <QPainter>
#include "TumblerRegister.h"
#include "ALU.h"
#include "UmLedWidget.h"
#include "DigitalIndicator8Bit.h"

namespace Ui {
class Stand02;
}

class Stand02 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stand02(QWidget *parent = 0);
    ~Stand02();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_buttonHelp_clicked();

private:
    Ui::Stand02 *ui;

    TumblerRegister *operandA;
    TumblerRegister *operandB;
    TumblerRegister *operandFunctionCode;
    ALU *aluFirst;
    ALU *aluSecond;
    DigitalIndicator8Bit *digitalIndicator;

    UmLed *ledCnPlus;

    UmTumbler *cnTumbler;
    UmTumbler *modeTumbler;
};

#endif // STAND02_H
