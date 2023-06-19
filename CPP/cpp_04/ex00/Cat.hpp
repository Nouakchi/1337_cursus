/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:46:02 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 13:46:03 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat( const Cat &copy );
    ~Cat();

    Cat &operator = (const Cat &copy );

    void makeSound() const;
};


# endif