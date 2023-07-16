/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:53:18 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/15 11:25:48 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __PRESIDENTIAL_PARDON_FORM__
# define __PRESIDENTIAL_PARDON_FORM__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm( std::string target );
    
    PresidentialPardonForm &operator = (const PresidentialPardonForm& other);
    
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor ) const;
};


# endif