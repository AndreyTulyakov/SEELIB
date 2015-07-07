#include "StendSelectionDialog.h"
#include "ui_StendSelectionDialog.h"

#include "Stand00.h"
#include "Stand01.h"
#include "Stand02.h"
#include "TestWindow.h"

StendSelectionDialog::StendSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StendSelectionDialog)
{
    ui->setupUi(this);
    window = nullptr;
}

StendSelectionDialog::~StendSelectionDialog()
{
    if(window != nullptr)
    {
        delete window;
        window = nullptr;
    }
    delete ui;
}

void StendSelectionDialog::on_buttonBox_accepted()
{
    if(window != nullptr)
    {
        delete window;
        window = nullptr;
    }

    switch(ui->comboBox->currentIndex())
    {
    case 0:
        window = new Stand00();
        break;
    case 1:
        window = new Stand01();
        break;
    case 2:
        window = new Stand02();
        break;
    case 3:
        window = new TestWindow();
        break;
    }

    window->show();
    this->close();
}

void StendSelectionDialog::onStandHide()
{

}
