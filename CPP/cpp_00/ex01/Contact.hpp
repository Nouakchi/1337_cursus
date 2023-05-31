/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:42:34 by onouakch          #+#    #+#             */
/*   Updated: 2023/05/31 12:47:19 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __CONTACT_H__
# define __CONTACT_H__

#include <iostream>
#include <string>
 
class Contact {
public:

    static int  id;
    
    //  default constructor
    Contact(){};
    
    //  constructor with parameters
    Contact(std::string, std::string, std::string,
            std::string, std::string);
            
    //  destructor
    ~Contact(){};
    
    // member functions
    void    getInfo();
    void    getAllInfo();
    void    setIndex(int);
    int     getIndex();
    
private:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};

# endif