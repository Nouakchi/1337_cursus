#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[9];
    int     oldest;
public:
    PhoneBook();
    
    int     addContact(Contact&);
    int     replaceContact(Contact);
    void    displayContacts();
    void    searchContact(int);
};

