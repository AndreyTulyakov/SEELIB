#include "StendSelectionDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StendSelectionDialog selectionDialog;
    selectionDialog.show();

    return a.exec();
}
