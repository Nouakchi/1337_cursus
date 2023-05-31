/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:42:18 by onouakch          #+#    #+#             */
/*   Updated: 2023/05/30 15:24:57 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.h"

int Contact::id = 0;

Contact::Contact(std::string f_name, std::string l_name,
std::string n_name, std::string phone, std::string d_secret)
{
    this->first_name = f_name;
    this->last_name = l_name;
    this->nickname = n_name;
    this->phone_number = phone;
    this->darkest_secret = d_secret;
    if (this->id == 8)
        this->id = 0;
    this->index = this->id++;
}

void Contact::getInfo()
{
    std::cout << resize_data("|" + std::to_string(this->index)) << "|" << resize_data(this->first_name) << "|";
    std::cout << resize_data(this->last_name) << "|" << resize_data(this->nickname) << "|\n";
}

void Contact::getAllInfo()
{
    std::cout << "********* Contact info **********\n";
    std::cout << "First Name: " << this->first_name << std::endl;
    std::cout << "Last Name: " << this->last_name << std::endl;
    std::cout << "Nick Name: " << this->nickname << std::endl;
    std::cout << "Phone Number: " << this->phone_number << std::endl;
    std::cout << "darcest Secret: " << this->darkest_secret << std::endl;
    std::cout << "********* Contact info **********\n";
}

void Contact::setIndex(int value)
{
    this->index = value;
}

int Contact::getIndex()
{
    return (this->index);
}