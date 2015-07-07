#include "TestWindow.h"
#include "ui_TestWindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);

    sum = new Summator("S1", ui->centralwidget);
    sum->setPositionCenter(200, 200);

    andGate = new GateAnd(ui->centralwidget, false);
    andGate->setPositionCenter(400,200);

    orGate = new GateOr(ui->centralwidget, false);
    orGate->setPositionCenter(200,400);

    notGate = new GateNot(ui->centralwidget);
    notGate->setPositionCenter(400,400);
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);

    painter.drawText(150, 120, "Полный сумматор");
    painter.drawText(170, 340, "Элемент ИЛИ");
    painter.drawText(370, 140, "Элемент И");
    painter.drawText(370, 340, "Элемент НЕ");
}
