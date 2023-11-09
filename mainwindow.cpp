
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GlassWidget->resize(ui->GlassWidget->height() / 2, ui->GlassWidget->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    close();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::ChangePauseButtonTextSlot(bool gameOn)
{
    if (gameOn)
    {
        ui->PauseButton->setText(tr("Pause"));
    }
    else
    {
        ui->PauseButton->setText(tr("Resume"));
    }
}

void MainWindow::on_actionRules_triggered()
{
    QMessageBox* rulesAndKeys = new QMessageBox;

    rulesAndKeys->setIcon(QMessageBox::Information);
    rulesAndKeys->setWindowTitle(tr("Rules and Keys"));
    rulesAndKeys->setText(tr("You get scores if put 3 and more cells of a kind in a row (either horizontal or vertical\n\n"
                          "The speed of game and your level increase each time you get a match\n\n"
                          "Arrows left and right move the figure accordingly\n\n"
                          "Arrows up and down spin cell colors in your figure\n\n"
                          "Space key drops the figure down\n\n"
                          "Escape key gets the game paused/resumes the game"));
    rulesAndKeys->adjustSize();
    rulesAndKeys->exec();
}


void MainWindow::on_actionNew_Game_triggered()
{
    ui->GlassWidget->NewGameSlot();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}
