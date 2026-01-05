#include "Database.h"

// Initializes the static instance of Database
Database* Database::instance = nullptr;

Database::Database(){

}

// Returns the singleton instance of Database
Database* Database::getInstance(){
    if (instance == nullptr){
        instance = new Database();
    }
    return instance;
}

// Loads books from a file into the database
void Database::loadBooks(const std::string& filename) {
    std::ifstream infile(filename);
    if (infile.is_open()) {
        std::string isbn, title, author;
        bool isAvailable;
        int format;
        booksCheckedOut = 0;
        totalBooks = books.size();

        // Read each book in the format using the Mohs scale
        while (std::getline(infile, isbn)) {
            std::getline(infile, title);
            std::getline(infile, author);
            infile >> isAvailable >> format;
            infile.ignore();  

            // Create and add the book to the list
            books.push_back(Book(isbn, title, author, isAvailable, {}, static_cast<BookFormat>(format)));
            //totalBooks++; 
        }
        totalBooks = books.size();
        for (const auto& books : books){
            if (!books.getAvailability()){
                booksCheckedOut++;
                //std::cout << "booksCheckedOut" << booksCheckedOut;
            }
        }
        infile.close();
    } else {
        std::cerr << "Error opening file check your pathways: " << filename << std::endl;
    }
}

// Loads users from a file into the database
void Database::loadUsers(const std::string& filename) {
    std::ifstream infile(filename);
    if (infile.is_open()) {
        std::string id, firstName, lastName, subject;
        int type, gradeLevel;
        
        users.clear(); // Reset user list
        totalUsers = users.size();
        //totalUsers = 0; // Reset count

        while (infile >> id >> firstName >> lastName >> type) {
            std::string name = firstName + " " + lastName;
            //totalUsers++; // Correctly count users

            if (type == static_cast<int>(UserType::Teacher)) {
                infile >> gradeLevel >> subject;
                users.push_back(User(id, name, static_cast<UserType>(type), gradeLevel, subject));
            } else if (type == static_cast<int>(UserType::Student)) {
                infile >> gradeLevel;
                users.push_back(User(id, name, static_cast<UserType>(type), gradeLevel));
            } else {
                users.push_back(User(id, name, static_cast<UserType>(type)));
            }
        }
        totalUsers = users.size();
        infile.close();
        //std::cout << "Loaded Total Users: " << totalUsers << std::endl; // Debug print
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

// Returns the vector of all books
std::vector<Book>& Database::getAllBooks() {
    return books;
}

// Saves the vector of books to a file
void Database::saveBooks(const std::string& filename) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& book : books) {
            outfile << book.getISBN() << "\n" << book.getTitle() << "\n" << book.getAuthor() << "\n"
                    << book.getAvailability() << " " << static_cast<int>(book.getFormat()) << "\n";
        }
        outfile.close();
    }
}

// Saves the list of users to a file
void Database::saveUsers(const std::string& filename) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& user : users) {
            // Write common fields
            outfile << user.getId() << " " << user.getName() << " " << static_cast<int>(user.getType());

            // Conditionally write gradeLevel and subject
            if (user.getType() == UserType::Teacher) {
                outfile << " " << user.getGradeLevel() << " " << user.getSubject();
            } else if (user.getType() == UserType::Student) {
                outfile << " " << user.getGradeLevel();
            }

            outfile << "\n";
        }
        outfile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

// Add a book to the database
void Database::addBook(const Book& book) {
    books.push_back(book);
    //totalBooks++;
    booksAdded++;
}

// Remove a book by ISBN
void Database::removeBook(const std::string& isbn) {
    // Find the book by ISBN and remove it from the list
    auto it = std::remove_if(books.begin(), books.end(), [&isbn](const Book& book) {
        return book.getISBN() == isbn;
    });

    // If we found the book, erase it from the vector
    if (it != books.end()) {
        books.erase(it, books.end());
        totalBooks--;
        booksDeleted++;
    }
}


// Add a user to the database
void Database::addUser(const User& user) {
    users.push_back(user);
    totalUsers = users.size();  // Ensure accuracy
    std::cout << "Total Users after adding: " << totalUsers << std::endl;
}

// Removes a user from the database by ID
void Database::removeUser(const std::string& userId) {
    // Find the user by their ID and remove them from the list
    auto it = std::remove_if(users.begin(), users.end(), [&userId](const User& user) {
        return user.getId() == userId;
    });

    // If we found the user, erase them from the vector
    if (it != users.end()) {
        users.erase(it, users.end());
        totalUsers--;
        usersDeleted++;
    }
}

// Get a book by index
Book& Database::getBook(int index) {
    return books.at(index);
}

// Get a user by index
User& Database::getUser(int index) {
    return users.at(index);
}

// Get the count of books
size_t Database::getBookCount() const {
    return books.size();
}

// Get the count of users
size_t Database::getUserCount() const {
    return users.size();
}

// Searches for books by title
std::vector<Book> Database::searchBooksByTitle(const std::string& title) {
    std::vector<Book> results;
    for (const auto& book : books) { 
        if (book.getTitle() == title) {
            results.push_back(book);
        }
    }
    return results;
}

// Retrieves a book by its ISBN
Book* Database::getBookByISBN(const std::string& isbn) {
    // Assuming you have a container (like a vector or map) to store books
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;  // Return pointer to the book if found
        }
    }
    return nullptr;  // Return nullptr if no book is found with the given ISBN
}

// Searches for a user by name or ID
std::vector<User> Database::searchUser(const std::string& query) {
    std::vector<User> matchingUsers;
    for (const auto& user : users) {  // Assuming `users` is a collection of User objects
        if (user.getName() == query || user.getId() == query) {
            matchingUsers.push_back(user);
        }
    }
    return matchingUsers;
}


// Search by author
std::vector<Book> Database::searchBooksByAuthor(const std::string& author) {
    std::vector<Book> results;
    for (const auto& book : books) {  // Add 'this->' to refer to the member variable
        if (book.getAuthor() == author) {
            results.push_back(book);
        }
    }
    return results;
}

// Search by ISBN
Book* Database::searchBookByISBN(const std::string& isbn) {
    for (auto& book : books) {  // Add 'this->' to refer to the member variable
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;  // No book found
}

// Logs the borrowing activity to a file
void Database::logBorrowing(const std::string& userId, const std::string& isbn) {
    std::ofstream borrowFile("borrow_history.txt", std::ios::app);
    if (borrowFile.is_open()) {
        // Get current date or any date logic here
        time_t now = time(0);
        char* dateTime = ctime(&now);

        borrowFile << "User ID: " << userId
                   << " ISBN: " << isbn
                   << " Borrowed on: " << dateTime
                   << "\n";

        borrowFile.close();
        //booksBorrowed++;
        //booksCheckedOut++;
    } else {
        std::cerr << "Error opening borrow history file.\n";
    }
}

// Retrieves the borrowing history from a file
std::vector<std::string> Database::getBorrowHistory() {
    std::vector<std::string> history;
    std::ifstream borrowFile("borrow_history.txt");
    //booksBorrowed++;
    //booksCheckedOut++;
    if (borrowFile.is_open()) {
        std::string line;
        while (std::getline(borrowFile, line)) {
            history.push_back(line);
        }
        borrowFile.close();
    } else {
        std::cerr << "Error opening borrow history file.\n";
    }

    return history;
}

// Destructor to clean up instance
Database::~Database() {
    delete instance;
    instance = nullptr;
}

// Saves the database statistics to a file
void Database::saveStatistics(const std::string& filename) {
    std::ofstream statsFile(filename);
    if (statsFile.is_open()) {
        // Debugging print for totalUsers
        //std::cout << "Saving stats, Total Users: " << totalUsers << std::endl; // Debug

        statsFile << "Total Books: " << totalBooks << "\n";
        statsFile << "Books Checked Out: " << booksCheckedOut << "\n";
        booksAdded = totalBooks + booksDeleted;
        statsFile << "Books Added: " << booksAdded << "\n";
        statsFile << "Books Deleted: " << booksDeleted << "\n";
        statsFile << "Total Users: " << totalUsers << "\n"; // Check if this is correct
        statsFile << "Users Deleted: " << usersDeleted << "\n";
        statsFile << "Books Borrowed: " << booksBorrowed << "\n";
        statsFile.close();
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

// Loads the database statistics from a file
void Database::loadStatistics(const std::string& filename) {
    std::ifstream statsFile(filename);
    if (statsFile.is_open()) {
        std::string line;
        while (std::getline(statsFile, line)) {
            if (line.find("Total Users:") != std::string::npos) {
                //totalUsers = std::stoi(line.substr(line.find(":") + 2));
                //std::cout << "Loaded Total Users: " << totalUsers << std::endl;  // Debug output
            }
        }
        statsFile.close();
    } else {
        //totalUsers = 0;
    }
}

