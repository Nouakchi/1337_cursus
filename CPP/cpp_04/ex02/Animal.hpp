/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:45:57 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 16:55:45 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
   std::string type;
    
public:
    Animal();
    Animal( const Animal  &copy );
    virtual ~Animal();

    virtual Animal &operator = ( const Animal &copy );

    std::string getType() const;

    virtual void makeSound() const = 0;
    virtual Brain *getBrain() const = 0;
};



# endif