/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:42:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 15:46:47 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
 
int main()
{
    try
    {
        std::srand(time(nullptr));

        Bureaucrat bb("bur", 2);
        
        PresidentialPardonForm ppf("Home");
        RobotomyRequestForm rrf("house");
        ShrubberyCreationForm srf("forest");
        
        bb.signForm(ppf);

        bb.executeForm(ppf);
        
        bb.signForm(rrf);

        bb.executeForm(rrf);

        bb.signForm(srf);
        
        bb.executeForm(srf);
        
    }
    catch( const std::exception& e )
    {
        std::cout << e.what();
    }
    
    return (0);
}