#ifndef DTRIGGER_H
#define DTRIGGER_H

#include <QPainter>
#include <QLabel>
#include <UmElement.h>

class DTrigger : public UmElement
{
    Q_OBJECT
public:
    explicit DTrigger(QString name, QWidget *parent = 0);
    ~DTrigger();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);


    QLabel* label;
};

#endif // DTRIGGER_H
