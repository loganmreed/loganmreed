#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

const int SIZE = 10;
const string EMPTY = "EMPTY";
const string DELETED = "DELETED";
const int constant = 1;

class HashTable {
private:
    string table[SIZE];
    int count;

public:
    HashTable() : count(0) {
        for (int i = 0; i < SIZE; i++)
            table[i] = EMPTY;
    }

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

        int baseIndex = hash(key);
        int index = baseIndex;
        int i = 0;
        int firstDeleted = -1;  

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Key already exists at index " << index << ".\n";
                return;
            }
            if (table[index] == DELETED && firstDeleted == -1) {
                firstDeleted = index; 
            }

            i++;
            index = (baseIndex + i*i + (constant + i)) % SIZE; //(baseIndex + i * i) % SIZE;
            if (i >= SIZE) break; 
        }

        
        if (firstDeleted != -1) {
            table[firstDeleted] = key;
            cout << "Inserted \"" << key << "\" at deleted index " << firstDeleted << ".\n";
        } else if (table[index] == EMPTY) {
            table[index] = key;
            cout << "Inserted \"" << key << "\" at index " << index << ".\n";
        } else {
            cout << "No available slot found.\n";
            return;
        }

        count++;
    }

    void remove(const string &key) {
        int index = hash(key);
        int i = 0;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                count--;
                cout << "Deleted \"" << key << "\" from index " << index << ".\n";
                return;
            }
            i++;
            index = (hash(key) + i*i + (constant + i)) % SIZE;//(hash(key) + i * i) % SIZE;
            if (i >= SIZE)
                break;
        }
        cout << "Key not found.\n";
    }

    bool search(const string &key) {
        int index = hash(key);
        int i = 0;
        while (table[index] != EMPTY) {
            if (table[index] == key)
                return true;
            i++;
            index = (hash(key) + i * i + (constant + i)) % SIZE;
            if (i >= SIZE)
                break;
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
        else if (table[index] == DELETED)
            cout << "Index " << index << " has a deleted marker.\n";
        else
            cout << "Index " << index << " contains: \"" << table[index] << "\"\n";
    }

    double loadFactor() {
        return static_cast<double>(count) / SIZE;
    }

    void display() {
        cout << "\n+-------+-----------+\n";
        cout << "| Index |   Value   |\n";
        cout << "+-------+-----------+\n";

        for (int i = 0; i < SIZE; i++) {
            cout << "| " << setw(5) << i << " | ";
            cout << setw(9) << table[i] << " |\n";
        }
        cout << "+-------+-----------+\n";
    }

    void showHashFunction(const string &key) {
        int baseHash = hash(key);
        int index = -1;
        int i = 0;

        while (true) {
            index = (baseHash + i * i ) % SIZE;
            if (table[index] == EMPTY || table[index] == key)
                break;
            i++;
            if (i >= SIZE)
                break;
        }

        cout << "\n--- HASH FUNCTION DEBUG ---\n";
        cout << "Given key: \"" << key << "\"\n";
        cout << "Base hash (hash(key)): " << baseHash << "\n";
        cout << "Probe attempt (i): " << i << "\n";
        cout << "Table size: " << SIZE << "\n";
        cout << "Calculation: (" << baseHash << " + " << i << "^2) % "
             << SIZE << " = " << index << "\n";
        cout << "Final index: " << index << "\n";
        cout << "---------------------------\n";
    }
};

// ---------- MENU FUNCTIONS ----------
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
    std::cout << "  [7]  Quit\n";
    std::cout << "  [8]  Show hash function result\n";
    std::cout << "====================================\n\n";
    std::cout << "Please choose an option: ";
}

int getValidIntInput(int min, int max) {
    int choice;
    string input;

    while (true) {
        getline(cin, input);
        if (input.empty()) {
            cout << "Invalid input. Enter a number between " << min << " and " << max << ".\n";
            continue;
        }

        stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= min && choice <= max)
            return choice;
        else
            cout << "Invalid input. Try again.\n";
    }
}

// ---------- MAIN ----------
int main() {
    HashTable ht;
    bool running = true;

    while (running) {
        showMenu();
        int choice = getValidIntInput(1, 8);

        switch (choice) {
        case 1:
            ht.display();
            break;
        case 2: {
            cout << "Enter string to insert: ";
            string val;
            getline(cin, val);
            ht.insert(val);
            break;
        }
        case 3: {
            cout << "Enter string to delete: ";
            string val;
            getline(cin, val);
            ht.remove(val);
            break;
        }
        case 4: {
            cout << "Enter index to access: ";
            int idx;
            cin >> idx;
            cin.ignore();
            ht.accessIndex(idx);
            break;
        }
        case 5: {
            cout << "Enter string to search for: ";
            string val;
            getline(cin, val);
            cout << (ht.search(val) ? "Element found.\n" : "Element not found.\n");
            break;
        }
        case 6:
            cout << "Load factor: " << ht.loadFactor() << "\n";
            break;
        case 7:
            running = false;
            cout << "Exiting program.\n";
            break;
        case 8: {
            cout << "Enter key to hash: ";
            string key;
            getline(cin, key);
            ht.showHashFunction(key);
            break;
        }
        }
        cout << "\n";
    }
    return 0;
}
