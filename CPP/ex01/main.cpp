/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:42:12 by onouakch          #+#    #+#             */
/*   Updated: 2023/05/31 10:27:48 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool check_number(std::string str) 
{
    for (size_t i = 0; i < str.length(); i++)
        if (std::isdigit(str[i]) == false)
            return false;
    return true;
}

int main()
{
    PhoneBook book;

    std::string user_index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    std::string res;

    do
    {
        std::system("clear");
        std::cout << "******* WELCOME TO THE 80's *******\n";
        std::cout << "Write :\n";
        std::cout << "[ADD] => add a new contact\n";
        std::cout << "[SEARCH] => to search for a contact\n";
        std::cout << "[EXIT] => to exit the program\n";
        std::cout << "Choice: ";
        std::getline(std::cin, res);
        if (std::cin.eof())
        {
            std::cin.clear();
            std::fclose(stdin);
            std::fopen("/dev/tty", "r");
            continue;
        }
        if (res != "ADD" && res != "SEARCH" && res != "EXIT")
        {
            std::cout << "Bad input !!";
            std::getline(std::cin, res);
            continue;
        }
        if (res == "ADD")
        {
            std::cout << "First Name: ";
            std::getline(std::cin,first_name);
            std::cout << "Last Name: ";
            std::getline(std::cin,last_name);
            std::cout << "Nick Name: ";
            std::getline(std::cin,nickname);
            std::cout << "Phone Number: ";
            std::getline(std::cin,phone_number);
            std::cout << "Darkest secret: ";
            std::getline(std::cin,darkest_secret);
            if (!first_name.empty() && !last_name.empty() && !nickname.empty() && !phone_number.empty() 
                && !darkest_secret.empty())
            {
                Contact   contact(first_name, last_name, nickname, phone_number, darkest_secret);
                book.addContact(contact);
                std::cout << "Saved Contact !!";
                std::getline(std::cin, res);
            }
            else
            {
                std::cout << "Empty field !!";
                std::getline(std::cin, res);
            }
        }
        else if (res == "SEARCH")
        {
            book.displayContacts();
            std::cout << "Index: ";
            std::getline(std::cin, user_index);
            if (!user_index.empty() && check_number(user_index))
            {
                if (std::stoi(user_index) < 8 && std::stoi(user_index) > -1)
                    book.searchContact(std::stoi(user_index));
                else
                    std::cout << "Invalid index !!, click ENTER to continue.";
            }
            else
                std::cout << "Invalid index !!, click ENTER to continue.";
            std::getline(std::cin, res);
        }
    } while (res != "EXIT");
    return (0);
}