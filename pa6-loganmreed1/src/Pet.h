#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm> 
#include "Date.h"

class Pet{
    friend std::ostream& operator<<(std::ostream&, Pet&);
    friend std::istream& operator>>(std::istream&, Pet&);
    private:
        std::string name;
        Date DOB;
        std::string type;
        std::string breed;
    public:
        Pet();
        Pet(const std::string&, const Date&, const int&, const std::string&);
        
        std::string getPetName();
        Date getPetDOB();
        std::string getPetType();
        std::string getPetBreed();

        void setPetName(const std::string&);
        void setPetDOB(const int&, const int&, const int&);
        void setPetType(const int&);
        void setPetBreed(const std::string&);
        void transformer();
};

#endif