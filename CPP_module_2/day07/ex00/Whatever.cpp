/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:16:57 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/18 10:33:48 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Whatever.hpp"

Whatever::Whatever()
{
}

Whatever::Whatever( const Whatever& copy )
{
    (void)copy;
}

Whatever::~Whatever()
{
}

Whatever& Whatever::operator= ( const Whatever& other )
{
    (void)other;
    return (*this);
}