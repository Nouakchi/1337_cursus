#include "PhoneBook.hpp"
#include "utils.h"

PhoneBook::PhoneBook()
{
    int i = -1;
    this->oldest = -1;
    while (++i < 8)
        this->contacts[i].setIndex(-1);
}

int PhoneBook::addContact(Contact &contact)
{
    this->oldest = (this->oldest == 7) ? 0 : this->oldest + 1;
    this->contacts[this->oldest] = contact;
    return (0);
}

void PhoneBook::displayContacts()
{
    int i;
    int j;

    i = -1;
    while (++i < 44)
        std::cout << "_";
    std::cout << "\n";
    std::cout << resize_data("|index") << "|" << resize_data("First Name") << "|";
    std::cout << resize_data("Last Name") << "|" << resize_data("Nick Name");
    std::cout << "|\n";
    i = -1;
    while (++i < 44)
        std::cout << "-";
    std::cout << "\n";
    i = -1;
    while (this->contacts[++i].getIndex() != -1 && i < 8)
    {
        this->contacts[i].getInfo();
        j = -1;
        while (++j < 44)
            std::cout << "-";
        std::cout << "\n";
    }
}

void PhoneBook::searchContact(int index)
{
    int i;

    i = -1;
    while (this->contacts[++i].getIndex() != -1 && i < 8)
    {
        if (i == index)
        {
            this->contacts[i].getAllInfo();
            return ;
        }
    }
    std::cout << "Contact not found !!";
}