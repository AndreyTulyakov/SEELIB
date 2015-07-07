#ifndef UMLEDWIDGET_H
#define UMLEDWIDGET_H

#include "UmElement.h"
#include <QImage>

class UmLed : public UmElement
{
    Q_OBJECT
public:
    explicit UmLed(QWidget *parent = 0);
    void setChecked(bool value);
    bool isChecked();

private:
    QImage* image;
    bool checked;
    int frame_size;

protected:
    void paintEvent(QPaintEvent *event);
    void onInputUpdated(QString pinName);


signals:
    void stateChanged();
public slots:

};

#endif // UMLEDWIDGET_H
