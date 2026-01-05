#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person{
    private:
        std::string name;
        int age;
    public:
        Person();
        Person(std::string,int);
        std::string getPersonName();
        int getPersonAge();
        void setPersonName(std::string);
        void setPersonAge(int);

};

#endif