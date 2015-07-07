#ifndef STAND01_H
#define STAND01_H

#include <QMainWindow>
#include "TumblerRegister.h"
#include "ShiftRegister.h"
#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QToolButton>
#include "DTrigger.h"
#include "Memory.h"
#include "ALU.h"
#include "QSvgRenderer"
#include "ClockGenerator.h"
#include "DigitalIndicator4Bit.h"
#include "UmButton.h"

namespace Ui {
class Stand01;
}

class Stand01 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stand01(QWidget *parent = 0);
    ~Stand01();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_buttonHelp_clicked();

private:
    Ui::Stand01 *ui;

    TumblerRegister *registerT;
    ShiftRegister *registerA;
    UmTumbler *S0Tumbler;
    UmTumbler *S1Tumbler;
    UmTumbler *SLTumbler;
    UmTumbler *SRTumbler;
    UmButton *mrButton;

    ClockGenerator *clockGenerator;
    DigitalIndicator4Bit *indicatorA;
};

#endif // STAND01_H
