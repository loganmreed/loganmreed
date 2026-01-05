#include "Book.h"
const double Book::lateFeePerDay = 0.50;

//Default constructor because I don't want the C++ made one
Book::Book(){ 
    isbn = "";
    title = "";
    author = "";
    isAvailable = true;
    waitingList = std::queue<User>();
    format = BookFormat::None;
}

//Parameterized constructor will everything 
Book::Book(std::string Passisbn, std::string Passtitle, std::string Passauthor, bool PassisAvailable, std::queue<User> PasswaitingList, BookFormat Passformat){
    isbn = Passisbn;
    title = Passtitle;
    author = Passauthor;
    isAvailable = PassisAvailable;
    waitingList = PasswaitingList;
    format = Passformat;
}
// Borrow book or add person to waiting list what ever the user wants
void Book::borrowBook(User& user) {
    if (isAvailable) {
        isAvailable = false;
        //dueDate = time(0) + 7 * 24 * 60 * 60; // 7 days from now
        dueDate = time(0) + 1 * 60 * 60; // 1 hour from now
        std::cout << user.getName() << " borrowed the book: " << title << std::endl;
    } else {
        waitingList.push(user);
        std::cout << user.getName() << " is added to the waiting list for: " << title << std::endl;
    }
}

// Returns book and notifies next user assuming the next user is looking over the persons shoulder
void Book::returnBook() {
    if (!waitingList.empty()) {
        User nextUser = waitingList.front();
        waitingList.pop();
        std::cout << nextUser.getName() << " can now borrow the book: " << title << std::endl;
    }
    isAvailable = true;
    std::cout << "The book " << title << " has been returned and is now available." << std::endl;
}

// Returns book availability status its a getter what do you expect
bool Book::getAvailability() const{
    return isAvailable;
}

// Returns book ISBN
std::string Book::getISBN() const {
    return isbn;
}
// Returns book title
std::string Book::getTitle() const{
    return title;
}
// Returns book author
std::string Book::getAuthor()const {
    return author;
}
// Returns book format
BookFormat Book::getFormat() const{
    return format;
}

// Displays book information and waiting list info it says it in the name of the function
void Book::displayInfo() {
    std::string textforFormat = "";
    switch (static_cast<int>(format))
    {
    case 0:
        textforFormat = "Hardback"; //good for baseball
        break;
    case 1:
        textforFormat = "Paperback"; // gets wet to easily
        break;
    case 2:
        textforFormat = "eBook"; // brakes if wet
        break;
    case 3:
        textforFormat = "Audiobook"; // sound is fun
        break;
    case 4:
        textforFormat = "Magazine"; // times
        break;
    default:
        textforFormat = "None"; // you can't even get this option dont know why I have it
        break;
    }
    std::cout << "Book ISBN: " << isbn << ", Title: " << title << ", Author: " << author; 
    std::cout << ", Format: " << textforFormat << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;

    if (!waitingList.empty()) {
        std::cout << "Waiting List: ";
        std::queue<User> tempQueue = waitingList;
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front().getName() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

//Checks if the book is overdue
bool Book::isOverdue() const {
    if (dueDate == 0){
        return false; 
    } 
    time_t now = time(0);
    return now > dueDate; 
}

// Calculates late fee for overdue book
double Book::calculateLateFee() const {
    if (!isOverdue()) {
        return 0.0;
    }
    time_t now = time(0);
    return (difftime(now, dueDate) / (1 * 60 * 60 * 1000) ) * lateFeePerDay;
}

// Checks and displays late fees for the book
// void Book::checkLateFees() {
//     if (!isAvailable) {  // Only check for books that have been borrowed
//         double fee = calculateLateFee();
//         if (fee > 0) {
//             std::cout << "The book \"" << title << "\" has a late fee of $" << std::fixed << std::setprecision(2) << fee << std::endl;
//         } else {
//             std::cout << "The book \"" << title << "\" is not overdue.\n";
//         }
//     } else {
//         std::cout << "The book \"" << title << "\" has not been borrowed.\n";
//     }
// } 

void Book::checkLateFees() {
    if (!isAvailable) {  // Only check for books that have been borrowed
        time_t now = time(0);
        double fee = 0.0;
        int overdueDays = 0;

        if (isOverdue()) {
            // Calculate overdue days
            overdueDays = difftime(now, dueDate) / (60 * 60 * 24);  // Convert seconds to days
            // Calculate late fee
            fee = (difftime(now, dueDate) / (60 * 60 * 24)) * lateFeePerDay;  // Late fee based on overdue days
        }

        if (overdueDays > 0) {
            std::cout << "The book \"" << title << "\" is overdue by " << overdueDays << " day(s) and has a late fee of $" << std::fixed << std::setprecision(2) << fee << std::endl;
        } else {
            std::cout << "The book \"" << title << "\" is not overdue.\n";
        }
    } else {
        std::cout << "The book \"" << title << "\" has not been borrowed.\n";
    }
}

