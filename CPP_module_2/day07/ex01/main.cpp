/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:16:38 by onouakch          #+#    #+#             */
/*   Updated: 2023/08/12 04:48:39 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void ) 
{
    char arr[3] = "ab";
    ::iter(arr, 2 , toupper);
    std::cout << arr << "\n";
    return 0;
}