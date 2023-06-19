/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:46:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 13:46:07 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog( const Dog &copy );
    ~Dog();

    Dog &operator = (const Dog &copy );

    void makeSound() const;
};


# endif