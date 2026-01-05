#include "Person.h"

Person::Person(){
    fName = "";
    lName = "";
    address = Address();
}

Person::Person(const std::string& firstName, const std::string& lastName, const Address& address){
    fName = firstName;
    lName = lastName;
    this->address = address;
}

Person::Person(const std::string& firstName, const std::string& lastName){
    fName = firstName;
    lName = lastName;
}


std::string Person::getFirstName(){
    for (char& c : fName) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return fName;
}
std::string Person::getLastName(){
    for (char& c : lName) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
    return lName;
}
Address& Person::getAddress(){
    return address;
}
std::vector<Pet*>& Person::getPets(){
    return pets;
}

void Person::setFirstName(const std::string& f){
    fName = f;
    for (char& c : fName) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
}
void Person::setLastName(const std::string& l){
    lName = l;
    for (char& c : lName) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Convert to uppercase
        }
    }
}
void Person::setAddress(const Address& a){
    this->address = a;
}

void Person::setStreetName(const std::string& str){
    address.setStreetName(str);
}
void Person::setCityName(const std::string& c){
    address.setCityName(c);
}
void Person::setStateName(const std::string& sta){
    address.setStateName(sta);
}
void Person::setZipCode(const size_t& z){
    address.setZipCode(z);
}

bool Person::searchPet(const std::string& sp){
    std::string SearchName = sp;
    std::transform(SearchName.begin(), SearchName.end(), SearchName.begin(), ::toupper);

    for (Pet* pet : pets){
        std::string petName = pet->getPetName();
        std::transform(petName.begin(), petName.end(), petName.begin(), ::toupper);
        
        if (petName == SearchName) {
            return true;
        }
    }
    return false;
}

/* void Person::addPet(){
    Pet* newPet = new Pet();

    std::cin >> *newPet;

    std::string petName = newPet->getPetName();
    std::transform(petName.begin(), petName.end(), petName.begin(), ::toupper);

    newPet->setPetName(petName);

    if (searchPet(newPet->getPetName())) {
        delete newPet;
        throw "Pet with same name already exists.";
    }

    operator+(pets, newPet);
}
 */

 void Person::addPet(){
    Pet* newPet = new Pet();

    std::cin >> *newPet;
    std::string petName = newPet->getPetName();
    std::transform(petName.begin(),petName.end(),
    petName.begin(),::toupper);

    newPet->setPetName(petName);

    if (searchPet(newPet->getPetName())) {
        delete newPet;
        throw "Pet with same name already exists.";
    }
    operator+(pets, newPet);
}


std::string Person::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void Person::deletePet(){
    std::string petName;
    std::getline(std::cin >> std::ws, petName); // Read full name, trimming leading whitespace

    petName = trim(petName);
    std::transform(petName.begin(), petName.end(), petName.begin(), ::toupper);

    if (!searchPet(petName)) {
        throw "Pet not found.";
    }

    //std::cout << "Deleting pet: " << petName << std::endl; // Debugging output
    operator-(pets, petName);
}

void operator+(std::vector<Pet*>& pets, Pet* pet){
    pets.push_back(pet);
}

void operator-(std::vector<Pet*>& pets, const std::string& petName) {
    auto it = std::find_if(pets.begin(), pets.end(), [&](Pet* pet) {
        std::string storedName = pet->getPetName();
        std::transform(storedName.begin(), storedName.end(), storedName.begin(), ::toupper);
        return storedName == petName;
    });

    if (it != pets.end()) {
        //std::cout << "Found pet: " << (*it)->getPetName() << ", deleting..." << std::endl; // Debugging output
        delete *it;
        *it = nullptr; // Prevent dangling pointer
        pets.erase(it);
    }
}



std::ostream& operator<<(std::ostream& os, Person& person) {
    // First Name and Last Name
    os << std::left << std::setw(14) << "FIRST NAME" 
       << ":" << std::right << std::setw(20) << person.getFirstName() << std::endl;
    os << std::left << std::setw(14) << "LAST NAME" 
       << ":" << std::right << std::setw(20) << person.getLastName() << std::endl;
    os << std::endl;

    // Address Section
    os << std::left << std::setw(14) << "ADDRESS" << std::endl;
    os << std::left << std::setw(14) << "STREET" 
       << ":" << std::right << std::setw(20) << person.getAddress().getStreetName() << std::endl;
    os << std::left << std::setw(14) << "CITY" 
       << ":" << std::right << std::setw(20) << person.getAddress().getCityName() << std::endl;
    os << std::left << std::setw(14) << "STATE" 
       << ":" << std::right << std::setw(20) << person.getAddress().getStateName() << std::endl;
    os << std::left << std::setw(14) << "ZIP CODE" 
       << ":" << std::right << std::setw(20) << person.getAddress().getZipCode() << std::endl;
    os << std::endl;

    // Pets List Section
    os << std::left << std::setw(14) << "PETS LIST" << std::endl;
    if (person.getPets().empty()) {
        os << "NONE" << std::endl;
    } else {
        for (Pet* pet : person.getPets()) {
            os << std::left << std::setw(14) << "NAME" 
               << ":" << std::right << std::setw(20) << pet->getPetName() << std::endl;
            os << std::left << std::setw(14) << "DOB" 
               << ":" << std::right << std::setw(20) << pet->getPetDOB().dateString() << std::endl;
            os << std::left << std::setw(14) << "TYPE" 
               << ":" << std::right << std::setw(20) << pet->getPetType() << std::endl;
            os << std::left << std::setw(14) << "BREED" 
               << ":" << std::right << std::setw(20) << pet->getPetBreed() << std::endl;
            os << std::endl;
        }
    }
    return os;
}


std::istream& operator>>(std::istream& is, Person& person) {

    std::string firstName, lastName, street, city, state;
    size_t zipCode;

    // Read person's details
    std::getline(is, firstName);
    std::getline(is, lastName);
    std::getline(is, street);
    std::getline(is, city);
    std::getline(is, state);
    is >> zipCode;

    std::cin.ignore();

    // Set the Person's details
    person.setFirstName(firstName);
    person.setLastName(lastName);
    person.setStreetName(street);
    person.setCityName(city);
    person.setStateName(state);
    person.setZipCode(zipCode);

    return is;
}
