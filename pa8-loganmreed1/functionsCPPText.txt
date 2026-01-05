#include "functions.h"
#include "CollegePerson.h"

std::vector<CollegePerson*> globalCollegeRecords;


void greeting(){
    std::cout << "Press Enter to Continue";
    std::cin.ignore();
}


int recordCount(){
    std::ifstream file("data/data.txt");
    if(!file){
        std::cerr << "Error: Could not open the file! count" << std::endl;
        return -1;
    }

    std::string line;
    int count = 0;
    bool inRecord = false;

    while(std::getline(file,line)){
        if (line.find_first_not_of(" \t\r\n") != std::string::npos) {
            if(!inRecord){
                count++;
                inRecord = true;
            }
        } else{
            inRecord = false;
        }
    }

    file.close();
    return count;
}

std::vector<CollegePerson*>& getCollegeRecords(){
    static std::vector<CollegePerson*> collegeRecords;
    return collegeRecords;
}

void getInput(std::vector<CollegePerson*> collegePersonsIn){

    std::ifstream file("data/data.txt");
   if (!file.is_open()) {
       std::cerr << "Error opening file." << std::endl;
       return;
   }

   std::string line;
   int index = 0;

   while (std::getline(file, line)) {
       if (line.empty()) 
           continue;

       std::stringstream ss(line);
       std::string name, university, college;
       int age, id;
       std::string temp;
       std::getline(ss, name, ','); 
       std::getline(ss, temp, ',');
       age = stoi(temp); 
       std::getline(ss, university, ',');
       std::getline(ss, college, ',');
       std::getline(ss, temp);
       id = stoi(temp);

       collegePersonsIn[index]->setPersonName(name);
       collegePersonsIn[index]->setPersonAge(age);
       collegePersonsIn[index]->setUniversityName(university);
       collegePersonsIn[index]->setCollegeName(college);
       collegePersonsIn[index]->setIDNumber(id);

       // Parse and set earned and total points
       float earned = 0, total = 0;
       std::getline(file, line);
       while (!line.empty()) {
           std::istringstream iss(line);
           std::string task;
           std::getline(iss, task, ',');
           std::getline(iss, temp, '/');
           earned = stof(temp);
           std::getline(iss, temp);
           total = stof(temp);
           

           // Set earned and total points
           collegePersonsIn[index]->setEarned(collegePersonsIn[index]->getEarned() + earned);
           collegePersonsIn[index]->setTotal(collegePersonsIn[index]->getTotal() + total);

           std::getline(file, line);
       }

       // Move to the next index
       index++;
   }

   file.close();   
}

/* void getInput(std::vector<CollegePerson*> collegeRecords) {
    std::ifstream file("data/data.txt");
    std::string line;
    std::vector<CollegePerson*>& records = getCollegeRecords();
    records.clear();

    //globalCollegeRecords = collegeRecords;
    int totalRecords = recordCount();
    //globalCollegeRecords.reserve(totalRecords);
    records.reserve(totalRecords);
    if (file.is_open()){
        while(std::getline(file,line)){
            for (char& c : line) {
                if (c == ',') {
                    c = ' ';
                }
            }
            std::stringstream ss(line);
            std::string fname,lname, university,college,idStr;
            
            std::cout << fname << lname << university << college << idStr;
            int age, id;

            //std::cout << "Parsing line: " << line << std::endl;
            ss >> fname >> lname;
            ss >> age;

            ss >> university;
            if (university == "UCD"){
                ss >> college;
            } else{
                std::string temp;
                ss >> temp;
                university += " " + temp;
                ss >> college;
            }
            ss >> idStr;

            std::string fullName = fname + " " + lname;

            id = std::stoi(idStr);

            CollegePerson* person = new CollegePerson(fullName,age,university,college,id);
            //std::cout << "name: " << person->getPersonName() << std::endl;
            person->setEarned(0);
            person->setTotal(0);
            while (std::getline(file, line) && !line.empty()) {
                // Expect line in format: "HW4,20/40"
                size_t commaPos = line.find(',');
                size_t slashPos = line.find('/', commaPos);
                if (commaPos == std::string::npos || slashPos == std::string::npos)
                    break;  // or continue, depending on your file format
            
                int earned = std::stoi(line.substr(commaPos + 1, slashPos - commaPos - 1));
                int total = std::stoi(line.substr(slashPos + 1));
                person->setEarned(person->getEarned() + earned);
                person->setTotal(person->getTotal() + total);
            }
            //std::cout << "totalRecords: " << totalRecords << std::endl;
           // std::cout << "Records loaded: " << collegeRecords.size() << std::endl;
          //  std::cout << "Records loaded globe: " << globalCollegeRecords.size() << std::endl;
            //collegeRecords.push_back(person);
            //globalCollegeRecords.push_back(person);
            records.push_back(person);
        }
        file.close();
    } else{
        std::cerr << "Unable to open the file." << std::endl;
    }
} */

    
void calcGrades(std::vector<CollegePerson*> dummy) {
    //std::vector<CollegePerson*>& records = getCollegeRecords();
    for (std::size_t i = 0; i < dummy.size(); i++) {
        CollegePerson* cp = dummy[i];
        float earned = cp->getEarned();
        float total = cp->getTotal();
        //std::cout << "total: " << total << "\nearned: " << earned << "\ngrade ex: " << earned / total * 100.0f<< std::endl;
        float grade = (total > 0.0f) ? (earned / total * 100.0f) : 0.0f;
        //std::cout << "grade" << grade << std::endl;
        cp->setGrade(grade);

        if (grade >= 94) {  // Fixed boundary condition
            cp->setLetterGrade("A+");
            cp->setgpa(4.5f);
        } else if (grade >= 89) {
            cp->setLetterGrade("A");
            cp->setgpa(4.0f);
        } else if (grade >= 84) {
            cp->setLetterGrade("B+");
            cp->setgpa(3.5f);
        } else if (grade >= 79) {
            cp->setLetterGrade("B");
            cp->setgpa(3.0f);
        } else if (grade >= 74) {
            cp->setLetterGrade("C+");
            cp->setgpa(2.5f);
        } else if (grade >= 69) {
            cp->setLetterGrade("C");
            cp->setgpa(2.0f);
        } else if (grade >= 64) {
            cp->setLetterGrade("D+");
            cp->setgpa(1.5f);
        } else if (grade >= 60) {
            cp->setLetterGrade("D");
            cp->setgpa(1.0f);
        } else {
            cp->setLetterGrade("F");
            cp->setgpa(0.0f);
        }
    }
}


void display(std::vector<CollegePerson*> collegeRecords) {
    //std::vector<CollegePerson*>& records = getCollegeRecords();
    const std::string universities[2] = {"UCD", "Metro State"};
    for (int u = 0; u < 2; u++) {
        std::string uni = universities[u];
        if (uni == "UCD"){
            std::cout << uni << std::endl;
        } else{
            std::cout << "\n" << uni << std::endl;
        }
        std::cout << std::string(90, '-') << std::endl;
        std::cout << std::left << std::setw(15) << "Name"
                  << std::setw(15) << "Age"
                  << std::setw(15) << "ID"
                  << std::setw(15) << "College"
                  << std::setw(15) << "GPA"
                  << std::setw(15) << "Grade" << std::endl;
        for (std::size_t i = 0; i < collegeRecords.size(); i++) {
            CollegePerson* cp = collegeRecords[i];
            if (cp->getUniversityName() == uni) {
                std::cout << std::left << std::setw(15) << cp->getPersonName()
                          << std::setw(15) << cp->getPersonAge()
                          << std::setw(15) << cp->getIDNumber()
                          << std::setw(15) << cp->getCollegeName()
                          << std::setw(15) << cp->getgpa()
                          << std::setw(15) << cp->getLetterGrade() << std::endl;
            }
        }
        //std::cout << std::endl;
    }
}