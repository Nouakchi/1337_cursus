#include <iostream>
#include <string>

class Contact
{
    private:
        static int  id;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact(){};
        Contact(std::string, std::string, std::string,
         std::string, std::string);

        void getInfo();
        void setId(int);
        int getId();
};

