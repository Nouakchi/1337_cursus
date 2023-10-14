/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:17:17 by onouakch          #+#    #+#             */
/*   Updated: 2023/08/12 04:49:10 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __WHATEVER_H__
# define __WHATEVER_H__

#include <iostream>

    
template <class T>
static void swap (T& a, T& b)
{
    T inter = a;
    a = b;
    b = inter;
}

template <class T>
static T min(T& a, T& b)
{
    return ((a < b) ? a : b);
}

template <class T>
static T max(T& a, T& b)
{
    return ((a > b) ? a : b);
}


# endif