/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:10:50 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 15:22:20 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __INTERN_H__
# define __INTERN_H__

#include "AForm.hpp"

class Intern
{
private:
    /* data */
public:
    Intern();
    Intern( const Intern& copy );
    ~Intern();
    
    Intern& operator = (const Intern& other);
    
    AForm *makeForm( std::string, std::string );
};


# endif