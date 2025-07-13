/********************************************************************************
** Form generated from reading UI file 'racinggame.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACINGGAME_H
#define UI_RACINGGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RacingGame
{
public:
    QWidget *centralwidget;
    QFrame *trackFrame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *howToPlayButton;
    QLabel *introLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RacingGame)
    {
        if (RacingGame->objectName().isEmpty())
            RacingGame->setObjectName("RacingGame");
        RacingGame->resize(1200, 957);
        centralwidget = new QWidget(RacingGame);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        trackFrame = new QFrame(centralwidget);
        trackFrame->setObjectName("trackFrame");
        trackFrame->setGeometry(QRect(10, -20, 1181, 911));
        trackFrame->setFrameShape(QFrame::Shape::StyledPanel);
        trackFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(trackFrame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(431, 713, 281, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName("startButton");
        startButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;  /* \353\271\250\352\260\204\354\203\211 */\n"
"    color: white;               /* \352\270\200\354\236\220\354\203\211 \355\235\260\354\203\211 */\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 16px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;  /* \353\247\210\354\232\260\354\212\244 \354\230\244\353\262\204 \354\213\234 \354\226\264\353\221\220\354\232\264 \353\271\250\352\260\225 */\n"
"}\n"
""));

        verticalLayout->addWidget(startButton);

        howToPlayButton = new QPushButton(verticalLayoutWidget);
        howToPlayButton->setObjectName("howToPlayButton");
        howToPlayButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;  /* \353\271\250\352\260\204\354\203\211 */\n"
"    color: white;               /* \352\270\200\354\236\220\354\203\211 \355\235\260\354\203\211 */\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font-size: 16px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;  /* \353\247\210\354\232\260\354\212\244 \354\230\244\353\262\204 \354\213\234 \354\226\264\353\221\220\354\232\264 \353\271\250\352\260\225 */\n"
"}\n"
""));

        verticalLayout->addWidget(howToPlayButton);

        introLabel = new QLabel(trackFrame);
        introLabel->setObjectName("introLabel");
        introLabel->setEnabled(true);
        introLabel->setGeometry(QRect(0, 20, 1181, 891));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(introLabel->sizePolicy().hasHeightForWidth());
        introLabel->setSizePolicy(sizePolicy);
        RacingGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RacingGame);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 37));
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
        howToPlayButton->setText(QCoreApplication::translate("RacingGame", "How To Play", nullptr));
        introLabel->setText(QCoreApplication::translate("RacingGame", "photo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RacingGame: public Ui_RacingGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACINGGAME_H
