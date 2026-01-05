#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

//const int SIZE = 10;
const string EMPTY = "";//"EMPTY";

class HashTable {
private:
    string* table;
    int SIZE;
    int count;

public:
    HashTable(int initialSize = 10) : SIZE(initialSize), count(0) {
        table = new string[SIZE];
        for (int i = 0; i < SIZE; i++)
            table[i] = EMPTY;
    }
    
    ~HashTable() { delete[] table; }

    int hash(const string &key) {
        unsigned int hash = 0;
        for (char c : key)
            hash = (hash * 31 + c) % SIZE;
        return hash % SIZE;
    }

    void insert(const string &key) {
        if (count == SIZE) {
            cout << "Hash table is full!\n";
            return;
        }

        if (key == ""){
            return;
        }

        int baseindex = hash(key);
        int index = baseindex;
        int steps = 0;

        while (table[index] != EMPTY) {
            if (table[index] == key){
                cout << "Key already exists at index " << index << ".\n";
                return;
            }
            steps++;
            index = ((baseindex + steps*steps) + 1) % SIZE;
            if (steps >= SIZE) break; 
        }
        if (table[index] == EMPTY){
            table[index] = key;
            cout << "Inserted \"" << key << "\" at index " << index << ".\n";
        } else{
            cout << "No available slot found.\n";
            return;
        }

        count++;
    }

    void remove(const string &key) {
        int index = hash(key);
        int steps = 0;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = EMPTY;
                count--;
                cout << "Deleted \"" << key << "\" from index " << index << ".\n";
                return;
            }

            steps++;
            index = ((hash(key) + steps * steps) + 1) % SIZE;
            if (steps >=SIZE){
                break;
            }
        }
        cout << "Key not found.\n";
    }

    bool search(const string &key) {
        int index = hash(key);
        int steps = 0;
        while (table[index] != EMPTY) {
            if (table[index] == key){
                return true;
            }
            steps++;
            index = ((hash(key) + steps * steps) + 1) % SIZE;
            if (steps >= SIZE){
                break;
            }
        }
        return false;
    }

    void accessIndex(int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Invalid index.\n";
            return;
        }

        if (table[index] == EMPTY)
            cout << "Index " << index << " is empty.\n";
        else
            cout << "Index " << index << " contains: \"" << table[index] << "\"\n";
    }

    double loadFactor() {
        return static_cast<double>(count) / SIZE;
    }

    void display() {
        cout << "There are " << count << " items in the table\n";
        cout << "\n+-------+-----------+\n";
        cout << "| Index |   Value   |\n";
        cout << "+-------+-----------+\n";

        for (int steps = 0; steps < SIZE; steps++) {
            cout << "| " << setw(5) << steps << " | ";
            cout << setw(9) << table[steps] << " |\n";
        }
        cout << "+-------+-----------+\n";
    }

    void rehash(int newSize) {
        if (newSize <= count) {
            cout << "New size must be greater than current count of items.\n";
            return;
        }

        cout << "Rehashing to new size = " << newSize << "...\n";

        string* oldTable = table;
        int oldSize = SIZE;

        table = new string[newSize];
        SIZE = newSize;
        count = 0;

        for (int i = 0; i < SIZE; i++) table[i] = EMPTY;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != EMPTY)
                insert(oldTable[i]);
        }

        delete[] oldTable;

        cout << "Rehashing complete!\n";
    }
};

void showMenu() {
    std::cout << "====================================\n"
              << "          HASH TABLE PROGRAM         \n"
              << "====================================\n\n";

    std::cout << "  [1]  Display all elements\n";
    std::cout << "  [2]  Insert element\n";
    std::cout << "  [3]  Delete element\n";
    std::cout << "  [4]  Access element by index\n";
    std::cout << "  [5]  Search based on content\n";
    std::cout << "  [6]  Display load factor\n";
    std::cout << "  [7]  Change Size of table\n";
    std::cout << "  [8]  Quit\n";
    std::cout << "====================================\n\n";
    std::cout << "Please choose an option: ";
}

int getValidIntInput(int min, int max) {
    int choice;
    std::string input;

    while (true) {
        std::cout << "Please enter a number between " << min << " and " << max << ": ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Invalid input. You didn't enter anything.\nPlease enter a valid number between " << min << " and " << max << "." << std::endl;
            continue;
        }

        std::stringstream ss(input);

        if (ss >> choice) {
            if (ss.eof() && choice >= min && choice <= max) {
                return choice;
            } else if (choice < min || choice > max) {
                std::cout << "Invalid input. The number " << choice << " is out of the valid range (" << min << " to " << max << ").\nPlease enter a number within this range." << std::endl;
            } else {
                std::cout << "Invalid input. The number " << choice << " is not within the range (" << min << " to " << max << ").\nTry again." << std::endl;
            }
        } else {
            bool hasInvalidChar = false;
            std::string invalidChars;
            for (char c : input) {
                if (!isdigit(c) && c != '-' && c != '+') {
                    hasInvalidChar = true;
                    invalidChars += c;
                }
            }

            if (hasInvalidChar) {
                std::cout << "Invalid input. You entered the following invalid characters: " << invalidChars << ".\nPlease enter only numbers that are positive values." << std::endl;
            } else {
                std::cout << "Invalid input. It looks like there were extra spaces or invalid formatting.\nEnsure you enter a clean integer between " << min << " and " << max << "." << std::endl;
            }
        }
    }
}

int main(){
    HashTable hashtable;
    while (true) {
        showMenu();
        int choice = getValidIntInput(1, 8);
        switch (choice) {
        case 1:
            hashtable.display();
            break;
        case 2: {
            cout << "Enter string to insert: ";
            string val;
            getline(cin, val);
            hashtable.insert(val);
            break;
        }
        case 3: {
            cout << "Enter string to delete: ";
            string val;
            getline(cin, val);
            hashtable.remove(val);
            break;
        }
        case 4: {
            cout << "Enter index to access: ";
            int idx;
            cin >> idx;
            cin.ignore();
            hashtable.accessIndex(idx);
            break;
        }
        case 5: {
            cout << "Enter string to search for: ";
            string val;
            getline(cin, val);
            cout << (hashtable.search(val) ? "Element found.\n" : "Element not found.\n");
            break;
        }
        case 6:
            cout << "Load factor: " << hashtable.loadFactor() << "\n";
            break;
        case 7: {
            cout << "Enter new hash table size: ";
            int newSize;
            cin >> newSize;
            cin.ignore();
            hashtable.rehash(newSize);
            break;
        }
        case 8:
            cout << "Exiting program.\n";
            return 0;
            break;
    }
    }
    return 0;
}