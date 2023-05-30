#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    int i = -1;
    this->oldest = 0;
    while (++i < 8)
        this->contacts[i].setId(-1);
}

int PhoneBook::addContact(Contact &contact)
{
    int i;

    i = -1;
    while (this->contacts[++i].getId() != -1 && i < 8);
    if (i == 8)
    {
        this->contacts[this->oldest] = contact;
        this->oldest = (this->oldest == 7) ? 0 : this->oldest++;
    }
}

void PhoneBook::displayContacts()
{
    int i;

    i = -1;
    while (++i < 8)
        this->contacts[i].getInfo();
}