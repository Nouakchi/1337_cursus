/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:55:11 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 10:43:57 by onouakch         ###   ########.fr       */
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
        std::string file = this->target + "_shrubbery";
        char filename[file.length() + 1];
        long unsigned int i = -1;
        while(++i <= file.length())
            filename[i] = file[i];
        filename[i] = '\0';
        std::ofstream myfile (filename);
        if (myfile.is_open())
            std::cout << ascii_tree;
        else
            std::cout << "enable to open file\n";
    }
}