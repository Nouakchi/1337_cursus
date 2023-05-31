#include <iostream>

std::string resize_data(std::string data)
{
    if (data.length() < 10)
        data.resize(data.size() + (10 - data.length()), ' ');
    else if (data.length() > 10)
    {
        data.resize(10);
        data[9] = '.';
    }
    return (data);
}