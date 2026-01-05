#include "user.h"

// Default Constructor for initializing User object
User::User(){
    name = "";
    id = "";
    type = UserType::Other;
    gradeLevel = 0;
    subject = "";
}
// Constructor to initialize User with ID, name, type, and grade level
User::User(std::string idPass, std::string namePass, UserType typePass, int gradelevelPass){
    name = namePass;
    id = idPass;
    type = typePass;
    gradeLevel = gradelevelPass;
    subject = "";
}
// Constructor to initialize User with ID, name, type, and subject
User::User(std::string idPass, std::string namePass, UserType typePass, std::string subjectPass){
    name = namePass;
    id = idPass;
    type = typePass;
    subject = subjectPass;
    gradeLevel = 0;
}
// Constructor to initialize User with ID, name, type, grade level, and subject
User::User(std::string idPass, std::string namePass, UserType typePass, int gradelevelPass, std::string subjectPass){
    name = namePass;
    id = idPass;
    type = typePass;
    gradeLevel = gradelevelPass;
    subject = subjectPass;
}
// Constructor to initialize User with ID, name, and type only
User::User(std::string idPass, std::string namePass, UserType typePass){
    name = namePass;
    id = idPass;
    type = typePass;
    subject = "";
    gradeLevel = 0;
}

// Get the User's ID
std::string User::getId() const{
    return id;
}
// Get the User's name
std::string User::getName() const{
    return name;
}

// Get the User's type
UserType User::getType() const{
    return type;
}
// Get the User's grade level if student
int User::getGradeLevel() const{
    return gradeLevel;
}
// Get the User's subject if teacher
std::string User::getSubject() const{
    return subject;
}
// Set the User's ID
void User::setId(std::string idPass){
    id = idPass;
}
// Set the User's name
void User::setName(std::string namePass){
    name = namePass;
}
// Set the User's type
void User::setType(UserType typePass){
    type = typePass;
}
// Set the User's grade level
void User::setGradeLevel(int gradeLevelPass){
    gradeLevel = gradeLevelPass;
}
// Set the User's subject
void User::setSubject(std::string subjectPass){
    subject = subjectPass;
}
// Display user's information based on type
void User::displayInfo() {
    // Map the user type to a string
    std::string userType;
    switch (getType()) {
        case UserType::Student:
            userType = "Student";
            break;
        case UserType::Teacher:
            userType = "Teacher";
            break;
        case UserType::Staff:
            userType = "Staff";
            break;
        case UserType::Other:
            userType = "Other";
            break;
    }

    std::cout << "Name: " << getName() << ", ID: " << getId() << ", Type: " << userType;

    // Display grade level only if user is a Student
    if (getType() == UserType::Student) {
        std::cout << ", Grade Level: " << getGradeLevel();
    }
    // Display subject only if user is a Teacher
    else if (getType() == UserType::Teacher) {
        std::cout << ", Subject: " << getSubject();
    }

    std::cout << std::endl;
}

