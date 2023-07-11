/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:42:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/24 15:48:33 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1;
        Bureaucrat b2("cor" , 1);
        Bureaucrat b3(b2);
        Bureaucrat b4 = b3;
        
        std::cout << b1;
        std::cout << b2;
        std::cout << b3;
        std::cout << b4;
        
        b1.decrement();
        b2.increment();
        b3.decrement();
        std::cout << b3.getGrade() << std::endl;
        
    }
    catch(std::string excp)
    {
        std::cout << excp;
    }
    
    return (0);
}