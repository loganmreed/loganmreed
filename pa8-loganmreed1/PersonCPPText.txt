#include "Person.h"

Person::Person(){
    name = "";
    age = 0;
}
Person::Person(std::string n,int a){
    name = n;
    age = a;
}

std::string Person::getPersonName(){
    return name;
}

int Person::getPersonAge(){
    return age;
}

void Person::setPersonName(std::string n){
    name = n;
}
void Person::setPersonAge(int a){
    age = a;
}