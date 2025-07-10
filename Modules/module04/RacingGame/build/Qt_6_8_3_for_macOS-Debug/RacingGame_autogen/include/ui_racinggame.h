/********************************************************************************
** Form generated from reading UI file 'racinggame.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACINGGAME_H
#define UI_RACINGGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RacingGame
{
public:
    QWidget *centralwidget;
    QFrame *trackFrame;
    QPushButton *startButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RacingGame)
    {
        if (RacingGame->objectName().isEmpty())
            RacingGame->setObjectName("RacingGame");
        RacingGame->resize(800, 600);
        centralwidget = new QWidget(RacingGame);
        centralwidget->setObjectName("centralwidget");
        trackFrame = new QFrame(centralwidget);
        trackFrame->setObjectName("trackFrame");
        trackFrame->setGeometry(QRect(150, 160, 461, 191));
        trackFrame->setFrameShape(QFrame::Shape::StyledPanel);
        trackFrame->setFrameShadow(QFrame::Shadow::Raised);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(320, 390, 100, 32));
        RacingGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RacingGame);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        RacingGame->setMenuBar(menubar);
        statusbar = new QStatusBar(RacingGame);
        statusbar->setObjectName("statusbar");
        RacingGame->setStatusBar(statusbar);

        retranslateUi(RacingGame);

        QMetaObject::connectSlotsByName(RacingGame);
    } // setupUi

    void retranslateUi(QMainWindow *RacingGame)
    {
        RacingGame->setWindowTitle(QCoreApplication::translate("RacingGame", "RacingGame", nullptr));
        startButton->setText(QCoreApplication::translate("RacingGame", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RacingGame: public Ui_RacingGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACINGGAME_H
