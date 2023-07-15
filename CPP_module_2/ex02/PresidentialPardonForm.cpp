/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:53:03 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 11:33:29 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Default", 25, 5)
{
    this->target = "unknow";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy.getName(), copy.getSigneGrade(), copy.getExecuteGrade())
{
    this->target = copy.target;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: AForm("Default", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm& other)
{
    this->target = other.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor ) const
{
    if(this->getIsSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    else
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}