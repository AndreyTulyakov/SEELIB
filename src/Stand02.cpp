#include "Stand02.h"
#include "ui_Stand02.h"
#include <QDesktopServices>


#include "QMessageBox"

Stand02::Stand02(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stand02)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow { background-color: white }");

    operandA = new TumblerRegister("Операнд А", 8, ui->centralWidget);
    operandA->setPositionCenter(200,100);

    operandB = new TumblerRegister("Операнд B", 8, ui->centralWidget);
    operandB->setPositionCenter(200,265);

    operandFunctionCode = new TumblerRegister("Код операции F", 4, ui->centralWidget);
    operandFunctionCode->setPositionCenter(200,430);

    cnTumbler = new UmTumbler("Cn", ui->centralWidget);
    cnTumbler->setPositionCenter(435, 90);

    modeTumbler = new UmTumbler("M", ui->centralWidget);
    modeTumbler->setPositionCenter(435, 400);

    aluFirst = new ALU("АЛУ", 8, ui->centralWidget);
    aluFirst->setPositionCenter(500,250);

    ledCnPlus = new UmLed(ui->centralWidget);
    ledCnPlus->setPositionCenter(580, 325);

    digitalIndicator = new DigitalIndicator8Bit("Результат",ui->centralWidget);
    digitalIndicator->setPositionCenter(625, 225);

    // Подключение к входов-выходов

    operandA->connectPins("OUT", aluFirst->getInputPin("A"));
    operandB->connectPins("OUT", aluFirst->getInputPin("B"));
    operandFunctionCode->connectPins("OUT", aluFirst->getInputPin("S"));

    cnTumbler->connectPins("OUT", aluFirst->getInputPin("CN"));
    modeTumbler->connectPins("OUT", aluFirst->getInputPin("M"));

    aluFirst->connectPins("CN+", ledCnPlus->getInputPin("DATA"));
    aluFirst->connectPins("F", digitalIndicator->getInputPin("DATA"));
}

Stand02::~Stand02()
{
    delete ui;
}


void Stand02::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // От А Б до АЛУ
    painter.setBrush(QColor(0,128,128,255));
    painter.setPen(QPen(QColor(0,128,128,255), 4));

    // A
    painter.drawLine(350, 100, 400, 100);
    painter.drawLine(400, 100, 400, 238);
    painter.drawLine(400, 238, 480, 238);

    // B
    painter.drawLine(350, 265, 480, 265);

    // От CN M до АЛУ
    painter.setBrush(QColor(0,0,0,255));
    painter.setPen(QPen(QColor(0,0,0,255), 2));

    painter.drawLine(435, 100, 435, 205);
    painter.drawLine(435, 205, 480, 205);

    painter.drawLine(435, 390, 435, 325);
    painter.drawLine(435, 325, 480, 325);

    // От оп. кода до АЛУ
    painter.setPen(QPen(QColor(0,0,128,255), 3));
    painter.drawLine(205, 430, 400, 430);
    painter.drawLine(400, 430, 400, 295);
    painter.drawLine(400, 295, 480, 295);


    // От АЛУ на индикатор
    painter.setBrush(QColor(0,128,128,255));
    painter.setPen(QPen(QColor(0,128,128,255), 4));

    painter.drawLine(520, 225, 625, 225);

    // От АЛУ до CN+
    painter.setPen(QPen(QColor(0,0,0,255), 2));
    painter.drawLine(520, 325, 575, 325);

}

void Stand02::mousePressEvent(QMouseEvent *event)
{
   // QMessageBox::information(this, "infa", QString("X:%1  Y:%2").arg(event->localPos().x()).arg(event->localPos().y()));
}

void Stand02::on_buttonHelp_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(QApplication::applicationDirPath()+"/help.pdf"));
}
