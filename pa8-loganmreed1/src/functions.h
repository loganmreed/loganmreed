#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
//#include "CollegePerson.h"

class CollegePerson; 

extern std::vector<CollegePerson*> globalCollegeRecords;

void greeting();

int recordCount();

void getInput(std::vector<CollegePerson*>);

void display(std::vector<CollegePerson*>);

void calcGrades(std::vector<CollegePerson*>);

void processRecord(const std::vector<std::string>& recordLines, std::vector<CollegePerson*>& collegeRecords);

std::vector<CollegePerson*>& getCollegeRecords();

#endif