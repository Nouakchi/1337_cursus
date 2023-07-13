/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:43:04 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/13 12:44:34 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknow")
{
    this->grade = 149;
}

Bureaucrat::Bureaucrat( const std::string &_name, int _grade ) : name(_name)
{
    this->setGrade(_grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : name(other.name)
{
    this->setGrade(other.grade);
}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat &Bureaucrat::operator = ( const Bureaucrat &other )
{
    this->setGrade(other.grade);
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::increment()
{
    this->setGrade(this->grade - 1);
}

void Bureaucrat::decrement()
{
    this->setGrade(this->grade + 1);
}

std::ostream &operator<< ( std::ostream &os, const Bureaucrat &b )
{
    std::cout << b.getName() + ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}

void Bureaucrat::setGrade( int grade )
{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::signedForm( const std::string name , int const signed_grade ) const
{
    if (this->grade < signed_grade )
        std::cout <<  "Bureaucrat " + this->name + " couldn't sign " + name + " because the ";
    else
        std::cout << "Bureaucrat " + this->name + " signed " + name + " \n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low.\n";
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high.\n";
}