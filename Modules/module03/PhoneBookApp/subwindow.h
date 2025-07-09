#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>
#include <QString>
#include <QPixmap>
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

    void setContactInfo(const QString &name, const QString &phone, const QString &email, const QPixmap &photo = QPixmap());

private:
    Ui::SubWindow *ui;
};

#endif // SUBWINDOW_H
