/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:46:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/12 14:22:59 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __FORM_H__
# define __FORM_H__

# include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int signed_grade;
    const int execute_grade;

public:
    Form();
    Form( const std::string , bool , const int , const int );
    Form( const Form &other );
    ~Form();

    Form &operator = ( const Form &other );

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSigneGrade() const;
    int getExecuteGrade() const;

    void beSigned( const Bureaucrat &b );

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