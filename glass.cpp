
#pragma once
#include "glass.h"
#include "figure.h"



Glass::Glass(QWidget *parent) : QWidget(parent)
{
    gameOn = false;
    score = 0;
    level = 1;
    levelString = QString(tr("Level: "));

    interval = 500;
    myTimerID = 0;

    currentFigure = new Figure;
    nextFigure = new Figure;

    connect(this, SIGNAL(GlassArrayInitialSignal()), this, SLOT(GlassArrayInitialSlot()), Qt::QueuedConnection);
    emit GlassArrayInitialSignal();
}

Glass::~Glass()
{
    delete currentFigure;
    delete nextFigure;
}

uint Glass::Rows() const
{
    return m_Rows;
}

uint Glass::Columns() const
{
    return m_Columns;
}

void Glass::setRows(uint Rows)
{
    if (m_Rows == Rows)
        return;

    m_Rows = Rows;
    emit RowsChanged(m_Rows);
}

void Glass::setColumns(uint Columns)
{
    if (m_Columns == Columns)
        return;

    m_Columns = Columns;
    emit ColumnsChanged(m_Columns);
}

void Glass::GlassArrayInitialSlot()
{
    glassColorsArray.resize(m_Rows);
    for (uint i=0; i<m_Rows; i++)
    {
        glassColorsArray[i].resize(m_Columns);
    }

    if (rect().width() < rect().height()/2)
    {
        cellSize = rect().width()/10;
    }
    else
    {
        cellSize = rect().height()/20;
    }

    ClearGlassSlot();
}

void Glass::ClearGlassSlot()
{
    for (uint row=0; row<m_Rows; row++)
    {
        for (uint col=0; col<m_Columns; col++)
        {
            glassColorsArray[row][col]=emptyCellColor;
        }
    }
    score=0;
    interval=500;
    level=1;
    emit SetLevel(levelString+QString::number(level));

}

void Glass::NewGameSlot()
{
    if (myTimerID)
    {
        killTimer(myTimerID);
        myTimerID = 0;
    }
    ClearGlassSlot();
    currentFigure->SetFigureColors();
    currentFigure->SetTopCellCoords(0, m_Columns/2);
    nextFigure->SetFigureColors();
    emit DrawNextFigureSignal(nextFigure);
    setFocus();
    repaint();
    currentFigure->PaintFigure();

    gameOn = true;
    emit SetScore(score);
    myTimerID = startTimer(interval);
    emit ChangePauseButtonTextSignal(gameOn);

}

void Glass::PausedSlot()
{
    if (gameOn)
    {
        if (myTimerID)
        {
            killTimer(myTimerID);
            myTimerID = 0;
        }
    }
    else
    {
        myTimerID = startTimer(interval);
        setFocus();
    }
    gameOn=!gameOn;
    qDebug()<<"gameOn is "<<gameOn;

    emit SetLevel(levelString+QString::number(level));
    emit ChangePauseButtonTextSignal(gameOn);

}

void Glass::AddFigureToGlass()
{
   for (uint row=0; row<figureSize; row++)
   {
       glassColorsArray[currentFigure->GetTopCellRow()+row][currentFigure->GetFigureColumn()] = currentFigure->CellColor(row);
   }

   EraseMatches();

   Figure* tmp = currentFigure;
   currentFigure = nextFigure;
   nextFigure = tmp;

   currentFigure->SetTopCellCoords(0, m_Columns/2);
   nextFigure->SetTopCellCoords(0,0);
   nextFigure->SetFigureColors();
   setFocus();
   repaint();

   emit DrawNextFigureSignal(nextFigure);


}

void Glass::EraseMatches()
{
    //erase horizontal matches
    for (uint row = 0; row<m_Rows; row++)
    {
        for (uint col = 0; col<m_Columns-2; col++)
        {
            uint start = col;
            uint finish = start;
            while (glassColorsArray[row][start]!=emptyCellColor
                   && finish<m_Columns-1
                   && glassColorsArray[row][start]==glassColorsArray[row][finish+1])
            {
                finish++;
            }
            if (start+1 < finish)
            {
                score+= 3 + (finish-start-2)*3; //3 points for 3 cells in a row, 6 for 4, 9 for 5 etc.

                if (interval>5)
                {
                    interval-=interval>300?5:1;
                     qDebug()<<interval;
                    killTimer(myTimerID);
                    myTimerID=startTimer(interval);
                }
                emit SetScore(score);
                level++;
                emit SetLevel(levelString+QString::number(level));


                for (;start<=finish; start++)
                {
                    for (uint r = row; r>0; r--)
                    {
                        glassColorsArray[r][start] = glassColorsArray[r-1][start];
                    }
                    glassColorsArray[0][start]=emptyCellColor;
                }

                EraseMatches();//check rows and then columns for matches once again
            }
        }
    }

    //erase vertical matches
    for (uint col = 0; col<m_Columns; col++)
    {
        for (uint row = 0; row<m_Rows-2; row++)
        {
            uint start = row;
            uint finish = start;
            while (glassColorsArray[start][col]!=emptyCellColor
                   && finish<m_Rows-1
                   && glassColorsArray[start][col]==glassColorsArray[finish+1][col])
            {
                finish++;
            }
            if (start+1 < finish)
            {
                score+= 3 + (finish-start-2)*3; //3 points for 3 cells in a row, 6 for 4, 9 for 5 etc.

                if (interval>5)
                {
                    interval-=interval>300?5:1;
                    qDebug()<<interval;
                    killTimer(myTimerID);
                    myTimerID=startTimer(interval);
                }
                emit SetScore(score);
                level++;
                emit SetLevel(levelString+QString::number(level));


                while (start)
                {
                    glassColorsArray[finish][col] = glassColorsArray[start-1][col];
                    start--;
                    finish--;
                }
                for (; start<=finish; start++) //to make first <figureSize> cells empty
                {
                    glassColorsArray[start][col]=emptyCellColor;
                }

                EraseMatches();//check rows and then columns for matches once again
            }
        }
    }

    // Add checking diagonale matches? ///////////////////////////////////////////////////////////
}


void Glass::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (uint row=0; row<m_Rows; row++)
    {
        for (uint col=0; col<m_Columns; col++)
        {
            QRect tmp(QPoint(col*cellSize, row*cellSize),QSize(cellSize-1,cellSize-1));
            painter.fillRect(tmp, glassColorsArray[row][col]);
        }
    }
    uint i=0;
    for (uint row = currentFigure->GetTopCellRow(); row<=currentFigure->GetLowCellRow(); row++)
    {
        QRect tmp(QPoint(currentFigure->GetFigureColumn()*cellSize, row*cellSize),QSize(cellSize-1,cellSize-1));

        painter.fillRect(tmp, currentFigure->CellColor(i));
        i++;
    }
}


void Glass::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        PausedSlot();
    }
    if (gameOn)
    {
        switch (event->key()) {
        case Qt::Key_Left:
            if (currentFigure->GetFigureColumn()
                    //to prevent moving through colored cells
                    && glassColorsArray[currentFigure->GetLowCellRow()][currentFigure->GetFigureColumn()-1]==emptyCellColor)
            {
                currentFigure->SetTopCellCoords(currentFigure->GetTopCellRow(), currentFigure->GetFigureColumn()-1);
            } break;
        case Qt::Key_Right:
            if (currentFigure->GetFigureColumn()<m_Columns-1
                    && glassColorsArray[currentFigure->GetLowCellRow()][currentFigure->GetFigureColumn()+1]==emptyCellColor)
            {
                currentFigure->SetTopCellCoords(currentFigure->GetTopCellRow(), currentFigure->GetFigureColumn()+1);
            } break;
        case Qt::Key_Up: currentFigure->ColorsUp(); break;
        case Qt::Key_Down: currentFigure->ColorsDown(); break;
        case Qt::Key_Space:
        {
            uint tmp = m_Rows-1;
            while (glassColorsArray[tmp][currentFigure->GetFigureColumn()]!=emptyCellColor)
            {
                tmp--;
            }
            currentFigure->SetTopCellCoords(tmp-figureSize+1, currentFigure->GetFigureColumn()); break;
        }
            default: break;
        }
        repaint();
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}


void Glass::timerEvent(QTimerEvent *event)
{
    if (gameOn)
    {

        if (currentFigure->GetLowCellRow()<m_Rows-1
                && glassColorsArray[currentFigure->GetLowCellRow()+1][currentFigure->GetFigureColumn()]!=emptyCellColor && currentFigure->GetTopCellRow()==0)
        {
            killTimer(myTimerID);
            myTimerID = 0;

            QMessageBox* gameOver = new QMessageBox;
            gameOver->setIconPixmap(QPixmap(":/myImages/Images/iconExit.ico"));
            gameOver->setWindowTitle("");

            QString scoreString;
            scoreString.setNum(score);
            gameOver->setText(tr("GAME OVER\nYour score is ") + scoreString);
            gameOver->exec();

           delete gameOver;
        }
        else
        {
            if (currentFigure->GetLowCellRow()<m_Rows-1
                    && glassColorsArray[currentFigure->GetLowCellRow()+1][currentFigure->GetFigureColumn()]==emptyCellColor)
            {
                currentFigure->SetTopCellCoords(currentFigure->GetTopCellRow()+1, currentFigure->GetFigureColumn());
                repaint();
            }
            else
            {
                AddFigureToGlass();
            }
        }
    }
}

void Glass::resizeEvent(QResizeEvent *event)
{

    if (rect().width() < rect().height()/2)
    {
        cellSize = rect().width()/10;
    }
    else
    {
        cellSize = rect().height()/20;
    }

    repaint();
}






























