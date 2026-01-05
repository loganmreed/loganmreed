#include "functions.h"
#include "CollegePerson.h"
void displayMenu() {
    std::cout << "\nCollege Person Management System" << std::endl;
    std::cout << "1. Load Data from File" << std::endl;
    std::cout << "2. Add New College Person" << std::endl;
    std::cout << "3. Calculate Grades" << std::endl;
    std::cout << "4. Display Records" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}


int main() {
    std::vector<CollegePerson*> collegeRecords;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                getInput(collegeRecords);
                //std::cout << "Records loaded: " << collegeRecords.size() << std::endl;
                //std::cout << "Data loaded successfully!" << std::endl;
                break;

            case 2: {
                std::string name, university, college;
                int age, id;
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Age: ";
                std::cin >> age;
                std::cin.ignore();
                std::cout << "Enter University: ";
                std::getline(std::cin, university);
                std::cout << "Enter College: ";
                std::getline(std::cin, college);
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cin.ignore();
                
                CollegePerson* newPerson = new CollegePerson(name, age, university, college, id);
                collegeRecords.push_back(newPerson);
                std::cout << "New record added successfully!" << std::endl;
                break;
            }

            case 3:
                calcGrades(collegeRecords);
                
                std::cout << "Grades calculated successfully!" << std::endl;
                break;

            case 4:
                display(collegeRecords);
                break;

            case 5:
                std::cout << "Exiting program..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    // Free allocated memory
    for (CollegePerson* person : collegeRecords) {
        delete person;
    }
    
    return 0;
}
