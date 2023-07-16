/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:57:05 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 15:47:22 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
 
class Bureaucrat;

AForm::AForm() : name("unknown") , is_signed(false) , signed_grade(1) , execute_grade(1) {}

AForm::AForm( const std::string name , const int s_grade , const int e_grade ) 
: name(name) , is_signed(false) , signed_grade(s_grade) , execute_grade(e_grade)
{
    if (signed_grade < 1 || execute_grade < 1)
        throw AForm::GradeTooHighException();
    if (signed_grade > 150 || execute_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm &other ) 
: name(other.name) , is_signed(other.is_signed) , signed_grade(other.signed_grade) , execute_grade(other.execute_grade) 
{}

AForm::~AForm() {}

AForm &AForm::operator = ( const AForm &other )
{
    this->is_signed = other.is_signed;
    return (*this);
}

const std::string &AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->is_signed; }
int AForm::getSigneGrade() const { return this->signed_grade; }
int AForm::getExecuteGrade() const { return this->execute_grade; }

void AForm::beSigned( Bureaucrat &b )
{
    if (this->signed_grade < b.getGrade())
        throw AForm::GradeTooLowException();
    else
        this->is_signed = 1;
}   

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low.\n";
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high.\n";
}
const char* AForm::NotSignedException::what() const throw()
{
    return "Form not signed.\n";
}

std::ostream &operator<< ( std::ostream &os, const AForm &b )
{
    std::cout <<  b.getName() << " signed = " << b.getIsSigned() << " signed grade = " << b.getSigneGrade() << " execute grade = " << b.getExecuteGrade() <<  "\n";
    return (os);
}