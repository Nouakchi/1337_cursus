/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:10:47 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 15:40:09 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern& other )
{
    (void)other;
}

Intern& Intern::operator= (const Intern& other )
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm( std::string formName , std::string formTarget )
{
    std::string forms[] = { "presidential pardon", "robotomy request" , "shrubbery creation"};
    int i = -1;
    while (++i < 3)
        if (forms[i] == formName)
            break;
    AForm *res = NULL;
    Bureaucrat bb("bureaucrat", 2);
    switch (i)
    {
    case 0:
        res = new PresidentialPardonForm(formTarget);
        break;
    case 1:
        res = new RobotomyRequestForm(formTarget);
        break;
    case 2:
        res = new ShrubberyCreationForm(formTarget);
        break;
    default:
        std::cout << "Form not found !!\n";
        break;
    }
    if (i < 3)
    {
        std::cout << "Intern creates " << formName << " \n";
        bb.signForm(*res);
        res->execute(bb);
    }
    return (res);
}