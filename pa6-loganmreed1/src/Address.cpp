#include "Address.h"

Address::Address(){
    street = "";
    city = "";
    state = "";
    zipCode = 0;
}

Address::Address(const std::string& str, const std::string& c, const std::string& sta, const size_t& z){
    street = str;
    city = c;
    state = sta;
    zipCode = z;
}

std::string Address::getStreetName(){
    for (char& c : street) { 
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return street;
}
std::string Address::getCityName(){
    for (char& c : city) { 
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return city;
}
std::string Address::getStateName(){
    for (char& c : state) { 
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return state;
}
size_t Address::getZipCode(){
    return zipCode;
}

void Address::setStreetName(const std::string& str){
    street = str;
}
void Address::setCityName(const std::string& c){
    city = c;
}

void Address::setStateName(const std::string& sta) {
    state = sta;
}
void Address::setZipCode(const size_t& z){
    zipCode = z;
}


std::ostream& operator<<(std::ostream& os, Address& addr) {
    std::string street = addr.street, city = addr.city, state = addr.state;
    std::transform(street.begin(), street.end(), street.begin(), ::toupper);
    std::transform(city.begin(), city.end(), city.begin(), ::toupper);
    std::transform(state.begin(), state.end(), state.begin(), ::toupper);

    os << std::left << std::setw(14) << "STREET" << ":" << std::right << std::setw(20) << street << std::endl;
    os << std::left << std::setw(14) << "CITY" << ":" << std::right << std::setw(20) << city << std::endl;
    os << std::left << std::setw(14) << "STATE" << ":" << std::right << std::setw(20) << state << std::endl;
    os << std::left << std::setw(14) << "ZIP CODE" << ":" << std::right << std::setw(20) << addr.zipCode << std::endl;

    return os;
}


std::istream& operator>>(std::istream& is, Address& addr) {
    std::getline(is, addr.street);
    std::getline(is, addr.city);
    std::getline(is, addr.state);
    is >> addr.zipCode;
    is.ignore(); // Ignore the newline left in the input buffer after zipCode
    auto capitalize = [](std::string& str) {
        bool newWord = true;
        for (char& c : str) { 
            if (newWord && c >= 'a' && c <= 'z') {
                c -= 32;  // Convert to uppercase
                newWord = false;
            }else if (newWord && c >= 'a' && c <= 'z') {
                c -= 32;  // Convert to uppercase
            }
            if (c== ' ') newWord = true;

        }
    };

    capitalize(addr.street);
    capitalize(addr.city);
    capitalize(addr.state);

    return is;
}