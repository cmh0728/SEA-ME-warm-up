#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);

    //signal-slot connection
    connect(ui->closeButton, &QPushButton::clicked, this, &SubWindow::close); //close button 구현
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::setContactInfo(const QString &name, const QString &phone, const QString &email, const QPixmap &photo)
{
    ui->nameLabel->setText("Name: " + name);
    ui->phoneLabel->setText("Phone: " + phone);
    ui->emailLabel->setText("Email: " + email);

    if (!photo.isNull()) {
        ui->photoLabel->setPixmap(photo);
    } else {
        ui->photoLabel->setText("[No Image]");
    }
}
