/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:46:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/14 12:00:50 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __FORM_H__
# define __FORM_H__

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int signed_grade;
    const int execute_grade;

public:
    Form();
    Form( const std::string , const int , const int );
    Form( const Form &other );
    ~Form();

    Form &operator = ( const Form &other );

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSigneGrade() const;
    int getExecuteGrade() const;

    void setSigned(bool);

    void beSigned( Bureaucrat &b );

    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream &operator << ( std::ostream &os , const Form &b );

# endif