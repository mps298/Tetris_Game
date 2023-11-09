
#pragma once
#include <QPainter>

#include "nextfigure.h"
#include "figure.h"
#include "glass.h"

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
nextFigure = nullptr;
}

void NextFigure::RenewNextFigureSlot(Figure* other)
{
    nextFigure = other;
    repaint();
}


void NextFigure::paintEvent(QPaintEvent *event)
{
       QPainter painter(this);

       cellSize = width()/5;

       for (uint row = 0; row < figureSize + 4; row++)
       {
           for  (uint col = 0; col < 5; col++)
           {
               QRect tmp(QPoint(col*cellSize, row*cellSize),QSize(cellSize-1,cellSize-1));
               if (col == 2 && row > 1 && row < figureSize + 2 && nextFigure)
               {
                    painter.fillRect(tmp, nextFigure->CellColor(row - 2));
               }
               else
               {
                    painter.fillRect(tmp, QColor(150,150,150));
               }
           }
       }
}
