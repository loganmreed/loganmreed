#ifndef PETF_H
#define PETF_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

struct Date{
    int day;
    int month;
    int year;
    
    unsigned int checkDay(int testDay) {
        static const int daysPerMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (testDay > 0 && testDay <= daysPerMonth[month]){
            return testDay;
        }
        if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
            return testDay;
        }
        throw "Invalid day for the given month and year";
    }
    std::string dateString() const{
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }

    Date(int m = 1, int d = 1, int y = 1900){
        if (m > 0 && m <= 12){
            month = m;
        } else{
            throw "Month must be between 1 and 12";
        }

        year = y;
        day = checkDay(d);
    }

};

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
};

#endif