// contactlist.cpp
#include "Contactlist.h"

void ContactList::addContact(const Contact& contact) {
    contacts_.append(contact);
}

void ContactList::removeContact(int index) {
    if (index >= 0 && index < contacts_.size()) {
        contacts_.removeAt(index);
    }
}

QVector<Contact> ContactList::getContacts() const {
    return contacts_;
}

QVector<Contact> ContactList::searchByName(const QString& keyword) const {
    QVector<Contact> results;
    for (const Contact& contact : contacts_) {
        if (contact.getName().contains(keyword, Qt::CaseInsensitive)) {
            results.append(contact);
        }
    }
    return results;
}
