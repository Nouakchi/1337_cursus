/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:42:23 by onouakch          #+#    #+#             */
/*   Updated: 2023/05/31 12:48:14 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
public:
    //  default constructor
    PhoneBook();
    
    //  destructor
    ~PhoneBook(){};
    
    // member functions
    int     addContact(Contact&);
    void    displayContacts();
    void    searchContact(int);
    
private:
    Contact contacts[9];
    int     oldest;
};

# endif