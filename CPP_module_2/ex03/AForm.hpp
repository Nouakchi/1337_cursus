/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:52:48 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 15:37:23 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __AFORM_H__
# define __AFORM_H__

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool is_signed;
    const int signed_grade;
    const int execute_grade;

public:
    AForm();
    AForm( const std::string , const int , const int );
    AForm( const AForm &other );
    virtual ~AForm();

    AForm &operator = ( const AForm &other );

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSigneGrade() const;
    int getExecuteGrade() const;

    void beSigned( Bureaucrat &b );

    virtual void execute(Bureaucrat const & executor ) const = 0;

    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };
    class NotSignedException : public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream &operator << ( std::ostream &os , const AForm &b );

# endif