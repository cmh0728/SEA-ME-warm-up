#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subwindow.h"
#include <QFile>

//시그널-슬롯 연결을 connect 해줘야 gui에서 작동함
//add--> add list
//remove --> remove
//load --> update list

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // signal-slot connection part(not required to edit .h)
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddContact); //add button
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onOpenNewWindow); //load button --> update list
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveContact); //remove button
}

MainWindow::~MainWindow()
{
    delete ui;
}

//for add button
void MainWindow::onAddContact() {
    QString name = ui->nameEdit->text();
    QString phone = ui->phoneEdit->text();
    QString email = ui->emailEdit->text();
    contactList_.addContact(Contact(name, phone, email));
    refreshContactList();
}

//for remove button --> 이 부분부터 수정하기
void MainWindow::onRemoveContact(){
    contactList_.removeContact(0); // idx edit require(chose name--> idx)
}

void MainWindow::refreshContactList() {
    ui->contactListWidget->clear();
    for (const auto& contact : contactList_.getContacts()) {
        ui->contactListWidget->addItem(contact.getName() + " - " + contact.getPhone());
    }
}


void MainWindow::onSaveToFile() {
    QFile file("contacts.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const auto& c : contactList_.getContacts()) {
            out << c.getName() << "," << c.getPhone() << "," << c.getEmail() << "\n";
        }
        file.close();
    }
}

void MainWindow::onOpenNewWindow() {
    SubWindow *newWin = new SubWindow(this);  // 부모 지정
    newWin->show();  // 또는 newWin->exec();  // exec는 모달 창
}

