#ifndef COLLEGEPERSON_H
#define COLLEGEPERSON_H

#include <iostream>
#include "Person.h"

class CollegePerson : public Person{
    private:
        std::string university;
        std::string college;
        int id;
        float earned;
        float total;
        float grade;
        float gpa;
        std::string letterGrade;
    public:
        CollegePerson();
        CollegePerson(std::string, int , std::string , std::string , int);

        std::string getUniversityName();
        std::string getCollegeName();
        int getIDNumber();
        float getEarned();
        float getTotal();
        float getGrade();
        float getgpa();
        std::string getLetterGrade();

        void setUniversityName(std::string);
        void setCollegeName(std::string);
        void setIDNumber(int);
        void setEarned(float);
        void setTotal(float);
        void setGrade(float);
        void setgpa(float);
        void setLetterGrade(std::string);

};      


#endif