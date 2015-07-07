#include "Stand00.h"
#include "ui_Stand00.h"

#include <QDesktopServices>

Stand00::Stand00(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stand00)
{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow { background-color: white }");

    // Part 1
    dInTumblerFirst = new UmTumbler("Вх.1", ui->centralwidget);
    dInTumblerFirst->setPositionCenter(150,85);

    dInTumblerSecond = new UmTumbler("Вх.2", ui->centralwidget);
    dInTumblerSecond->setPositionCenter(150,185);

    dTriggerFirst = new DTrigger("D-Триггер 1", ui->centralwidget);
    dTriggerFirst->setPositionCenter(300,100);

    dTriggerSecond = new DTrigger("D-Триггер 2", ui->centralwidget);
    dTriggerSecond->setPositionCenter(300,200);

    dLedFirst = new UmLed(ui->centralwidget);
    dLedFirst->setPositionCenter(400, 95);

    dLedSecond = new UmLed(ui->centralwidget);
    dLedSecond->setPositionCenter(400, 195);


    dLedFirstNot = new UmLed(ui->centralwidget);
    dLedFirstNot->setPositionCenter(400, 125);

    dLedSecondNot = new UmLed(ui->centralwidget);
    dLedSecondNot->setPositionCenter(400, 225);

    clockGenerator = new ClockGenerator("Тактовый генератор", 500, ui->centralwidget);
    clockGenerator->setPositionCenter(120,315);

    // Part 2
    rsTrigger = new RSTrigger("RS-Триггер",ui->centralwidget);
    rsTrigger->setPositionCenter(300,500);

    rsInTumblerSet = new UmButton("Set", ui->centralwidget);
    rsInTumblerSet->setPositionCenter(150, 460);

    rsInTumblerReset = new UmButton("Reset", ui->centralwidget);
    rsInTumblerReset->setPositionCenter(150, 540);

    rsLed = new UmLed(ui->centralwidget);
    rsLed->setPositionCenter(400, 495);

    rsLedNot = new UmLed(ui->centralwidget);
    rsLedNot->setPositionCenter(400, 525);

    // Part 3 JK
    jkTrigger = new JKTrigger("JK-Триггер", ui->centralwidget);
    jkTrigger->setPositionCenter(650, 150);

    jkInTumblerJ = new UmButton("J", ui->centralwidget);
    jkInTumblerJ->setPositionCenter(520, 80);

    jkInTumblerK = new UmTumbler("K", ui->centralwidget);
    jkInTumblerK->setPositionCenter(520, 150);

    jkLed = new UmLed(ui->centralwidget);
    jkLed->setPositionCenter(750, 130);

    jkLedNot = new UmLed(ui->centralwidget);
    jkLedNot->setPositionCenter(750, 160);

    // T
    tTrigger = new TTrigger("T-Триггер", ui->centralwidget);
    tTrigger->setPositionCenter(650, 500);

    tInButton = new UmButton("T", ui->centralwidget);
    tInButton->setPositionCenter(550, 400);

    tLed = new UmLed(ui->centralwidget);
    tLed->setPositionCenter(750, 495);

    tLedNot = new UmLed(ui->centralwidget);
    tLedNot->setPositionCenter(750, 525);

    // Подключение проводов
    // Part 1
    dInTumblerFirst->connectPins("OUT", dTriggerFirst->getInputPin("D"));
    dInTumblerSecond->connectPins("OUT", dTriggerSecond->getInputPin("D"));

    clockGenerator->connectPins("CLK", dTriggerFirst->getInputPin("CLK"));
    clockGenerator->connectPins("CLK", dTriggerSecond->getInputPin("CLK"));

    dTriggerFirst->connectPins("Q", dLedFirst->getInputPin("DATA"));
    dTriggerSecond->connectPins("Q", dLedSecond->getInputPin("DATA"));

    dTriggerFirst->connectPins("!Q", dLedFirstNot->getInputPin("DATA"));
    dTriggerSecond->connectPins("!Q", dLedSecondNot->getInputPin("DATA"));

    // Part 2
    rsInTumblerSet->connectPins("OUT", rsTrigger->getInputPin("S"));
    rsInTumblerReset->connectPins("OUT", rsTrigger->getInputPin("R"));
    rsTrigger->connectPins("Q", rsLed->getInputPin("DATA"));
    rsTrigger->connectPins("!Q", rsLedNot->getInputPin("DATA"));

    // Part JK T
    jkInTumblerK->connectPins("OUT", jkTrigger->getInputPin("K"));
    jkInTumblerJ->connectPins("OUT", jkTrigger->getInputPin("J"));
    clockGenerator->connectPins("CLK", jkTrigger->getInputPin("CLK"));
    jkTrigger->connectPins("Q", jkLed->getInputPin("DATA"));
    jkTrigger->connectPins("!Q", jkLedNot->getInputPin("DATA"));

    tInButton->connectPins("OUT", tTrigger->getInputPin("T"));
    clockGenerator->connectPins("CLK", tTrigger->getInputPin("CLK"));
    tTrigger->connectPins("Q", tLed->getInputPin("DATA"));
    tTrigger->connectPins("!Q", tLedNot->getInputPin("DATA"));


}

Stand00::~Stand00()
{
    delete dTriggerFirst;
    delete dTriggerSecond;
    delete ui;
}

void Stand00::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // От D-тригера до светодиодов
    painter.setBrush(QColor(0,0,0,255));
    painter.setPen(QPen(QColor(0,0,0,255), 2));

    painter.drawLine(300,  95, 395, 95);
    painter.drawLine(300, 125, 395, 125);

    painter.drawLine(300, 195, 395, 195);
    painter.drawLine(300, 225, 395, 225);

    // От тумблеров вх1-2 до D-триггеров
    painter.setPen(QPen(QColor(0,128,0,255), 2));

    painter.drawLine(150,95, 300, 95);
    painter.drawLine(150,195, 300, 195);

    // Такт-ген до D-триггеров
    painter.setPen(QPen(QColor(0,0,128,255), 2));

    painter.drawLine(150, 315, 480, 315);
    painter.drawLine(230, 315, 230, 125);

    painter.drawLine(230, 125, 300, 125);
    painter.drawLine(230, 225, 300, 225);

    painter.drawLine(480, 190, 480, 525);

    painter.drawLine(480, 190, 640, 190);
    painter.drawLine(480, 525, 640, 525);

    // От кнопок до RS триггера
    painter.setPen(QPen(QColor(0,128,0,255), 2));

    // Set butoon
    painter.drawLine(160, 470, 215, 470);
    painter.drawLine(215, 470, 215, 495);
    painter.drawLine(215, 495, 270, 495);

    // Reset button
    painter.drawLine(160, 550, 215, 550);
    painter.drawLine(215, 550, 215, 525);
    painter.drawLine(215, 525, 270, 525);

    // От кнопок до JK триггера
    painter.drawLine(520, 90, 570, 90); // J
    painter.drawLine(570, 90, 570, 130);
    painter.drawLine(570, 130, 640, 130);

    painter.drawLine(520, 160, 640, 160); // K

    // От кнопок до Т триггера
    painter.drawLine(550, 400, 550, 495); // T
    painter.drawLine(550, 495, 640, 495);


    // От RS-тригера до светодиодов
    painter.setBrush(QColor(0,0,0,255));
    painter.setPen(QPen(QColor(0,0,0,255), 2));

    painter.drawLine(300, 495, 395, 495);
    painter.drawLine(300, 525, 395, 525);

    // От JK и T до светодиодов
    painter.drawLine(660, 130, 745, 130);
    painter.drawLine(660, 160, 745, 160);

    painter.drawLine(660, 495, 745, 495);
    painter.drawLine(660, 525, 745, 525);

}

void Stand00::on_buttonHelp_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(QApplication::applicationDirPath()+"/help.pdf"));
}
