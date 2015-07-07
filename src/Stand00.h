#ifndef STAND00_H
#define STAND00_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>

#include <DTrigger.h>
#include <RSTrigger.h>
#include <ClockGenerator.h>
#include <UmTumblerWidget.h>
#include <UmLedWidget.h>
#include <UmButton.h>
#include <JKTrigger.h>
#include <TTrigger.h>

namespace Ui {
class Stand00;
}

class Stand00 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stand00(QWidget *parent = 0);
    ~Stand00();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_buttonHelp_clicked();

private:
    Ui::Stand00 *ui;

    DTrigger *dTriggerFirst;
    DTrigger *dTriggerSecond;
    RSTrigger *rsTrigger;

    UmLed *dLedFirst;
    UmLed *dLedSecond;
    UmLed *dLedFirstNot;
    UmLed *dLedSecondNot;

    UmTumbler *dInTumblerFirst;
    UmTumbler *dInTumblerSecond;
    ClockGenerator *clockGenerator;

    UmButton *jkInTumblerJ;
    UmTumbler *jkInTumblerK;

    UmButton *rsInTumblerSet;
    UmButton *rsInTumblerReset;

    UmButton *tInButton;

    UmLed *rsLed;
    UmLed *rsLedNot;

    UmLed *jkLed;
    UmLed *jkLedNot;

    UmLed *tLed;
    UmLed *tLedNot;

    JKTrigger *jkTrigger;
    TTrigger *tTrigger;

};

#endif // STAND00_H
