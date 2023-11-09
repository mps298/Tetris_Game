#pragma once
#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include <QColor>
#include <QVector>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QTranslator>
#include <QTime>
#include <QMessageBox>

class Figure;

static QColor emptyCellColor(120,120,120);


class Glass : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(uint Rows READ Rows WRITE setRows NOTIFY RowsChanged)
    Q_PROPERTY(uint Columns READ Columns WRITE setColumns NOTIFY ColumnsChanged)


    uint m_Rows;
    uint m_Columns;


    bool gameOn;
    int score;
    int level;

    Figure* currentFigure;
    Figure* nextFigure;

    int myTimerID;
    uint interval;
    QString levelString;


    QVector<QVector<QColor>>glassColorsArray;

public:
    explicit Glass(QWidget *parent = nullptr);
    ~Glass();


uint Rows() const;
uint Columns() const;

signals:
    void RowsChanged(uint Rows);
    void ColumnsChanged(uint Columns);
    void GlassArrayInitialSignal();
    void DrawNextFigureSignal(Figure*);
    void SetScore(int);
    void SetLevel(QString);
    void ChangePauseButtonTextSignal(bool);

public slots:
    void setRows(uint Rows);
    void setColumns(uint Columns);
    void GlassArrayInitialSlot();
    void ClearGlassSlot();
    void NewGameSlot();
    void PausedSlot();
    void AddFigureToGlass();
    void EraseMatches();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void timerEvent(QTimerEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // GLASS_H
