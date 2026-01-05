#include <iostream>
#include <string>
#include <limits>
#include "Database.h"
#include "Book.h"
#include "user.h"
#include "main.h"
#include <algorithm> 
#include <cctype> 
#include <limits>
#include <vector>
#include <sstream> 
#include <locale>
#include <unordered_set>

// ANSI escape codes for bold and color to make things stand out
#define RESET   "\033[0m" // to reset
#define BOLD    "\033[1m" 
#define GREEN   "\033[32m" //choices
#define BLUE    "\033[34m" // for headers
#define YELLOW  "\033[33m" // for questions
#define CYAN    "\033[36m" // for functions passing
#define RED     "\033[31m" // for removeing things


// Function to get a valid integer input within a specific range
int getValidIntInput(int min, int max) {
    int choice;
    std::string input;

    while (true) {
        std::cout << YELLOW << "Please enter a number between " << min << " and " << max << ": " << RESET;

        std::getline(std::cin, input);

        // Check for empty input
        if (input.empty()) {
            std::cout << "Invalid input. You didn't enter anything.\n" << YELLOW << "Please enter a valid number between " << min << " and " << max << "." << std::endl << RESET;
            continue;
        }

        std::stringstream ss(input);

        // Try to extract an integer and check for trailing characters
        if (ss >> choice) {
            if (ss.eof() && choice >= min && choice <= max) {
                return choice; // Valid input
            } else if (choice < min || choice > max) {
                std::cout << "Invalid input. The number " << choice << " is out of the valid range (" << min << " to " << max << ").\n" << YELLOW << "Please enter a number within this range." << std::endl << RESET;
            } else {
                std::cout << "Invalid input. The number " << choice << " is not within the range (" << min << " to " << max << ").\n" << YELLOW << "Try again." << std::endl << RESET;
            }
        } else {
            // Check if the input contains non-numeric characters or symbols
            bool hasInvalidChar = false;
            std::string invalidChars;
            for (char c : input) {
                if (!isdigit(c) && c != '-' && c != '+') {
                    hasInvalidChar = true;
                    invalidChars += c;
                }
            }

            if (hasInvalidChar) {
                std::cout <<"Invalid input. You entered the following invalid characters: " << invalidChars << ".\n" << YELLOW << "Please enter only numbers that are positive values." << std::endl << RESET;
            } else {
                std::cout <<"Invalid input. It looks like there were extra spaces or invalid formatting.\n" << YELLOW << "Ensure you enter a clean integer between " << min << " and " << max << "." << std::endl << RESET;
            }
        }
    }
}

// Show Menu with color
void showMenu() {
    std::cout << "\n" << BOLD << BLUE
              << "====================================\n"
              << "        LIBRARY SYSTEM MENU        \n"
              << "====================================\n"
              << RESET << "\n";

    std::cout << GREEN << "  [1]  Add a Book"           << RESET << "\n";
    std::cout << GREEN << "  [2]  Add a User"           << RESET << "\n";
    std::cout << GREEN << "  [3]  Search Book by Title" << RESET << "\n";
    std::cout << GREEN << "  [4]  Search Book by Author"<< RESET << "\n";
    std::cout << GREEN << "  [5]  Borrow a Book"        << RESET << "\n";
    std::cout << GREEN << "  [6]  Return a Book"        << RESET << "\n";
    std::cout << GREEN << "  [7]  Show All Books"       << RESET << "\n";
    std::cout << GREEN << "  [8]  Show All Users"       << RESET << "\n";
    std::cout << GREEN << "  [9]  Remove User"          << RESET << "\n";
    std::cout << GREEN << " [10]  Remove Book"          << RESET << "\n";
    std::cout << GREEN << " [11]  Check Late Fees"      << RESET << "\n";
    std::cout << GREEN << " [12]  Show Borrow History"  << RESET << "\n";
    std::cout << GREEN << " [13]  Show Stats"           << RESET << "\n";
    std::cout << GREEN << " [14]  Search for User"      << RESET << "\n";
    std::cout << GREEN << " [15]  Save and Exit"        << RESET << "\n";

    std::cout << BOLD << BLUE
              << "====================================\n"
              << RESET << "\n";

    std::cout << YELLOW << "Please choose an option: " << RESET;
}

// Removes a book from the database by ISBN
void removeBookByISBN() {
    std::string isbn;
    std::cout << YELLOW << "Enter the ISBN of the book to remove: " << RESET;
    std::cin >> isbn;
    
    char confirmation;
    while (true) {
        std::cout << RED << "Are you sure you want to remove the book with ISBN " << isbn << "? (y/n): " << RESET;
        std::cin >> confirmation;

        // Convert to lowercase for flexibility
        confirmation = std::tolower(confirmation);

        if (confirmation == 'y' || confirmation == 'n') {
            break;  // Proceed if the input is either 'y' or 'n'
        } else {
            std::cout << RED << "Invalid input. Please enter 'y' for yes or 'n' for no." << RESET << std::endl;
        }
    }

    if (confirmation == 'y') {
        // Call removeBook function from Database class
        Database::getInstance()->removeBook(isbn);
        std::cout << GREEN << "Book with ISBN " << isbn << " has been removed." << RESET << std::endl;
    } else {
        std::cout << CYAN << "Book removal canceled." << RESET << std::endl;
    }
}

// Removes a user from the database by ID
void removeUserById() {
    std::string userId;
    std::cout << YELLOW << "Enter the User ID to remove: " << RESET;
    std::cin >> userId;

    char confirmation;
    while (true) {
        std::cout << RED << "Are you sure you want to remove the user with ID " << userId << "? (y/n): " << RESET;
        std::cin >> confirmation;

        // Convert to lowercase
        confirmation = std::tolower(confirmation);

        if (confirmation == 'y' || confirmation == 'n') {
            break;  // Proceed if the input is either 'y' or 'n' not 1 or 2
        } else {
            std::cout << RED << "Invalid input. Please enter 'y' for yes or 'n' for no." << RESET << std::endl;
        }
    }

    if (confirmation == 'y') {
        // Call removeUser function from Database class
        Database::getInstance()->removeUser(userId);
        std::cout << GREEN << "User with ID " << userId << " has been removed." << RESET << std::endl;
    } else {
        std::cout << CYAN << "User removal canceled." << RESET << std::endl;
    }
}
// Add a book with validation
bool isValidISBN(const std::string& isbn) {
    // Remove hyphens and check if the remaining string has 13 characters
    std::string cleanedISBN;
    for (char ch : isbn) {
        if (ch != '-') {
            cleanedISBN.push_back(ch);
        }
    }

    // Check length of ISBN 13
    if (cleanedISBN.length() != 13) {
        return false;
    }

    // Check if all characters are digits, except the last one which can be 'X'
    for (size_t i = 0; i < 12; ++i) {
        if (!isdigit(cleanedISBN[i])) {
            return false;
        }
    }

    // Check the last character, it can either be a digit or 'X'
    if (!isdigit(cleanedISBN[12]) && cleanedISBN[12] != 'X') {
        return false;
    }

    // Validate the check digit (ISBN-13 uses a modulus-10 check)
    int sum = 0;
    for (size_t i = 0; i < 12; ++i) {
        int digit = cleanedISBN[i] - '0';
        sum += (i % 2 == 0) ? digit : digit * 3; // Even-indexed digits multiply by 1, odd by 3
    }

    int checkDigit = (cleanedISBN[12] == 'X') ? 10 : (cleanedISBN[12] - '0');
    sum += checkDigit;

    // ISBN is valid if sum is divisible by 10
    return (sum % 10 == 0);
}

// Adds a new book to the database
void addBook() {
    std::string isbn, title, author;
    int formatChoice;
    bool isAvailable;

    // ISBN input and validation
    while (true) {
        std::cout << YELLOW << "Enter ISBN: " << RESET;
        std::cin >> isbn;
        std::cin.ignore();  // Ignore newline character
        
        if (isValidISBN(isbn)) {
            break;
        } else {
            std::cout << YELLOW << "Invalid ISBN. Please enter a valid 13-digit ISBN number.(000-0000000000)" << std::endl << RESET;
        }
    }

    std::cout << YELLOW << "Enter Title: " << RESET;
    std::getline(std::cin, title);
    std::cout << YELLOW << "Enter Author: " << RESET;
    std::getline(std::cin, author);
    while (true) {
        std::cout << YELLOW << "Enter Availability (1 for available, 0 for not available): " << RESET;
        
        std::string input;
        std::getline(std::cin, input); 
        
        std::stringstream ss(input);
        if (!(ss >> isAvailable) || ss.rdbuf()->in_avail() > 0 || (isAvailable != 0 && isAvailable != 1)) {
            // If conversion failed, extra characters are present, or value is not 0 or 1
            std::cout << YELLOW << "Invalid input. Please enter 1 for available or 0 for not available." << std::endl << RESET;
        } else {
            break;
        }
    }    

    while (true) {
        std::cout << "\nPlease select the format of the book:" << std::endl;
        std::cout << "0: Hardback\n1: Paperback\n2: eBook\n3: Audiobook\n4: Magazine" << std::endl;
        std::cout << YELLOW << "Enter a number between 0 and 4: " << RESET;
        
        std::string input;
        std::getline(std::cin, input);
        
        std::stringstream ss(input);
        if (!(ss >> formatChoice) || ss.rdbuf()->in_avail() > 0 || formatChoice < 0 || formatChoice > 4) {
            // If conversion failed, extra characters are present, or out of range
            std::cout << YELLOW << "Invalid input. Please enter a number between 0 and 4 for the format." << std::endl << RESET;
        } else {
            break; 
        }
    }    

    Book newBook(isbn, title, author, isAvailable, {}, static_cast<BookFormat>(formatChoice));
    Database::getInstance()->addBook(newBook);
    std::cout << GREEN << "Book added successfully!" << std::endl << RESET;
}

// Add a user with validation
bool isValidID(const std::string& id) {
    return std::all_of(id.begin(), id.end(), [](char c) {
        return std::isalnum(static_cast<unsigned char>(c)); // Ensures only letters and numbers
    });
}

// Validates name length and character constraints
bool isValidName(const std::string& name) {
    if (name.length() < 1 || name.length() > 50) return false; // Check length
    return std::all_of(name.begin(), name.end(), [](char c) {
        return std::isalpha(static_cast<unsigned char>(c)) || c == ' '; // Allows only letters and spaces
    });
}

// Formats name to capitalize the first letter of each word
std::string formatName(const std::string& str) {
    std::string result;
    bool capitalizeNext = true;
    
    for (char ch : str) {
        if (std::isspace(ch)) {
            capitalizeNext = true;
        } else if (capitalizeNext) {
            ch = std::toupper(static_cast<unsigned char>(ch));
            capitalizeNext = false;
        } else {
            ch = std::tolower(static_cast<unsigned char>(ch));
        }
        result += ch;
    }
    
    return result;
}

// Adds a new user to the database
void addUser() {
    std::string id, name, subject;
    int typeChoice, gradeLevel;

    // Handle user type input
    while (true) {
        std::cout << YELLOW << "Enter User Type (0: Student, 1: Teacher, 2: Staff, 3: Other): " << RESET;
        std::cin >> typeChoice;
        if (std::cin.fail() || typeChoice < 0 || typeChoice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 0 and 3.\n";
        } else {
            break;
        }
    }

    // Validate ID
    while (true) {
        std::cout << YELLOW << "Enter ID (Only letters and numbers allowed): " << RESET;
        std::cin >> id;
        if (isValidID(id)) {
            break;
        }
        std::cout << "Invalid ID. Please enter only letters and numbers.\n";
    }

    std::cin.ignore(); // Ignore leftover newline from previous input

    // Validate and format Name
    while (true) {
        std::cout << YELLOW << "Enter Name: " << RESET;
        std::getline(std::cin, name);
        if (isValidName(name)) {
            name = formatName(name);
            break;
        }
        std::cout << "Invalid name. Must be 1-50 characters long and contain only alphabetic characters and spaces.\n";
    }

    // Handle user type-specific information
    if (typeChoice == 0) {  // Student
        while (true) {
            std::cout << YELLOW << "Enter Grade Level: " << RESET;
            std::cin >> gradeLevel;
            if (std::cin.fail() || gradeLevel < 1 || gradeLevel >= 12) {  
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid grade level. Please enter an integer greater than 0.\n";
            } else {
                break;
            }
        }
        User newUser(id, name, static_cast<UserType>(typeChoice), gradeLevel);
        Database::getInstance()->addUser(newUser);
        std::cout << GREEN << "Student added successfully!\n" << RESET;
    }
    else if (typeChoice == 1) {  // Teacher
        std::cin.clear();
        std::cout << YELLOW << "Enter Subject: " << RESET;
        std::getline(std::cin, subject);
        User newUser(id, name, static_cast<UserType>(typeChoice), subject);
        Database::getInstance()->addUser(newUser);
        std::cout << GREEN <<"Teacher added successfully!\n" << RESET;
    }    
    else {  // Staff or Other
        User newUser(id, name, static_cast<UserType>(typeChoice));
        Database::getInstance()->addUser(newUser);
        std::cout << GREEN << "Staff/Other user added successfully!\n" << RESET;
    }
}

// Search for books by title
void searchBooksByTitle() {
    std::string title;
    std::cout << YELLOW << "Enter the title of the book: " << RESET;
    std::getline(std::cin, title);  // No need to call ignore()
    
    auto books = Database::getInstance()->searchBooksByTitle(title);
    if (books.empty()) {
        std::cout << "No books found with the title \"" << title << "\".\n";
    } else {
        for (auto& book : books) {
            book.displayInfo();
        }
    }
}

void searchUserByNameOrID() {
    std::string query;
    std::cout << YELLOW << "Enter the user's name or ID: " << RESET;
    std::getline(std::cin, query);

    auto users = Database::getInstance()->searchUser(query);
    if (users.empty()) {
        std::cout << "No users found with \"" << query << "\".\n";
    } else {
        for (auto& user : users) {
            user.displayInfo();
        }
    }
}

// Searches and displays books by a given author
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Search for books by author
void searchBooksByAuthor() {
    while (true) {
        std::string author;
        std::cout << YELLOW << "Enter the author of the book (or type 'exit' to cancel): " << RESET;
        std::getline(std::cin, author);

        if (toLowerCase(author) == "exit") {
            std::cout << "Search canceled.\n";
            return;
        }

        std::string lowerAuthor = toLowerCase(author);
        auto allBooks = Database::getInstance()->getAllBooks();

        // Store books that match the author
        std::vector<Book> foundBooks;
        std::unordered_set<std::string> uniqueSuggestions;

        for (auto& book : allBooks) {
            std::string bookAuthor = book.getAuthor();
            std::string lowerBookAuthor = toLowerCase(bookAuthor);

            if (lowerBookAuthor == lowerAuthor) {
                foundBooks.push_back(book);
            } else if (lowerBookAuthor.find(lowerAuthor) != std::string::npos) {
                uniqueSuggestions.insert(bookAuthor); // Add unique author suggestion
            }
        }

        if (!foundBooks.empty()) {
            std::cout << "Books by " << author << ":\n";
            for (auto& book : foundBooks) {
                book.displayInfo();
            }
            return; // Exit after a successful search
        }

        std::cout << "No books found by author \"" << author << "\".\n";

        // Display unique suggestions
        if (!uniqueSuggestions.empty()) {
            std::cout << "Did you mean one of the following authors?\n";
            for (const auto& suggestion : uniqueSuggestions) {
                std::cout << "- " << suggestion << "\n";
            }
        }

        std::cout << YELLOW << "Would you like to try again? (yes/no): " << RESET;
        std::string response;
        std::getline(std::cin, response);
        if (toLowerCase(response) != "yes") {
            std::cout << "Returning to main menu.\n";
            return;
        }
    }
}

// Borrow a book
void borrowBook() {
    std::string isbn, userId;
    std::cout << YELLOW << "Enter the ISBN of the book you want to borrow: " << RESET;
    std::cin >> isbn;
    std::cout << YELLOW << "Enter your User ID: "<< RESET;
    std::cin >> userId;

    Book* book = Database::getInstance()->searchBookByISBN(isbn);
    if (book) {
        User* user = nullptr;
        for (size_t i = 0; i < Database::getInstance()->getUserCount(); ++i) {  // change to size_t
            if (Database::getInstance()->getUser(i).getId() == userId) {
                user = &Database::getInstance()->getUser(i);
                break;
            }
        }
        if (user) {
            book->borrowBook(*user);

            // Log the borrowing activity
            Database::getInstance()->logBorrowing(userId, isbn);
        } else {
            std::cout << "User not found!\n";
        }
    } else {
        std::cout << "Book not found!\n";
    }
}


// Return a book
void returnBook() {
    std::string isbn;
    std::cout << YELLOW << "Enter the ISBN of the book you want to return: " << RESET;
    std::cin >> isbn;

    Book* book = Database::getInstance()->searchBookByISBN(isbn);
    if (book) {
        book->returnBook();
    } else {
        std::cout << "Book not found!\n";
    }
}

// Show all books
void showAllBooks() {
    for (size_t i = 0; i < Database::getInstance()->getBookCount(); ++i) {  // change to size_t
        Database::getInstance()->getBook(i).displayInfo();
    }
}

// Show all users
void showAllUsers() {
    for (size_t i = 0; i < Database::getInstance()->getUserCount(); ++i) {  // change to size_t
        Database::getInstance()->getUser(i).displayInfo();
    }
}

// Displays the borrow history from the database
void showBorrowHistory(){
    std::vector<std::string> history = Database::getInstance()->getBorrowHistory();
    for (const std::string& record : history) {
        std::cout << record << "\n";
    }
}

// Displays and updates the library statistics, then saves them
void showStats() {
    // Get the singleton instance of Database
    Database* database = Database::getInstance();
    
    // Load the statistics from the file
    database->loadStatistics("Data.txt");  

    // Now the statistics are available in the database instance
    std::cout << "Total Books: " << database->getTotalBooks() << "\n";
    std::cout << "Books Checked Out: " << database->getBooksCheckedOut() << "\n";
    std::cout << "Books Added: " << database->getBooksAdded() << "\n";
    std::cout << "Books Deleted: " << database->getBooksDeleted() << "\n";
    std::cout << "Total Users: " << database->getTotalUsers() << "\n";
    std::cout << "Users Deleted: " << database->getUsersDeleted() << "\n";
    std::cout << "Books Borrowed: " << database->getBooksBorrowed() << "\n";

    // Perform actions like adding books, borrowing, etc.
    database->incrementBooksAdded();
    database->incrementBooksCheckedOut();

    // When you need to save the stats
    database->saveStatistics("Data.txt");
}

// Checks and displays the late fee for a specific book by ISBN
void checkLateFees() {
    // Ask for the ISBN to check the late fee
    std::string isbn;
    std::cout << YELLOW << "Enter the ISBN of the book to check late fees: " << RESET;
    std::cin >> isbn;
    
    // Get the book from the database assuming getBookByISBN is available
    Book* book = Database::getInstance()->getBookByISBN(isbn);
    if (book != nullptr) {
       book->checkLateFees();  // Check and display the late fee that is calculated in the book cpp file
    } else {
       std::cout << "Book not found." << std::endl;
    }
}

// Main interface for managing books and users
int main() {
    Database::getInstance()->loadBooks("books.txt");
    Database::getInstance()->loadUsers("users.txt");
    int choice;
    while (true) {
        showMenu();
        choice = getValidIntInput(1, 15);  // Ensure choice is between 1 and 11

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addUser();
                break;
            case 3:
                searchBooksByTitle();
                break;
            case 4:
                searchBooksByAuthor();
                break;
            case 5:
                borrowBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                showAllBooks();
                break;
            case 8:
                showAllUsers();
                break;
            case 9:
                removeUserById();  // Handle removing a user
                break;
            case 10:
                removeBookByISBN();  // Call remove book function
                break;
            case 11:
                checkLateFees();
                break;
            case 12:
                showBorrowHistory();
                break;
            case 13:
                showStats();
                break;
            case 14:
                searchUserByNameOrID();
                break;
            case 15:
                Database::getInstance()->saveBooks("books.txt");
                Database::getInstance()->saveUsers("users.txt");
                std::cout << "Data saved. Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
