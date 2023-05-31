/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:42:34 by onouakch          #+#    #+#             */
/*   Updated: 2023/05/30 14:48:02 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
 
class Contact
{
    static int  id;

    private:
        int         index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        
    public:
        Contact(){};
        Contact(std::string, std::string, std::string,
                std::string, std::string);

        void    getInfo();
        void    getAllInfo();
        void    setIndex(int);
        int     getIndex();
};

# endif