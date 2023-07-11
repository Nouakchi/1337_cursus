/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:42:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/11 13:32:19 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1;
        Bureaucrat b2("cor" , 2);
        Bureaucrat b3(b2);
        Bureaucrat b4 = b3;
        
        b1.decrement();

        std::cout << b1;
        std::cout << b2;
        std::cout << b3;
        std::cout << b4;
        
        b2.increment();
        b3.decrement();
        std::cout << b2.getGrade() << std::endl;

        b2.increment();
        
    }
    catch( const std::exception& e )
    {
        std::cout << e.what();
    }
    
    return (0);
}