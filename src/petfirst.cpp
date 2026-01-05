#include "Petfirst.h"

Pet::Pet(){
    name = "";
    DOB.day = 0;   // Set the day
    DOB.month = 0; // Set the month
    DOB.year = 0;  // Set the year
    type = "";
    breed = "";
}

Pet::Pet(const std::string& n, const Date& d, const int& t, const std::string& b){
    name = n;
    DOB = d;
    setPetType(t);
    breed = b;
}

std::string Pet::getPetName(){
    for (char& c : name) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return name;
}

Date Pet::getPetDOB(){
    
    return DOB;
}



std::string Pet::getPetType(){
    for (char& c : type) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return type;
}

std::string Pet::getPetBreed(){
    for (char& c : breed) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return breed;
}

void Pet::setPetName(const std::string& n){
    name = n;
    for (char& c : name) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
}

void Pet::setPetDOB(const int& d, const int& m, const int& y){
    DOB.day = d;   // Set the day
    DOB.month = m; // Set the month
    DOB.year = y;  // Set the year
}

void Pet::setPetType(const int& t){
    switch (t){
    case 1:
        type = "DOG";
        break;
    case 2:
        type = "CAT";
        break;
    case 3:
        type = "BIRD";
        break ;
    case 4:
        type = "SNAKE";
        break ;
    default:
        std::cout << "Enter the type of pet you have:\n";
        std::getline(std::cin,type);
        for (char& c : type) {
            if (c >= 'a' && c <= 'z'){
                c -= 32;
            }
        }
        break;
    }
}
void Pet::setPetBreed(const std::string& b){
    breed = b;
    for (char& c : breed) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
}

std::ostream& operator<<(std::ostream& os, Pet& pet) {
    os.setf(std::ios::left);

    os << std::setw(14) << "NAME" << " : " << std::setw(18) << pet.getPetName() << std::endl;
    os << std::setw(14) << "DOB" << " : " << std::setw(18) << pet.getPetDOB().dateString() << std::endl;
    os << std::setw(14) << "TYPE" << " : " << std::setw(18) << pet.getPetType() << std::endl;
    os << std::setw(14) << "BREED" << " : " << std::setw(18) << pet.getPetBreed() << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Pet& pet) {
    std::string name;
    int month,day,year,typeNum;
    std::string typeName, breed;

    std::getline(is,name);

    if(!(is >> month >> day >> year)){
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> typeNum)){
        is.setstate(std::ios::failbit);
        return is;
    }

    if (typeNum < 1 || typeNum > 4){
        is.ignore();
        std::getline(is,typeName);
    }

    is.ignore();
    std::getline(is,breed);

    pet.setPetName(name);
    pet.setPetDOB(day,month,year);
    pet.setPetBreed(breed);
    pet.setPetType(typeNum);

    return is;
}