/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:44:48 by onouakch          #+#    #+#             */
/*   Updated: 2023/07/17 15:53:14 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __UTILS_H__
# define __UTILS_H__

#include <ctime>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class Utils
{
public:
    Utils();
    Utils( const Utils& copy );
    ~Utils();
    
    Utils& operator= ( const Utils& other );
    
    static Base * generate(void);
    static void identify(Base* p);
    static void identify(Base& p);
};


# endif