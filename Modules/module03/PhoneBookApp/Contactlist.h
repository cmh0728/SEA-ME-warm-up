#ifndef CONTACTLIST_H
#define CONTACTLIST_H

// contactlist.h
#include <QVector>
#include "contact.h"

class ContactList {
public:
    void addContact(const Contact& contact);
    void removeContact(int index);
    QVector<Contact> getContacts() const;
    QVector<Contact> searchByName(const QString& keyword) const;

private:
    QVector<Contact> contacts_;
};


#endif // CONTACTLIST_H
