#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string> 
#include <queue>
#include <ctime>
#include <iomanip> 
#include <chrono>
#include "user.h"


enum class BookFormat {
    Hardback,
    Paperback,
    eBook,
    Audiobook,
    Magazine,
    None
};

//const double Book::lateFeePerDay = 0.50;

class Book{
    private:
        std::string isbn;
        std::string title;
        std::string author;
        BookFormat format;
        bool isAvailable;
        std::queue<User> waitingList;
        time_t dueDate;  
        static const double lateFeePerDay;
        //time_t dueDate; 
        
    public:
        Book();
        Book(std::string isbn, std::string title, std::string author, bool isAvailable, std::queue<User> waitingList, BookFormat format);
        void borrowBook(User& user);
        void returnBook();
        bool getAvailability() const;
        std::string getISBN() const;
        std::string getAuthor() const;
        BookFormat getFormat() const; 
        std::string getTitle() const;
        void displayInfo();

        void setDueDate(time_t due) { dueDate = due; }
        time_t getDueDate() const { return dueDate; }
        //bool isAvailable() const { return isAvailable; }
        //void setAvailable(bool status) { isAvailable = status; }

        bool isOverdue() const;
        double calculateLateFee() const;
        void checkLateFees();
};

#endif