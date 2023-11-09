/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionNew_Game;
    QAction *actionRules;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QLabel *NextFigureLabel;
    NextFigure *NextFigureWidget;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    Glass *GlassWidget;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *NewGameButton;
    QPushButton *PauseButton;
    QPushButton *ExitButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *ScoreLabel;
    QLCDNumber *ScoreLCDNumber;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menuBar;
    QMenu *menu_Main;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1377, 1739);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/myImages/Images/Tetris.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/myImages/Images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/myImages/Images/iconNewGame.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Game->setIcon(icon2);
        actionRules = new QAction(MainWindow);
        actionRules->setObjectName(QString::fromUtf8("actionRules"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/myImages/Images/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRules->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(40);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 20, 20, 0);
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        NextFigureLabel = new QLabel(centralWidget);
        NextFigureLabel->setObjectName(QString::fromUtf8("NextFigureLabel"));
        sizePolicy.setHeightForWidth(NextFigureLabel->sizePolicy().hasHeightForWidth());
        NextFigureLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        NextFigureLabel->setFont(font);
        NextFigureLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(NextFigureLabel);

        NextFigureWidget = new NextFigure(centralWidget);
        NextFigureWidget->setObjectName(QString::fromUtf8("NextFigureWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NextFigureWidget->sizePolicy().hasHeightForWidth());
        NextFigureWidget->setSizePolicy(sizePolicy1);
        NextFigureWidget->setMinimumSize(QSize(150, 0));

        verticalLayout->addWidget(NextFigureWidget);

        verticalSpacer = new QSpacerItem(20, 228, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        GlassWidget = new Glass(centralWidget);
        GlassWidget->setObjectName(QString::fromUtf8("GlassWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(GlassWidget->sizePolicy().hasHeightForWidth());
        GlassWidget->setSizePolicy(sizePolicy2);
        GlassWidget->setFocusPolicy(Qt::StrongFocus);
        GlassWidget->setProperty("Rows", QVariant(20u));
        GlassWidget->setProperty("Columns", QVariant(10u));

        horizontalLayout->addWidget(GlassWidget);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        NewGameButton = new QPushButton(centralWidget);
        NewGameButton->setObjectName(QString::fromUtf8("NewGameButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(NewGameButton->sizePolicy().hasHeightForWidth());
        NewGameButton->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        NewGameButton->setFont(font1);
        NewGameButton->setLayoutDirection(Qt::LeftToRight);
        NewGameButton->setIcon(icon2);

        verticalLayout_2->addWidget(NewGameButton);

        PauseButton = new QPushButton(centralWidget);
        PauseButton->setObjectName(QString::fromUtf8("PauseButton"));
        sizePolicy3.setHeightForWidth(PauseButton->sizePolicy().hasHeightForWidth());
        PauseButton->setSizePolicy(sizePolicy3);
        PauseButton->setFont(font1);

        verticalLayout_2->addWidget(PauseButton);

        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        sizePolicy3.setHeightForWidth(ExitButton->sizePolicy().hasHeightForWidth());
        ExitButton->setSizePolicy(sizePolicy3);
        ExitButton->setFont(font1);
        ExitButton->setIcon(icon1);

        verticalLayout_2->addWidget(ExitButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        ScoreLabel = new QLabel(centralWidget);
        ScoreLabel->setObjectName(QString::fromUtf8("ScoreLabel"));
        ScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ScoreLabel);

        ScoreLCDNumber = new QLCDNumber(centralWidget);
        ScoreLCDNumber->setObjectName(QString::fromUtf8("ScoreLCDNumber"));
        sizePolicy.setHeightForWidth(ScoreLCDNumber->sizePolicy().hasHeightForWidth());
        ScoreLCDNumber->setSizePolicy(sizePolicy);
        ScoreLCDNumber->setMinimumSize(QSize(100, 80));
        ScoreLCDNumber->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        ScoreLCDNumber->setFont(font2);
        ScoreLCDNumber->setStyleSheet(QString::fromUtf8("font: 18pt \"MS Shell Dlg 2\";"));
        ScoreLCDNumber->setProperty("value", QVariant(0.000000000000000));

        verticalLayout_2->addWidget(ScoreLCDNumber);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1377, 28));
        menu_Main = new QMenu(menuBar);
        menu_Main->setObjectName(QString::fromUtf8("menu_Main"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sizePolicy3.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy3);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Main->menuAction());
        menu_Main->addAction(actionNew_Game);
        menu_Main->addAction(actionExit);
        menu_Main->addAction(actionRules);

        retranslateUi(MainWindow);
        QObject::connect(ExitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(NewGameButton, SIGNAL(clicked()), GlassWidget, SLOT(NewGameSlot()));
        QObject::connect(PauseButton, SIGNAL(clicked()), GlassWidget, SLOT(PausedSlot()));
        QObject::connect(GlassWidget, SIGNAL(SetLevel(QString)), statusBar, SLOT(showMessage(QString)));
        QObject::connect(GlassWidget, SIGNAL(SetScore(int)), ScoreLCDNumber, SLOT(display(int)));
        QObject::connect(GlassWidget, SIGNAL(DrawNextFigureSignal(Figure*)), NextFigureWidget, SLOT(RenewNextFigureSlot(Figure*)));
        QObject::connect(GlassWidget, SIGNAL(ChangePauseButtonTextSignal(bool)), MainWindow, SLOT(ChangePauseButtonTextSlot(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Medvedev Tetris", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionNew_Game->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        actionRules->setText(QCoreApplication::translate("MainWindow", " Rules and Keys", nullptr));
        NextFigureLabel->setText(QCoreApplication::translate("MainWindow", "Next figure", nullptr));
        NewGameButton->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        PauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        ExitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        ScoreLabel->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        menu_Main->setTitle(QCoreApplication::translate("MainWindow", "&Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
