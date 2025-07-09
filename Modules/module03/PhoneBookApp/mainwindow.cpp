#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subwindow.h"
#include <QFile>

//시그널-슬롯 연결을 connect 해줘야 gui에서 작동함
//add--> add list
//remove --> remove
//load --> update list


//constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadFromFile();

    // window name setting
    setWindowTitle("PhoneBook App - Kevin");


    //입력창 메세지 출력(일반적으로 생성자에서 선언)
    ui->nameEdit->setPlaceholderText("                              Input your Name");
    ui->phoneEdit->setPlaceholderText("                       Input your Phone number");
    ui->emailEdit->setPlaceholderText("                             Input your E-mail");
    ui->searchEdit->setPlaceholderText("             Input to search : Name");

    // signal-slot connection part(not required to edit .h)
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddContact); //add button
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onOpenNewWindow); //load button --> update list
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveContact); //remove button

    //for double click on list-->new window(more information)
    connect(ui->contactListWidget, &QListWidget::itemDoubleClicked,this, &MainWindow::onContactDoubleClicked);

    //save and exit
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveAndExit);

}


MainWindow::~MainWindow()
{
    delete ui;
}

//for add button
void MainWindow::onAddContact() {
    //input
    QString name = ui->nameEdit->text();
    QString phone = ui->phoneEdit->text();
    QString email = ui->emailEdit->text();
    contactList_.addContact(Contact(name, phone, email)); //add function
    refreshContactList();
}

//for remove button --> 이 부분부터 수정하기
void MainWindow::onRemoveContact(){
    contactList_.removeContact(0); // idx edit require(chose name--> idx)
    refreshContactList();
}

//list refresh(초기화)
void MainWindow::refreshContactList() {
    ui->contactListWidget->clear();
    for (const auto& contact : contactList_.getContacts()) {
        ui->contactListWidget->addItem(contact.getName());
    }
}

//open sub window in mainwindow
void MainWindow::onOpenNewWindow() {
    SubWindow *newWin = new SubWindow(this);  // 부모 지정
    newWin->show();
}

//for doublec click on list --> new window(more information)
void MainWindow::onContactDoubleClicked(QListWidgetItem *item) {
    QString contactInfo = item->text();

    // 새 창 생성
    SubWindow *infoWindow = new SubWindow(this);
    infoWindow->setInfoText(contactInfo);
    infoWindow->show();
}

// to save contact with exit
void MainWindow::onSaveToFile() {
    QString path = QCoreApplication::applicationDirPath() + "/contacts.txt"; //실행파일과 같은 위치에 저장
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto &c : contactList_.getContacts()) {
            out << c.getName() << "," << c.getPhone() << "," << c.getEmail() << "\n";
        }
        file.close();
    }
}

//save and exit code
void MainWindow::onSaveAndExit() {
    onSaveToFile();  // 연락처 저장
    close();         // 메인 윈도우 종료
}

// load contact.txt file
void MainWindow::loadFromFile() {
    QString path = QCoreApplication::applicationDirPath() + "/contacts.txt";
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        contactList_.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 3) {
                contactList_.addContact(Contact(parts[0], parts[1], parts[2]));
            }
        }
        file.close();
        refreshContactList();
    }
}

