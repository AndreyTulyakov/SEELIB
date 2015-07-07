#ifndef CLOCKGENERATOR_H
#define CLOCKGENERATOR_H

#include "UmElement.h"
#include <QLabel>
#include <QTimer>
#include <QDial>

class ClockGenerator : public UmElement
{
    Q_OBJECT

public:
    ClockGenerator(QString name, int tickPeriod, QWidget* parent);
    ~ClockGenerator();

protected:
    void paintEvent(QPaintEvent *event);

    QLabel* label;
    QLabel* hzIndicator;
    bool tick;

    QTimer timer;
    QDial* dial;

public slots:
    void onTick();
    void onHzChange(int value);
};

#endif // CLOCKGENERATOR_H
