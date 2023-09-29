#include <iostream>
#include <sstream>
#include <ctime>

int main() {
    std::string dateString = "2023-1-20";
    std::tm date1 = {};  // Initialize to all zeros

    std::istringstream ss(dateString);
    char delimiter;

    // Parse year, month, day components
    ss >> date1.tm_year >> delimiter
       >> date1.tm_mon >> delimiter
       >> date1.tm_mday;

    if (ss.fail() )
        return (std::cout << "Date parsing failed." << std::endl, 1);

    date1.tm_year -= 1900;  // Years since 1900
    // date1.tm_mon -= 1;      // Months are 0-based
    // std::tm date1 = {0, 0, 0,
    //                  19, 1, 1900 - 1900};
    std::tm date2 = {0, 0, 0,
                     19, 1, 2023 - 1900};

    std::time_t time1 = std::mktime(&date1);
    std::time_t time2 = std::mktime(&date2);

    double difference =  std::difftime(time2, time1);

    if (difference > 0) {
        std::cout << "Date 2 is later than Date 1." << std::endl;
    } else if (difference < 0) {
        std::cout << "Date 1 is later than Date 2." << std::endl;
    } else {
        std::cout << "Date 1 and Date 2 are the same." << std::endl;
    }

    // Adjust year and month values as per the tm structure

    // Convert the std::tm structure to a time_t value
    // std::time_t date = std::mktime(&timeInfo);

    // Print the converted time_t value
    // std::cout << "Time in seconds since epoch: " << timeInfo.tm_mon << std::endl;

    return 0;
}
