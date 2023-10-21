/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouakch <onouakch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:30:02 by onouakch          #+#    #+#             */
/*   Updated: 2023/10/21 20:35:19 by onouakch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &copy ) 
{
    (void)copy;
}

BitcoinExchange &BitcoinExchange::operator= ( const BitcoinExchange& other )
{
    (void)other;
    return (*this);
}

time_t parseDateTime_1(const char* datetimeString, const char* format)
{
    struct tm tmStruct;
    strptime(datetimeString, format, &tmStruct);
    return mktime(&tmStruct);
}

void    BitcoinExchange::setData( std::string path )
{
    std::ifstream   data;
    std::string     line;
    char      *key;
    double          value;

    data.open(path.c_str());
    if (data.is_open())
    {
        getline(data, line);
        while (getline(data, line))
        {
            key = strtok((char *)line.c_str(), ",");
            value = atof((const char*)strtok(NULL, ","));
            this->data.insert(
                std::pair<time_t,double>(
                    parseDateTime_1(
                        (const char*)strcat(key, " 00:00:00"),
                        "%Y-%m-%d %H:%M:%S"
                        ),
                    value
                )
            );
        }
        data.close();
    }
}

std::map<time_t, double>    BitcoinExchange::getData( )
{
    return (this->data);
}

void BitcoinExchange::getDateValue( time_t date, double value )
{
    std::map<time_t, double>::iterator  it;
    double                              tmp;
    
    tmp = -1;
    for (it=this->data.begin();it!=this->data.end();++it)
    {
        if (date == it->first)
        {
            std::cout << it->second * value << std::endl;
            return ;
        }
        if (date > it->first)
            tmp = it->second;
    }
    std::cout << value * tmp << std::endl;
}

int isNumeric( char *str )
{
    if (std::strlen(str) < 2)
        return (0);
    int i = -1;
    while (str[++i])
    {
        if (!std::isdigit(str[i]))
            return (0);   
    }
    return (atoi(str));
}



bool isDate( int year, int month, int day)
{
    if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if (year == 2009 && day < 2)
        return (false);
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!(year % 400) || (!(year % 4) && year % 100 ))
        daysInMonths[2] = 29;
    return ( day <= daysInMonths[month]);
}

bool BitcoinExchange::parseDate( char *date )
{
    if (std::strlen(date) != 10)
        return (0);
    int dash_count = 0, i = -1;
    while (date[++i])
        if (date[i] == '-')
            dash_count++;
    if (dash_count != 2)
        return (0);
    std::string tmp = date;
    int year = isNumeric(strtok((char*)tmp.c_str(), "-"));
    int month = isNumeric(strtok(NULL, "-"));
    int day = isNumeric(strtok(NULL, "-"));
    if (!year || !month || !day || !isDate(year, month, day))
        return (0);
    return (1);
}

double isFloat( char *value )
{
    int i = std::strlen(value);
    bool contain_digit = false;
    int contain_dot = 0;
    int contain_f = 0;
    if (value[i - 1] == 'f' || value[i - 1] == 'F')
    {
        i--;
        contain_f = 1;
    }
    if (value[0] == '-')
        return (std::cout << "Error: not a positive number.\n" , -1);
    int j = (value[0] == '+') ? 0 : -1;
    while (++j < i)
    {
        if (!isdigit(value[j]))
        {
            if (value[j] == '.' && ++contain_dot <= 1)
                continue;
            else
                return (std::cout << "Error: bad input => " << value << std::endl, -1);
        }
        else
            contain_digit = true;
    }
    if (!contain_digit || (contain_f && !contain_dot))
        return (std::cout << "Error: bad input => " << value << std::endl, -1);
    return (atof((char*)value));
}

bool BitcoinExchange::parseLine( std::string line )
{
    size_t pipe_count = 0, i = -1;
    while (++i < line.length())
        if (line[i] == '|')
            pipe_count++;
    if (pipe_count != 1)
        return (std::cout << "Error: bad input => |" << std::endl, 0);
    char *date = strtok((char*)line.c_str(), " |\t");
    char *value = strtok(NULL, " |\t");
    char *tmp = strtok(NULL, " |\t");
    if (!date)
        return (std::cout << "Error: bad input => " << std::endl, 0);
    if (!parseDate(date))
        return (std::cout << "Error: bad input => " << date << std::endl, 0);
    if (!value)
        return (std::cout << "Error: bad input => " << std::endl, 0);
    if (tmp)
        return (std::cout << "Error: bad input => " << tmp << std::endl, 0);
    double btc_value = isFloat(value);
    if (btc_value < 0)
        return (0);
    if (btc_value > 1000)
        return (std::cout << "Error: too large a number.\n", 0);
    std::cout << date <<" => "<< btc_value << " = ";
    return (1);
}
