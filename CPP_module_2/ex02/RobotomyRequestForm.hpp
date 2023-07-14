/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:24 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/14 17:30:44 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __ROBOT_MY_REQUEST_FORM__
# define __ROBOT_MY_REQUEST_FORM__

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm( std::string target );
    
    RobotomyRequestForm &operator = (const RobotomyRequestForm& other);
    
    ~RobotomyRequestForm();
    
    void execute( Bureaucrat const & executor) const;

    class FailureException : std::exception
    {
        public:
            const char* what() const throw();
    };
};


# endif