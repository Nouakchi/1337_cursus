/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:42:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/12 14:30:28 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
 
int main()
{
    try
    {
        Bureaucrat bb("bur", 2);
        
        Form b1;
        Form b2("cor" , 0, 150,1);
        Form b3(b2);
        Form b4 = b3;
        
        std::cout << b1;
        std::cout << b2;
        std::cout << b3;
        std::cout << b4;

        b2.beSigned(bb);

        std::cout << b2;
        
        
    }
    catch( const std::exception& e )
    {
        std::cout << e.what();
    }
    
    return (0);
}