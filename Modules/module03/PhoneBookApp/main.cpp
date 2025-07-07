#include "mainwindow.h"      // 메인 윈도우 클래스 include
#include <QApplication>      // Qt GUI 앱의 필수 클래스

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Qt 어플리케이션 객체 생성
    MainWindow w;                // MainWindow 인스턴스 생성
    w.show();                    // 윈도우 보이기
    return a.exec();             // 이벤트 루프 실행
}
