#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ExitButton_clicked();
    void on_actionExit_triggered();
    void ChangePauseButtonTextSlot(bool);
    void on_actionRules_triggered();
    void on_actionNew_Game_triggered();

private:
    Ui::MainWindow *ui;

protected:
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
