/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:46:35 by onouakch          #+#    #+#             */
/*   Updated: 2023/06/24 17:43:55 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __FORM_H__
# define __FORM_H__

# include <iostream>

class Form
{
private:
    const std::string name;
    bool _signed;
    const int sign_grade;
    const int execute_grade;
public:
    Form();
    Form( const Form &other );
    ~Form();

    Form &operator = ( const Form &other );

    void GradeTooHighException();
    void GradeTooLowException();
};

std::ostream &operator << ( std::ostream &os , const Form &b );

# endif