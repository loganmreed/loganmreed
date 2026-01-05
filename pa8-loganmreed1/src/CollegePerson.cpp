#include "CollegePerson.h"


CollegePerson::CollegePerson() : Person() {
    university = "";
    college = "";
    id = 0;
    earned = 0.0f;
    total = 0.0f;
    grade = 0.0f;
    gpa = 0.0f;
    letterGrade = "";
}

CollegePerson::CollegePerson(std::string namepass, int agepass, std::string universitypass, std::string collegepass, int idpass) 
    : Person(namepass, agepass) {
    university = universitypass;
    college = collegepass;
    id = idpass;
    earned = 0.0f;
    total = 0.0f;
    grade = 0.0f;
    gpa = 0.0f;
    letterGrade = "";
}

std::string CollegePerson::getUniversityName(){
    return university;
}

std::string CollegePerson::getCollegeName(){
    return college;
}

int CollegePerson::getIDNumber(){
    return id;
}

float CollegePerson::getEarned(){
    return earned;
}

float CollegePerson::getTotal(){
    return total;
}

float CollegePerson::getGrade(){
    return grade;
}

float CollegePerson::getgpa(){
    return gpa;
}

std::string CollegePerson::getLetterGrade(){
    return letterGrade;
}


//setters
void CollegePerson::setUniversityName(std::string u){
    university = u;
}

void CollegePerson::setCollegeName(std::string c){
    college = c;
}

void CollegePerson::setIDNumber(int i){
    id = i;
}

void CollegePerson::setEarned(float e){
    earned = e;
}

void CollegePerson::setTotal(float t){
    total = t;
}

void CollegePerson::setGrade(float g){
    grade = g;
}

void CollegePerson::setgpa(float gp){
    gpa = gp;
}

void CollegePerson::setLetterGrade(std::string l){
    letterGrade = l;
}