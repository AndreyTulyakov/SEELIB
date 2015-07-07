#ifndef STENDSELECTIONDIALOG_H
#define STENDSELECTIONDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class StendSelectionDialog;
}

class StendSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StendSelectionDialog(QWidget *parent = 0);
    ~StendSelectionDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::StendSelectionDialog *ui;

    QMainWindow* window;

public slots:
    void onStandHide();
};

#endif // STENDSELECTIONDIALOG_H
