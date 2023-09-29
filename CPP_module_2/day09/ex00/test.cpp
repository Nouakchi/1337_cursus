// C++ Program to implement Date and Time parsing using
// <ctime>
#include <ctime>
#include <iostream>
using namespace std;

// function to parse a date or time string.
time_t parseDateTime(const char* datetimeString, const char* format)
{
	struct tm tmStruct;
	strptime(datetimeString, format, &tmStruct);
	return mktime(&tmStruct);
}

// Function to format a time_t value into a date or time string.
// string DateTime(time_t time, const char* format)
// {
// 	char buffer[90];
// 	struct tm* timeinfo = localtime(&time);
// 	strftime(buffer, sizeof(buffer), format, timeinfo);
// 	return buffer;
// }
int main()
{
    std::string line = "2023-06-17,0";
	char* datetimeString = (char *)line.c_str();
	const char* format = "%Y-%m-%d %H:%M:%S";
	time_t parsedTime = parseDateTime((const char*)datetimeString, format);

    // parseDateTime(
    //                     (const char*)strtok((char*)line.append(" 00:00:00").c_str(), ","),
    //                     "%Y-%m-%d %H:%M:%S"
    //                 )
    char *date = strtok((char*)datetimeString, ",");
    std::cout << date << std::endl;
    std::cout << parseDateTime(
                        (const char*)strcat(date, " 12:36:51"),
                        "%Y-%m-%d %H:%M:%S"
                    ) << std::endl;
	// string formattedTime = DateTime(parsedTime, format);
	// cout << "Parsed Time--> " << parsedTime << endl;
	// cout << "Formatted Time--> " << formattedTime << endl;
	return 0;
}
