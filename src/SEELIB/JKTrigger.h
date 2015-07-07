#ifndef JKTRIGGER_H
#define JKTRIGGER_H

#include <QPainter>
#include <QLabel>
#include <UmElement.h>

class JKTrigger : public UmElement
{
    Q_OBJECT

public:
    explicit JKTrigger(QString name, QWidget *parent = 0);
    ~JKTrigger();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);


    QLabel* label;
};

#endif // JKTRIGGER_H
