#ifndef MEMORY_H
#define MEMORY_H

#include <UmElement.h>
#include <QLabel>
#include <QPainter>

#define byte bool

class Memory : public UmElement
{
    Q_OBJECT
public:
    explicit Memory(QString name, int inputPins, int ouputPins, QWidget *parent = 0);
    ~Memory();

    bool getValue(int wordNumber, int byteNumber);
    void setValue(int wordNumber, int byteNumber, bool value);

    bool getValue(int offset);
    void setValue(int offset, bool value);


private:
    int wordSize;
    int wordCount;
    bool *data;
    QLabel* label;

private:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // MEMORY_H
