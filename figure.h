#pragma once
#ifndef FIGURE_H
#define FIGURE_H

#include "glass.h"

const uint figureSize= 3;
static uint cellSize = 50;

class Figure
{
    QColor FigureColors[figureSize];
    uint topCellRow;
    uint figureColumn;

public:
    Figure();
    uint GetTopCellRow();
    uint GetLowCellRow();
    uint GetFigureColumn();
    void SetTopCellCoords(uint, uint);
    void PaintFigure();
    void SetFigureColors();
    QColor CellColor(uint) const;
    void ColorsUp();
    void ColorsDown();
};

#endif // FIGURE_H
