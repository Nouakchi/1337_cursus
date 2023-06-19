/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:46:02 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 18:53:45 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;
public:
    Cat();
    Cat( const Cat &copy );
    ~Cat();

    Cat &operator = ( const Animal &copy );

    void makeSound() const;
    Brain *getBrain() const;
};


# endif