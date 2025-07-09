#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>
#include "ui_subwindow.h"

namespace Ui {
class SubWindow;
}

class SubWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SubWindow(QWidget *parent = nullptr);
    ~SubWindow();

    void setInfoText(const QString &text);// 외부에서 텍스트를 설정할 수 있게!

private:
    Ui::SubWindow *ui;
};

#endif // SUBWINDOW_H
