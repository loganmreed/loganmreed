#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm> 
#include "Book.h"
#include "user.h"

class Database {
    private:
        static Database* instance;
        std::vector<Book> books;
        std::vector<User> users;
        size_t totalBooks = 0;           // Tracks the total number of books
        size_t booksCheckedOut = 0;      // Tracks the number of books checked out
        size_t booksAdded = 0;           // Tracks the number of books added
        size_t booksDeleted = 0;         // Tracks the number of books deleted
        size_t totalUsers = 0;           // Tracks the total number of users
        size_t usersDeleted = 0;         // Tracks the number of users deleted
        size_t booksBorrowed = 0;        // Tracks the number of books borrowed
    

        Database();
    public:
        static Database* getInstance();

        void loadBooks(const std::string& filename);
        void loadUsers(const std::string& filename);


        void saveBooks(const std::string& filename);
        void saveUsers(const std::string& filename);

        void removeBook(const std::string& isbn);
        void addBook(const Book& book);
        void removeUser(const std::string& userId);
        void addUser(const User& user);

        Book& getBook(int index);
        User& getUser(int index);
        std::vector<Book>& getAllBooks();
        Book* getBookByISBN(const std::string& isbn);

        size_t getBookCount() const;
        size_t getUserCount() const;

        void loadStatistics(const std::string& filename);

        // Method to save statistics to the file
        void saveStatistics(const std::string& filename);
    
        // Methods to increment statistics counters
        void incrementTotalBooks() { totalBooks++; }
        void incrementBooksCheckedOut() { booksCheckedOut++; }
        void incrementBooksAdded() { booksAdded++; }
        void incrementBooksDeleted() { booksDeleted++; }
        void incrementTotalUsers() { totalUsers++; }
        void incrementUsersDeleted() { usersDeleted++; }
        void incrementBooksBorrowed() { booksBorrowed++; }
    
        // Getters for statistics
        size_t getTotalBooks() const { return totalBooks; }
        size_t getBooksCheckedOut() const { return booksCheckedOut; }
        size_t getBooksAdded() const { return booksAdded; }
        size_t getBooksDeleted() const { return booksDeleted; }
        size_t getTotalUsers() const { return totalUsers; }
        size_t getUsersDeleted() const { return usersDeleted; }
        size_t getBooksBorrowed() const { return booksBorrowed; }

        
        std::vector<Book> searchBooksByTitle(const std::string& title);
        std::vector<Book> searchBooksByAuthor(const std::string& author);
        std::vector<User> searchUser(const std::string& query);
        Book* searchBookByISBN(const std::string& isbn);
        void logBorrowing(const std::string& userId, const std::string& isbn);
        std::vector<std::string> getBorrowHistory();
        ~Database();
};

#endif