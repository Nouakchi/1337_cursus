/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:55:28 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/14 15:38:23 by othman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __SHRUBBERY_CREATION_FORM__
# define __SHRUBBERY_CREATION_FORM__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm( std::string target );
    
    ShrubberyCreationForm &operator = (const ShrubberyCreationForm& other);
    
    ~ShrubberyCreationForm();

    void execute( Bureaucrat const & executor) const;
};



# endif