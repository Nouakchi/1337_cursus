/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:46:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 18:45:24 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog( const Dog &copy );
    ~Dog();

    Dog& operator=(const Animal& other);
    
    void makeSound() const;
    Brain *getBrain() const;
};


# endif