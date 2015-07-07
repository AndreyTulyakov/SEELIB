#ifndef RSTRIGGER_H
#define RSTRIGGER_H

#include <QPainter>
#include <QLabel>
#include <UmElement.h>

class RSTrigger : public UmElement
{
    Q_OBJECT

public:
    explicit RSTrigger(QString name, QWidget *parent = 0);
    ~RSTrigger();

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);


    QLabel* label;
};

#endif // RSTRIGGER_H
