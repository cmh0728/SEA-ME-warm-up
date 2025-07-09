#include "Contactlist.h"


/*
Qvector function
1. append(val)
2. prepend(val)
3. insert(idx, val)
4. remove(idx)
5. clear()
*/


void ContactList::addContact(const Contact& contact) {
    contacts_.append(contact);
}

void ContactList::removeContact(int idx) {
    if (idx >= 0 && idx < contacts_.size()) //index error guard
    {
        contacts_.removeAt(idx);
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

void ContactList::clear() {
    contacts_.clear();
}

