/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:14 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 11:36:52 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default" , 72, 45)
{
    this->target = "unknown";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) 
: AForm(copy.getName() , copy.getSigneGrade(), copy.getExecuteGrade())
{
    this->target = copy.target;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
: AForm("Default" , 72, 45)
{
    this->target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm& other)
{
    this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const char* RobotomyRequestForm::FailureException::what() const throw()
{
    return ("the robotomy failed\n");
}

void RobotomyRequestForm::execute( Bureaucrat const & executor) const
{
    if(this->getIsSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << "some drilling noises\n";
    int check = std::rand() % 2;
    if (check)
        std::cout << this->target << " has been robotomized\n";
    else
        throw RobotomyRequestForm::FailureException();
}