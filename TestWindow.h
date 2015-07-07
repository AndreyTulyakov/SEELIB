#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include "RSTrigger.h"
#include "JKTrigger.h"
#include "TTrigger.h"
#include "UmTumblerWidget.h"
#include "UmButton.h"
#include "UmLedWidget.h"
#include "DigitalIndicator4Bit.h"
#include "DigitalIndicator8Bit.h"
#include "GateAnd.h"
#include "GateOr.h"
#include "GateNot.h"

#include "Summator.h"

namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();

private:
    Ui::TestWindow *ui;


    Summator* sum;
    GateAnd* andGate;
    GateOr* orGate;
    GateNot* notGate;

    void paintEvent(QPaintEvent *event);
};

#endif // TESTWINDOW_H
