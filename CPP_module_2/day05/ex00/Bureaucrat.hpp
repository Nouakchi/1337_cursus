/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:44:15 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/11 12:24:47 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

#include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
    
    void setGrade( int grade );

public:
    Bureaucrat();
    Bureaucrat( const std::string &name, int grade );
    Bureaucrat( const Bureaucrat &other );
    ~Bureaucrat();

    Bureaucrat &operator = ( const Bureaucrat &other );

    const std::string &getName() const;
    int getGrade() const;
    
    void increment();
    void decrement();
    
    class GradeTooLowException : public std::exception{
        public :
            const char* what() const throw();
    };
    class GradeTooHighException : public std::exception{
        public :
            const char* what() const throw();
    };
};

std::ostream &operator << ( std::ostream &os , const Bureaucrat &b );

# endif