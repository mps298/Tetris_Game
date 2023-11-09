#pragma once
#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
class Figure;

class NextFigure : public QWidget
{
    Q_OBJECT
    Figure* nextFigure;

public:
    explicit NextFigure(QWidget *parent = nullptr);

signals:

public slots:
    void RenewNextFigureSlot(Figure*);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // NEXTFIGURE_H
