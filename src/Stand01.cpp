#include "Stand01.h"
#include "ui_Stand01.h"
#include <QDesktopServices>
#include <QMessageBox>


Stand01::Stand01(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stand01)
{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow { background-color: white }");

    registerT = new TumblerRegister("Блок тумблеров", 4, ui->centralWidget);
    registerT->setPositionCenter(150,210);

    registerA = new ShiftRegister("RGA", 4, ui->centralWidget);
    registerA->setPositionCenter(450, 315);

    S0Tumbler = new UmTumbler("S0", ui->centralWidget);
    S0Tumbler->setPositionCenter(290, 480);

    S1Tumbler = new UmTumbler("S1", ui->centralWidget);
    S1Tumbler->setPositionCenter(350, 480);

    SLTumbler = new UmTumbler("SL", ui->centralWidget);
    SLTumbler->setPositionCenter(350, 125);

    SRTumbler = new UmTumbler("SR", ui->centralWidget);
    SRTumbler->setPositionCenter(290, 125);

    mrButton = new UmButton("MR", ui->centralWidget);
    mrButton->setPositionCenter(210, 390);

    clockGenerator = new ClockGenerator("Тактовый генератор", 1000, ui->centralWidget);
    clockGenerator->setPositionCenter(150,300);

    indicatorA = new DigitalIndicator4Bit("Индикатор А", ui->centralWidget);
    indicatorA->setPositionCenter(600,200);


    // Подключение проводов
    clockGenerator->connectPins("CLK", registerA->getInputPin("CLK"));
    registerT->connectPins("OUT", registerA->getInputPin("D"));

    S0Tumbler->connectPins("OUT", registerA->getInputPin("S0"));
    S1Tumbler->connectPins("OUT", registerA->getInputPin("S1"));

    SLTumbler->connectPins("OUT", registerA->getInputPin("SL"));
    SRTumbler->connectPins("OUT", registerA->getInputPin("SR"));

    mrButton->connectPins("OUT", registerA->getInputPin("MR"));

    registerA->connectPins("Q", indicatorA->getInputPin("DATA"));

}

Stand01::~Stand01()
{
    delete registerT;

    delete registerA;

    delete S0Tumbler;
    delete S1Tumbler;

    delete ui;
}

void Stand01::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // От тумблерного регистра до регистров
    painter.setBrush(QColor(0,128,128,255));
    painter.setPen(QPen(QColor(0,128,128,255), 4));

    painter.drawLine(200,212, 450, 212);


    // От регистров до индикаторов
    painter.setBrush(QColor(0,128,0,255));
    painter.setPen(QPen(QColor(0,128,0,255), 4));

    painter.drawLine(450, 210, 600, 210);


    // От S0 S1 до регистра
    painter.setBrush(QColor(0,0,0,255));
    painter.setPen(QPen(QColor(0,0,0,255), 2));

    painter.drawLine(290, 480, 290, 330);
    painter.drawLine(290, 330, 450, 330);

    painter.drawLine(350, 480, 350, 360);
    painter.drawLine(350, 360, 450, 360);

    // От SL, SR до регистра
    painter.drawLine(290, 125, 290, 270);
    painter.drawLine(290, 270, 450, 270);

    painter.drawLine(350, 125, 350, 240);
    painter.drawLine(350, 240, 450, 240);

    // От Clock Generator до регистров
    painter.setBrush(QColor(0,0,128,255));
    painter.setPen(QPen(QColor(0,0,128,255), 2));

    painter.drawLine(150, 300, 450, 300);
    painter.drawLine(210, 390, 450, 390);
}

void Stand01::mousePressEvent(QMouseEvent *event)
{
   //QMessageBox::information(this, "infa", QString("X:%1  Y:%2").arg(event->localPos().x()).arg(event->localPos().y()));
}

void Stand01::on_buttonHelp_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(QApplication::applicationDirPath()+"/help.pdf"));
}
