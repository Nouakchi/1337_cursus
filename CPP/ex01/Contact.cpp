#include "Contact.hpp"

int Contact::id = 0;

Contact::Contact(std::string f_name, std::string l_name,
std::string n_name, std::string phone, std::string d_secret)
{
    this->first_name = f_name;
    this->last_name = l_name;
    this->nickname = n_name;
    this->phone_number = phone;
    this->darkest_secret = d_secret;
    this->id++;
}

void Contact::getInfo()
{
    std::cout << "********* Contact info **********\n";
    std::cout << "First Name: " << this->first_name << std::endl;
    std::cout << "Last Name: " << this->last_name << std::endl;
    std::cout << "Nick Name: " << this->nickname << std::endl;
    std::cout << "Phone Number: " << this->phone_number << std::endl;
    std::cout << "darcest Secret: " << this->darkest_secret << std::endl;
    std::cout << "********* Contact info **********\n";
}

void Contact::setId(int value)
{
    this->id = value;
}

int Contact::getId()
{
    return (this->id);
}