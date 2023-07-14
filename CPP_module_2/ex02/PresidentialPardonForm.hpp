/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othman <othman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:53:18 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/14 17:47:34 by othman           ###   ########.fr       */
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