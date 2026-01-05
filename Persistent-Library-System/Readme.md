Persistent Library Management System (C++)

This is a full-scale Library Management System (LMS) designed with an emphasis on Software Architecture and Data Integrity. It moves beyond simple CRUD operations by implementing persistent storage, transactional logic for waitlists, and rigorous input validation engines.

- Singleton Design Pattern: Implemented a centralized Database controller to ensure a "Single Source of Truth" across the application lifecycle.

- Persistence Layer: Custom file-handling logic that synchronizes objects (Books, Users, Waitlists) with flat-file databases (.txt), ensuring data survives application restarts.

- The Erase-Remove Idiom: Utilizes modern C++ std::remove_if with Lambda Expressions for high-performance collection filtering.

- ISBN-13 Integrity: Implemented the Weighted Modulus 10 algorithm to mathematically verify ISBNs before entry.

- Fail-Safe Input Handling: Developed a custom stringstream parser for std::cin to prevent buffer overflows and infinite loop crashes—ensuring a "bulletproof" user interface.

- Time-Series Penalties: Integrated <ctime> for real-time calculation of late fees based on Unix timestamps and daily differentials.

Book.CPP & Book.h

+--------------------------------+
|            Book                |
+--------------------------------+
| - isbn: std::string            |
| - title: std::string           |
| - author: std::string          |
| - format: BookFormat           |
| - isAvailable: bool            |
| - waitingList: std::queue<User>|
| - dueDate: time_t              |
| - static lateFeePerDay: double |
+--------------------------------+
| + Book()                       |
| + Book(isbn, title, author,    |
|   isAvailable, waitingList,    |
|   format)                      |
| + borrowBook(user: User&)      |
| + returnBook()                 |
| + getAvailability(): bool      |
| + getISBN(): std::string       |
| + getAuthor(): std::string     |
| + getFormat(): BookFormat      |
| + getTitle(): std::string      |
| + displayInfo()                |
| + setDueDate(due: time_t)      |
| + getDueDate(): time_t         |
| + isOverdue(): bool            |
| + calculateLateFee(): double   |
| + checkLateFees()              |
+--------------------------------+

Notes:
- `Book format` is an enumeration enum class `Hardback, Paperback, eBook, Audiobook, Magazine`

- `waitingList` is a queue of `User` objects.

- `dueDate` is a type `time_t` to store the due date.

Database.CPP & Database.h

+------------------------------------------------+
|                 Database                      |
+------------------------------------------------+
| - static instance: Database*                  |
| - books: std::vector<Book>                    |
| - users: std::vector<User>                    |
| - totalBooks: size_t                          |
| - booksCheckedOut: size_t                     |
| - booksAdded: size_t                          |
| - booksDeleted: size_t                        |
| - totalUsers: size_t                          |
| - usersDeleted: size_t                        |
| - booksBorrowed: size_t                       |
+------------------------------------------------+
| + static getInstance(): Database*             |
| + loadBooks(filename: std::string)            |
| + loadUsers(filename: std::string)            |
| + saveBooks(filename: std::string)            |
| + saveUsers(filename: std::string)            |
| + removeBook(isbn: std::string)               |
| + addBook(book: Book)                         |
| + removeUser(userId: std::string)             |
| + addUser(user: User)                         |
| + getBook(index: int): Book&                  |
| + getUser(index: int): User&                  |
| + getAllBooks(): std::vector<Book>&           |
| + getBookByISBN(isbn: std::string): Book*     |
| + getBookCount(): size_t                      |
| + getUserCount(): size_t                      |
| + loadStatistics(filename: std::string)       |
| + saveStatistics(filename: std::string)       |
| + incrementTotalBooks()                       |
| + incrementBooksCheckedOut()                  |
| + incrementBooksAdded()                       |
| + incrementBooksDeleted()                     |
| + incrementTotalUsers()                       |
| + incrementUsersDeleted()                     |
| + incrementBooksBorrowed()                    |
| + getTotalBooks(): size_t                     |
| + getBooksCheckedOut(): size_t                |
| + getBooksAdded(): size_t                     |
| + getBooksDeleted(): size_t                   |
| + getTotalUsers(): size_t                     |
| + getUsersDeleted(): size_t                   |
| + getBooksBorrowed(): size_t                  |
| + searchUser(const std::string& query)        |
| + searchBooksByTitle(title: std::string)      |
| + searchBooksByAuthor(author: std::string)    |
| + searchBookByISBN(isbn: std::string): Book*  |
| + logBorrowing(userId: std::string, isbn: std::string) |
| + getBorrowHistory(): std::vector<std::string> |
| ~Database()                                   |
+------------------------------------------------+

Notes:
- Singleton Pattern: with `static Database* instance` and `getInstance()`.

main.cpp & main.h

+-----------------------------------+
|              Main                 |
+-----------------------------------+
| - RESET: const char*              |
| - BOLD: const char*               |
| - GREEN: const char*              |
| - BLUE: const char*               |
| - YELLOW: const char*             |
| - CYAN: const char*               |
| - RED: const char*                |
+-----------------------------------+
| + getValidIntInput(min: int, max: int): int |
| + showMenu(): void                |
| + removeBookByISBN(): void        |
| + removeUserById(): void          |
| + isValidISBN(isbn: std::string): bool |
| + addBook(): void                 |
| + isValidID(id: std::string): bool|
| + isValidName(name: std::string): bool |
| + formatName(str: std::string): std::string |
| + searchUserByNameOrID(): void    |
| + addUser(): void                 |
| + searchBooksByTitle(): void      |
| + toLowerCase(str: std::string): std::string |
| + searchBooksByAuthor(): void     |
+-----------------------------------+

Notes:
- ANSI Escape Codes: to make the outputs more readable.

User.cpp & user.h

+---------------------------------------------------+
|                      User                         |
+---------------------------------------------------+
| - id: std::string                                 |
| - name: std::string                               |
| - type: UserType                                  |
| - gradeLevel: int                                 |
| - subject: std::string                            |
+---------------------------------------------------+
| + User()                                          |
| + User(id: std::string, name: std::string,        |
|   type: UserType, gradeLevel: int)                |
| + User(id: std::string, name: std::string,        |
|   type: UserType, subject: std::string)           |
| + User(id: std::string, name: std::string,        |
|   type: UserType)                                 |
| + User(idPass: std::string, namePass: std::string, |
|   typePass: UserType, gradelevelPass: int,        |
|   subjectPass: std::string)                       |
| + getId(): std::string                            |
| + getName(): std::string                          |
| + getType(): UserType                             |
| + getGradeLevel(): int                            |
| + getSubject(): std::string                       |
| + setId(id: std::string): void                    |
| + setName(name: std::string): void                |
| + setType(type: UserType): void                   |
| + setGradeLevel(gradeLevel: int): void            |
| + setSubject(subject: std::string): void          |
| + displayInfo(): void                             |
+---------------------------------------------------+

Notes 

- `UserType`: is an enumeration enum class (`Student`, `Teacher`, `Staff`, `Other`).


To compile the program, use the following commands:
- Basic run: `g++ -o library_system main.cpp Database.cpp Book.cpp User.cpp`
- For improved performance, catch warnings, and enable debugging: `g++ -O3 -Wall -pedantic -g -o library_system main.cpp Database.cpp Book.cpp User.cpp`

Totals(headers & cpp):
- Function Count: 183 functions
- Longest Function Length: 64 lines
- Average Function Length: 6.78 lines
- Line Count: 1550 lines of code
- Class Count: 3 Classes
- Logical Line of Code (LLOC): 1169 (lines of code excluding empty and comment lines)
- Global Variable Usage: 0 
- Variable Count: 179
- Comment Quality: 205 (total comment lines)
- Character Count: 47833 characters
- Character Count Excluding Spaces: 35590 characters
- Word Count: 5955 words
- Most Used Keyword: if
- Indentation Levels: 20 (max indentation level)

Error Handling:
- Inputs:
    - makes sure the inputs are in range 
    - makes sure inputs are not empty
    - makes sure they are numbers
    - reprompts user for invalids
    - Uses While loops to prompt the user till a valid is given
    - also some helper functions to make sure inputs are formated correctly
