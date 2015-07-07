#ifndef TTRIGGER_H
#define TTRIGGER_H

#include <QPainter>
#include <QLabel>
#include <UmElement.h>

class TTrigger : public UmElement
{
    Q_OBJECT
public:
    explicit TTrigger(QString name, QWidget *parent = 0);
    ~TTrigger();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);


    QLabel* label;

};

#endif // TTRIGGER_H
