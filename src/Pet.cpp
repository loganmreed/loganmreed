#include "Pet.h"

Pet::Pet(){
    name = "";
    DOB = Date();
    type = "";
    breed = "";

    transformer();
}

Pet::Pet(const std::string& n, const Date& d, const int& t, const std::string& b){
    name = n;
    DOB = d;
    breed = b;
    setPetType(t);

    transformer();
}

std::string Pet::getPetName(){
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    return name;
}

Date Pet::getPetDOB(){
    
    return DOB;
}

std::string Pet::getPetType(){
    std::transform(type.begin(), type.end(), type.begin(), ::toupper);
    return type;
}

std::string Pet::getPetBreed(){
    std::transform(breed.begin(), breed.end(), breed.begin(), ::toupper);
    return breed;
}

void Pet::setPetName(const std::string& petName) {
    name = petName;
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
}

void Pet::setPetDOB(const int& month, const int& day, const int& year) {
    if (month < 1 || month > 12) {
        throw "Month must be between 1 and 12.";
    }
    DOB = Date(month,day,year);
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
        std::transform(type.begin(), type.end(), type.begin(), ::toupper);
        break;
    }
}

void Pet::setPetBreed(const std::string& petBreed) {
    breed = petBreed;
    std::transform(breed.begin(), breed.end(), breed.begin(), ::toupper);
}

std::istream& operator>>(std::istream& in, Pet& pet) {
    std::getline(in, pet.name);  // Read name

    int month, day, year;
    in >> month >> day >> year;  // Read DOB
    pet.setPetDOB(month, day, year);

    int petType;
    in >> petType;  // Read pet type as an integer
    in.ignore();  // Consume newline left in buffer

    if (petType < 1 || petType > 4) {  
        std::getline(in, pet.type);  // Read custom type name if needed
        std::transform(pet.type.begin(), pet.type.end(), pet.type.begin(), ::toupper);
    } else {
        pet.setPetType(petType);  // Normal case
    }

    std::getline(in, pet.breed);  // Read breed
    pet.setPetBreed(pet.breed);

    return in;
}



std::ostream& operator<<(std::ostream& out, Pet& pet) {
    out << std::left << std::setw(14) << "NAME"  << ":" << std::right << std::setw(20) << pet.name  << "\n"
        << std::left << std::setw(14) << "DOB"   << ":" << std::right << std::setw(20) << pet.DOB.dateString() << "\n"
        << std::left << std::setw(14) << "TYPE"  << ":" << std::right << std::setw(20) << pet.type  << "\n"
        << std::left << std::setw(14) << "BREED" << ":" << std::right << std::setw(20) << pet.breed << "\n";

    return out;
}


void Pet::transformer(){
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    std::transform(type.begin(), type.end(), type.begin(), ::toupper);
    std::transform(breed.begin(), breed.end(), breed.begin(), ::toupper);
}