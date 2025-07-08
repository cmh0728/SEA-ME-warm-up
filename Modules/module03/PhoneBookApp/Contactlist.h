#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QVector>
#include "contact.h"

/*
Contact List class for save Contacts
use Qvector instead vector
function : add, delete, search, save
*/

class ContactList {
public:
    void addContact(const Contact& contact);
    void removeContact(int idx);
    QVector<Contact> getContacts() const;
    QVector<Contact> searchByName(const QString& keyword) const;

private:
    QVector<Contact> contacts_; //list of Contacts
};


#endif // CONTACTLIST_H
