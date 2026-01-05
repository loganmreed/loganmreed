#include "functions.h"
#include "CollegePerson.h"

void greeting(){
    std::cout << "Press Enter to Continue";
    std::cin.ignore();
}

int recordCount(){
    std::ifstream file("data/data.txt");
    if(!file){
        std::cerr << "Error: Could not open the file!" << std::endl;
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


void getInput(std::vector<CollegePerson*> collegeRecords){
    std::ifstream file("data/data.txt");
    if(!file){
        std::cerr << "Error: Could not open file!" << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> recordLines;
    while (std::getline(file, line)) {
        // Non-blank line: add to current record
        if (line.find_first_not_of(" \t\r\n") != std::string::npos) {
            recordLines.push_back(line);
        } else {
            // Blank line encountered: process the accumulated recordLines
            if (!recordLines.empty()) {
                std::istringstream iss(recordLines[0]);
                std::string token;
                std::string name, ageStr, university, college, idStr;
                
                // Extract the person info (fields separated by commas)
                if (std::getline(iss, token, ',')) { name = token; }
                if (std::getline(iss, token, ',')) { ageStr = token; }
                if (std::getline(iss, token, ',')) { university = token; }
                if (std::getline(iss, token, ',')) { college = token; }
                if (std::getline(iss, token, ',')) { idStr = token; }
                
                int age = std::stoi(ageStr);
                int id = std::stoi(idStr);
                
                // Process the task lines (from index 1 onward)
                double totalEarned = 0;
                double totalPoints = 0;
                for (std::size_t i = 1; i < recordLines.size(); i++) {
                    std::istringstream taskStream(recordLines[i]);
                    std::string taskName, score;
                    if (std::getline(taskStream, taskName, ',')) {
                        if (std::getline(taskStream, score, ',')) {
                            // Score format: earned/full (e.g., "15/20")
                            std::size_t pos = score.find('/');
                            if (pos != std::string::npos) {
                                std::string earnedStr = score.substr(0, pos);
                                std::string fullStr = score.substr(pos + 1);
                                try {
                                    double earned = std::stod(earnedStr);
                                    double full = std::stod(fullStr);
                                    totalEarned += earned;
                                    totalPoints += full;
                                } catch (const std::exception& e) {
                                    throw "you broke it";
                                }
                            }
                        }
                    }
                }
                CollegePerson* cp = new CollegePerson();
                cp->setPersonName(name);
                cp->setPersonAge(age);
                cp->setUniversityName(university);
                cp->setCollegeName(college);
                cp->setIDNumber(id);
                cp->setEarned(totalEarned);
                cp->setTotal(totalPoints);

                collegeRecords.push_back(cp);
                recordLines.clear();
            }
        }
    }
        
    if(!recordLines.empty()){
        std::istringstream iss(recordLines[0]);
        std::string token;
        std::string name, ageStr, university, college, idStr;
        
        // Extract the person info (fields separated by commas)
        if (std::getline(iss, token, ',')) { name = token; }
        if (std::getline(iss, token, ',')) { ageStr = token; }
        if (std::getline(iss, token, ',')) { university = token; }
        if (std::getline(iss, token, ',')) { college = token; }
        if (std::getline(iss, token, ',')) { idStr = token; }
        
        int age = std::stoi(ageStr);
        int id = std::stoi(idStr);
        
        // Process the task lines (from index 1 onward)
        double totalEarned = 0;
        double totalPoints = 0;
        for(std::size_t i = 1; i < recordLines.size(); i++){
            std::istringstream taskStream(recordLines[i]);
            std::string taskName, score;
            if (std::getline(taskStream, taskName, ',')) {
                if (std::getline(taskStream, score, ',')) {
                    std::size_t pos = score.find('/');
                    if (pos != std::string::npos) {
                        std::string earnedStr = score.substr(0, pos);
                        std::string fullStr = score.substr(pos + 1);
                        try {
                            double earned = std::stod(earnedStr);
                            double full = std::stod(fullStr);
                            totalEarned += earned;
                            totalPoints += full;
                        } catch (const std::exception& e) {
                            throw "you broke it";
                        }
                    }
                }
            }
        }
        CollegePerson* cp = new CollegePerson();
        cp->setPersonName(name);
        cp->setPersonAge(age);
        cp->setUniversityName(university);
        cp->setCollegeName(college);
        cp->setIDNumber(id);
        cp->setEarned(totalEarned);
        cp->setTotal(totalPoints);

        collegeRecords.push_back(cp);
        recordLines.clear();
    }
    file.close();
}

void getInput(std::vector<CollegePerson*> collegeRecords) {
    std::ifstream file("data/data.txt");
    if (!file) {
        std::cerr << "Error: Could not open file! input" << std::endl;
        std::cout << "\nPress Enter to exit...";
        std::cin.ignore();
        std::cin.get();
    }

    std::vector<CollegePerson*> tempRecords;  // Temporary vector

    std::string line;
    std::vector<std::string> recordLines;// To store one person's records
    
    
    while (std::getline(file, line)) {
        std::cout << "Read line: " << line << std::endl;
        if (line.empty()) {
            //std::stringstream ss;
            if (!recordLines.empty()) {
                processRecord(recordLines, tempRecords);
                recordLines.clear();
            }
        }else{
            recordLines.push_back(line);
        }
    }

    if (!recordLines.empty()) {
        processRecord(recordLines, tempRecords);
        recordLines.clear();
    }

    file.close();
    


    // Workaround: Copy tempRecords into the passed vector
    collegeRecords.clear();  // Clear existing vector to avoid memory leaks
    for (std::size_t i = 0; i < tempRecords.size(); i++) {
        collegeRecords.push_back(tempRecords[i]);
    }
}

    /* std::string line;
    std::vector<std::string> recordLines;
    
    while (std::getline(file, line)) {
        if (line.find_first_not_of(" \t\r\n") != std::string::npos) {
            recordLines.push_back(line);
            std::cout << line;
        } else {
            if (!recordLines.empty()) {
                processRecord(recordLines, tempRecords);
                recordLines.clear();
            }
        }
    }

    if (!recordLines.empty()) {
        processRecord(recordLines, tempRecords);
        recordLines.clear();
    }

    //file.close();

    // Workaround: Copy tempRecords into the passed vector
    collegeRecords.clear();  // Clear existing vector to avoid memory leaks
    for (std::size_t i = 0; i < tempRecords.size(); i++) {
        collegeRecords.push_back(tempRecords[i]);
    } */

/* void getInput(std::vector<CollegePerson*> collegeRecords){
    std::ifstream file("data/data.txt");
    if(!file){
        std::cerr << "Error: Could not open file!" << std::endl;
        return;
    }

    std::string line, name, university, college;
    int age, id;
    float earnedPoints, totalPoints;

    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip extra blank lines

        // Read all the required fields
        name = line;
        std::getline(file, line);

        try {
            age = std::stoi(line);
        } catch (const std::invalid_argument& e){
            std::cerr << "Invalid age input: " << std::endl;
            continue;
        }

        std::getline(file, university);
        std::getline(file, college);
        std::getline(file, line);
        
        try {
            id = std::stoi(line);
        } catch (const std::invalid_argument& e){
            std::cerr << "Invalid ID input: " << std::endl;
            continue;
        }
        std::getline(file, line);

        try {
            earnedPoints = std::stof(line);
        } catch (const std::invalid_argument& e){
            std::cerr << "Invalid earned points input: " << std::endl;
            continue;
        }

        std::getline(file, line);

        try {
            totalPoints = std::stof(line);
        } catch (const std::invalid_argument& e){
            std::cerr << "Invalid total points input: " << std::endl;
            continue;
        }
        

        // Create a CollegePerson object
        CollegePerson* person = new CollegePerson();
        person->setPersonName(name);
        person->setPersonAge(age);
        person->setUniversityName(university);
        person->setCollegeName(college);
        person->setIDNumber(id);
        person->setEarned(earnedPoints);
        person->setTotal(totalPoints);

        // Store in vector
        collegeRecords.push_back(person);
    }
    file.close();
} */


void calcGrades(std::vector<CollegePerson*> collegeRecords) {
    // Loop through each CollegePerson object in the vector
    for (CollegePerson* person : collegeRecords){
        float grade = (person->getEarned()/person->getTotal()) * 100;

        std::string letterGrade;
        float gpa = 0.0f;

        if (grade > 94) {
            letterGrade = "A+";
            gpa = 4.5f;
        } else if (grade > 89) {
            letterGrade = "A";
            gpa = 4.0f;
        } else if (grade > 84) {
            letterGrade = "B+";
            gpa = 3.5f;
        } else if (grade > 79) {
            letterGrade = "B";
            gpa = 3.0f;
        } else if (grade > 74) {
            letterGrade = "C+";
            gpa = 2.5f;
        } else if (grade > 69) {
            letterGrade = "C";
            gpa = 2.0f;
        } else if (grade > 64) {
            letterGrade = "D+";
            gpa = 1.5f;
        } else if (grade > 60) {
            letterGrade = "D";
            gpa = 1.0f;
        } else {
            letterGrade = "F";
            gpa = 0.0f;
        }

        person->setGrade(grade);
        person->setLetterGrade(letterGrade);
        person->setgpa(gpa);
    }
}

void display(std::vector<CollegePerson*> collegeRecords) {
    // Separate records into two groups: UCD and Metro State.
    std::vector<CollegePerson*> ucdRecords;
    std::vector<CollegePerson*> metroRecords;
    for (CollegePerson* person : collegeRecords) {
        std::string university = person->getUniversityName();
        if (university == "UCD") {
            ucdRecords.push_back(person);
        } else if (university == "Metro State") {
            metroRecords.push_back(person);
        }
    }
    
    // Create a separator line of 90 hyphens.
    std::string separator(90, '-');
    
    // Function to print header.
    auto printHeader = []() {
        std::cout << std::setw(15) << "Name"
                  << std::setw(15) << "Age"
                  << std::setw(15) << "ID"
                  << std::setw(15) << "College"
                  << std::setw(15) << "GPA"
                  << std::setw(15) << "Grade" << std::endl;
    };

    // Print UCD records if any exist.
    if (!ucdRecords.empty()) {
        std::cout << "UCD" << std::endl;
        std::cout << separator << std::endl;
        printHeader();
        for (CollegePerson* person : ucdRecords) {
            std::cout << std::setw(15) << person->getPersonName()
                      << std::setw(15) << person->getPersonAge()
                      << std::setw(15) << person->getIDNumber()
                      << std::setw(15) << person->getCollegeName()
                      << std::setw(15) << person->getgpa()
                      << std::setw(15) << person->getLetterGrade() << std::endl;
        }
        std::cout << std::endl;  // Blank line to separate groups.
    }
    
    // Print Metro State records if any exist.
    if (!metroRecords.empty()) {
        std::cout << "Metro State" << std::endl;
        std::cout << separator << std::endl;
        printHeader();
        for (CollegePerson* person : metroRecords) {
            std::cout << std::setw(15) << person->getPersonName()
                      << std::setw(15) << person->getPersonAge()
                      << std::setw(15) << person->getIDNumber()
                      << std::setw(15) << person->getCollegeName()
                      << std::setw(15) << person->getgpa()
                      << std::setw(15) << person->getLetterGrade() << std::endl;
        }
    }
}

void processRecord(const std::vector<std::string>& recordLines, std::vector<CollegePerson*>& collegeRecords) {
    std::istringstream iss(recordLines[0]);
    std::string name, ageStr, university, college, idStr;

    std::getline(iss, name, ',');  // Ensure the full name is captured
    std::getline(iss, ageStr, ',');
    std::getline(iss, university, ',');
    std::getline(iss, college, ',');
    std::getline(iss, idStr, ',');

    std::cout << "Extracted data: " << name << ", " << ageStr << ", " << university << ", " << college << ", " << idStr << std::endl;

    bool isAgeValid = true;
    for (char c: ageStr){
        if(!std::isdigit(c)){
            isAgeValid = false;
            break;
        }
    }
    bool isIdValid = true;
    for (char c: idStr){
        if(!std::isdigit(c)){
            isIdValid = false;
            break;
        }
    }

    if (ageStr.empty() || idStr.empty()|| !isAgeValid || !isIdValid){
        std::cerr << "Error: Invalid data found in age or ID field!" <<"\nageStr" << ageStr << "\nidStr" << idStr << std::endl;
        return;
    }
    int age = std::stoi(ageStr);
    int id = std::stoi(idStr);

    double totalEarned = 0;
    double totalPoints = 0;

    for (std::size_t i = 1; i < recordLines.size(); i++) {
        std::istringstream taskStream(recordLines[i]);
        std::string task, score;
        if (std::getline(taskStream, task, ',') && std::getline(taskStream, score, ',')) {
            std::size_t pos = score.find('/');
            if (pos != std::string::npos) {
                double earned = std::stod(score.substr(0, pos));
                double full = std::stod(score.substr(pos + 1));
                totalEarned += earned;
                totalPoints += full;
            }
        }
    }
    std::cout << "ADebugging: Setting CollegePerson values..." << std::endl;
    std::cout << "AName: " << name << std::endl;
    std::cout << "AAge: " << age << std::endl;
    std::cout << "AUniversity: " << university << std::endl;
    std::cout << "ACollege: " << college << std::endl;
    std::cout << "AID: " << id << std::endl;
    std::cout << "ATotal Earned: " << totalEarned << std::endl;
    std::cout << "ATotal Points: " << totalPoints << std::endl;
    CollegePerson* cp = new CollegePerson();
    cp->setPersonName(name);
    cp->setPersonAge(age);
    cp->setUniversityName(university);
    cp->setCollegeName(college);
    cp->setIDNumber(id);
    cp->setEarned(totalEarned);
    cp->setTotal(totalPoints);

    collegeRecords.push_back(cp);
    std::cout << "Extracted data pro: " << name << ", " << ageStr << ", " << university << ", " << college << ", " << idStr << std::endl;
}