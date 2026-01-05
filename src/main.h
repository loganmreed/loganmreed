#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <limits>
#include "Database.h"
#include "Book.h"
#include "User.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <sstream>
#include <locale>
#include <unordered_set>


// ANSI escape codes for bold and color
#define RESET   "\033[0m" // to reset
#define BOLD    "\033[1m"
#define GREEN   "\033[32m" //choices
#define BLUE    "\033[34m" // for headers
#define YELLOW  "\033[33m" // for questions
#define CYAN    "\033[36m" // for functions passing
#define RED     "\033[31m" // for removing things

int getValidIntInput(int min, int max);
void showMenu();
void removeBookByISBN();
void removeUserById();
bool isValidISBN(const std::string& isbn);
void addBook();
bool isValidID(const std::string& id);
bool isValidName(const std::string& name);
std::string formatName(const std::string& str);
void searchUserByNameOrID();
void addUser();
void searchBooksByTitle();
std::string toLowerCase(const std::string& str);
void searchBooksByAuthor();

#endif // MAIN_H
