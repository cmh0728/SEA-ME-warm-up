#include "mainwindow.h"      // 메인 윈도우 클래스 include
#include <QApplication>      // Qt GUI 앱의 필수 클래스

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Qt application instance
    MainWindow w;                // MainWindow instance
    w.show();                    // window show
    return a.exec();             // event loop
}
