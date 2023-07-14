/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:55:11 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/14 18:03:50 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
: AForm("default", 145, 137)
{
    this->target = "unknow";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) 
: AForm(copy.getName() , copy.getSigneGrade() , copy.getExecuteGrade())
{
    this->target = copy.target;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
: AForm("Shrub", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other)
{
    this->target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if(this->getIsSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::string ascii_tree = 
        "       _-_       \n" 
        "    /~~   ~~\\   \n" 
        " /~~         ~~\\\n" 
        "{               }\n" 
        " \\  _-     -_  /\n" 
        "   ~  \\ //  ~   \n" 
        "_- -   | | _- _  \n" 
        "  _ -  | |   -_  \n" 
        "      // \\      \n";
        std::string filename = this->target + "_shrubbery";
        std::ofstream myfile (filename);
        if (myfile.is_open())
            std::cout << ascii_tree;
        else
            std::cout << "enable to open file\n";
    }
}