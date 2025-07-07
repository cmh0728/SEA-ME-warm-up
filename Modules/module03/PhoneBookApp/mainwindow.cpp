#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

//시그널-슬롯 연결을 connect 해줘야 gui에서 작동함

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 버튼 클릭 시 슬롯 연결
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddContact);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveToFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddContact() {
    QString name = ui->nameEdit->text();
    QString phone = ui->phoneEdit->text();
    QString email = ui->emailEdit->text();
    contactList_.addContact(Contact(name, phone, email));
    refreshContactList();
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
