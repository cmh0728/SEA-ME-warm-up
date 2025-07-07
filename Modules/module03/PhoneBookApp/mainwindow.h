#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Contactlist.h"  // 연락처 리스트 클래스 포함
#include "Contact.h"      // Contact 클래스도 같이 include (명시적으로 필요하지 않더라도 권장)

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddContact();       // "추가" 버튼 등에서 연결되는 슬롯
    void onSaveToFile();       // 저장 기능
    void refreshContactList(); // 리스트 갱신

private:
    Ui::MainWindow *ui;
    ContactList contactList_;  // 연락처 저장 객체
};

#endif // MAINWINDOW_H
