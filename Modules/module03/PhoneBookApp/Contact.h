#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
public:
    Contact(const QString& name = "", const QString& phone = "", const QString& email = "");
    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;
    void setName(const QString& name);
    void setPhone(const QString& phone);
    void setEmail(const QString& email);

private:
    QString name_;
    QString phone_;
    QString email_;
};

#endif // CONTACT_H
