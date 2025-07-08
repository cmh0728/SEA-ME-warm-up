#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::SubWindow)
{
    ui->setupUi(this);

    // 버튼 눌렀을 때 동작 같은 것도 여기에 연결 가능
    connect(ui->closeButton, &QPushButton::clicked, this, &SubWindow::close);
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::setInfoText(const QString& text) {
    ui->label->setText(text);  // QLabel 등 수정 가능
}
