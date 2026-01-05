#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> 

class Address{
    friend std::ostream& operator<<(std::ostream& os, Address& addr);
    friend std::istream& operator>>(std::istream& is, Address& addr);

    private:
        std::string street;
        std::string city;
        std::string state;
        size_t zipCode;
    public:
        Address();
        Address(const std::string&, const std::string&, const std::string&, const size_t&);
        std::string getStreetName();
        std::string getCityName();
        std::string getStateName();
        size_t getZipCode();

        void setStreetName(const std::string&);
        void setCityName(const std::string&);
        void setStateName(const std::string&);
        void setZipCode(const size_t&);

};



#endif