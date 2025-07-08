#ifndef MAINWINDOW_H //헤더가드
#define MAINWINDOW_H

#include <QMainWindow> // for qt mainwindow class

//user defined class
#include "Contactlist.h"
#include "Contact.h"

QT_BEGIN_NAMESPACE // qt ui class
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

private slots: //signal-slot
    void onAddContact();       // "추가" 버튼 등에서 연결되는 슬롯
    void onSaveToFile();       // 저장 기능
    void refreshContactList(); // 리스트 갱신
    void onOpenNewWindow();
    void onRemoveContact();

private:
    Ui::MainWindow *ui; //ui object pointer
    ContactList contactList_;  // 연락처 저장 객체
};

#endif // MAINWINDOW_H
