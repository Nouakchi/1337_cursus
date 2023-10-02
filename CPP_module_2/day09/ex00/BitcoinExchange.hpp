/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:30:00 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/02 09:54:23 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __BITCOIN_EXCHANGE_H__
# define __BITCOIN_EXCHANGE_H__

# include <iostream>
# include <fstream>
#include <ctime>
# include <map>

class BitcoinExchange
{
private:
public:
    std::map<time_t , double> data;
    BitcoinExchange();
    BitcoinExchange( const BitcoinExchange& copy );
    ~BitcoinExchange();

    BitcoinExchange &operator= ( const BitcoinExchange& other );
    
    static bool parseDate( char *date );
    static bool parseLine( std::string line );
    void        setData( std::string path );
    std::map<time_t, double>    getData( );
    void      getDateValue( time_t date, double value);
    static time_t parseDateTime(const char* datetimeString, const char* format);
};





# endif