/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:49:01 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/17 14:44:11 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *ptr1 = new Data, *ptr2 = NULL;
    ptr2 = Serializer::deserialize(Serializer::serialize(ptr1));
    if (ptr1 == ptr2) 
        std::cout << "ptr2 equal to the original one (ptr1) \n";
    else
        std::cout <<  "they are not equal\n";
    std::cout << "ptr1 => [" << ptr1 << "]\n";
    std::cout << "ptr2 => [" << ptr2 << "]\n";
    delete ptr1;
    return (0);
}