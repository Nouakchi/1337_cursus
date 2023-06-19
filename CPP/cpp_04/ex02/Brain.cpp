/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:53:06 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/19 16:43:42 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain is created \n";
}

Brain::Brain( const Brain &copy )
{
    *this = copy;
    std::cout << "Brain copy constructor is called\n";
}

Brain &Brain::operator=( const Brain &copy )
{
    int i = -1;
    while (++i < 100)
        this->ideas[i] = copy.ideas[i];
    std::cout << "Brain copy assignement is called\n";
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain is destroyed\n";
}