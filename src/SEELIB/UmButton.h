#ifndef UMBUTTON_H
#define UMBUTTON_H

#include <UmElement.h>
#include <QPainter>
#include <QMouseEvent>
#include <QImage>
#include <QLabel>

class UmButton : public UmElement
{
    Q_OBJECT
public:
    explicit UmButton(QWidget *parent = 0);
    explicit UmButton(QString labelname, QWidget *parent = 0);

    ~UmButton();

private:
    QImage* image;
    int frame_size;
    QLabel* label;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

signals:
    void stateChanged();

};

#endif // UMBUTTON_H
