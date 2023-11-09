#pragma once
#include "figure.h"

Figure::Figure()
{
    for (uint i = 0; i<figureSize; i++)
    {
       FigureColors[i] = emptyCellColor;
    }
    topCellRow = 0;
    figureColumn = 0;
}

uint Figure::GetTopCellRow()
{
    return topCellRow;
}

uint Figure::GetLowCellRow()
{
    return topCellRow+(figureSize-1);
}

uint Figure::GetFigureColumn()
{
    return figureColumn;
}

void Figure::SetTopCellCoords(uint r, uint c)
{
    topCellRow = r;
    figureColumn = c;
}

void Figure::PaintFigure()
{
    QPainter painter;

    int row = topCellRow;
    for (uint i=0; i<figureSize; i++)
    {
        QRect tmp(QPoint(figureColumn*cellSize, row*cellSize),QSize(cellSize-1,cellSize-1));
        painter.fillRect(tmp, FigureColors[i]);
        row++;
    }
}

void Figure::SetFigureColors()
{
    for (uint i = 0; i<figureSize; i++)
    {
        switch (qrand()%4)
        {
            case 0: FigureColors[i]=Qt::red; break;
            case 1: FigureColors[i]=Qt::blue; break;
            case 2: FigureColors[i]=Qt::green; break;
            case 3: FigureColors[i]=Qt::yellow; break;
            default: FigureColors[i]=emptyCellColor; break;
        }
    }
}

QColor Figure::CellColor(uint i) const
{
    return FigureColors[i];
}

void Figure::ColorsUp()
{
    QColor tmp = FigureColors[0];
    for (uint i = 0; i<figureSize-1; i++)
    {
        FigureColors[i]=FigureColors[i+1];
    }
    FigureColors[figureSize-1]=tmp;
}

void Figure::ColorsDown()
{
    QColor tmp = FigureColors[figureSize-1];
    for (uint i = figureSize-1; i>0; i--)
    {
        FigureColors[i]=FigureColors[i-1];
    }
    FigureColors[0]=tmp;
}
