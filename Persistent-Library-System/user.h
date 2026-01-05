#ifndef USER_H
#define USER_H
#include <iostream>
#include <string> 

enum class UserType {
    Student = 0, 
    Teacher = 1,
    Staff = 2,
    Other = 3
};


class User{
    private:
        std::string id;
        std::string name;
        UserType type;
        int gradeLevel;
        std::string subject;
    public:
        User();
        User(std::string id, std::string name, UserType type, int gradelevel);
        User(std::string id, std::string name, UserType type, std::string subject);
        User(std::string id, std::string name, UserType type);
        User(std::string idPass, std::string namePass, UserType typePass, int gradelevelPass, std::string subjectPass);
        std::string getId() const;
        std::string getName() const;
        UserType getType() const;
        int getGradeLevel() const;
        std::string getSubject() const;

        void setId(std::string);
        void setName(std::string);
        void setType(UserType);
        void setGradeLevel(int);
        void setSubject(std::string);
        void displayInfo();

};

#endif