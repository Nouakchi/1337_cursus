/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:42:20 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 15:41:27 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main()
{
    try
    {
        std::srand(time(nullptr));
        
        Intern someRandomIntern;
        
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        
        delete rrf;
        
    }
    catch( const std::exception& e )
    {
        std::cout << e.what();
    }
    
    return (0);
}