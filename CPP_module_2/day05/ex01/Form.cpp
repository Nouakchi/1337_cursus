/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:47:19 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 11:22:49 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : name("unknown") , is_signed(0) , signed_grade(1) , execute_grade(1) {}

Form::Form( const std::string name , const int s_grade , const int e_grade ) :
                name(name) , is_signed(0) , signed_grade(s_grade) , execute_grade(e_grade)
{
    if (signed_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
    if (signed_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form( const Form &other ) : name(other.name) , is_signed(other.is_signed) , signed_grade(other.signed_grade) , execute_grade(other.execute_grade) {}

Form::~Form() {}

Form &Form::operator = ( const Form &other )
{
    this->is_signed = other.is_signed;
    return (*this);
}

const std::string &Form::getName() const { return this->name; }
bool Form::getIsSigned() const { return this->is_signed; }
int Form::getSigneGrade() const { return this->signed_grade; }
int Form::getExecuteGrade() const { return this->execute_grade; }

void Form::setSigned(bool sign) { this->is_signed = sign;}

void Form::beSigned( Bureaucrat &b )
{
    if (this->signed_grade > b.getGrade())
        throw Form::GradeTooLowException();
    else
        this->is_signed = 1;
}   

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low.\n";
}
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high.\n";
}

std::ostream &operator<< ( std::ostream &os, const Form &b )
{
    std::cout <<  b.getName() << " signed = " << b.getIsSigned() << " signed grade = " << b.getSigneGrade() << " execute grade = " << b.getExecuteGrade() <<  "\n";
    return (os);
}