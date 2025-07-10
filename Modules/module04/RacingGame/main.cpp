#include "racinggame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RacingGame game;
    game.show();
    return a.exec();
}


