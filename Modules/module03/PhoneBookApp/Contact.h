#ifndef CONTACT_H
#define CONTACT_H

#include <QString> //qt string class (string 대신 이거 쓰는게 좋음)

/*
Contact class
*/

class Contact {
public:
    Contact(const QString& name = "", const QString& phone = "", const QString& email = ""); //constructor

    //member function
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


