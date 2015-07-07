#ifndef UMTUMBLERWIDGET_H
#define UMTUMBLERWIDGET_H

#include <UmElement.h>
#include <QImage>
#include <QLabel>

class UmTumbler : public UmElement
{
    Q_OBJECT
public:
    explicit UmTumbler(QWidget *parent = 0);
    explicit UmTumbler(QString labelname, QWidget *parent = 0);

    ~UmTumbler();

    void setChecked(bool value);
    bool isChecked();

private:
    QImage* image;
    bool checked;
    int frame_size;
    QLabel* label;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);

signals:
    void stateChanged();

public slots:

};

#endif // UMTUMBLERWIDGET_H
