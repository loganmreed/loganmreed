#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

const int SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[SIZE];
    int count;

public:
    HashTable() : count(0) {
        for (int i = 0; i < SIZE; i++)
            table[i] = EMPTY;
    }

    int hash(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        if (count == SIZE) {
            cout << "Hash table is full!\n";
            return;
        }

        int index = hash(key);
        int start = index;

        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % SIZE;
            if (index == start) {
                cout << "No available slot found.\n";
                return;
            }
        }

        table[index] = key;
        count++;
        cout << "Inserted " << key << " at index " << index << ".\n";
    }

    void remove(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                count--;
                cout << "Deleted " << key << " from index " << index << ".\n";
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                break;
        }
        cout << "Key not found.\n";
    }

    bool search(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key)
                return true;
            index = (index + 1) % SIZE;
            if (index == start)
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
            cout << "Index " << index << " contains: " << table[index] << "\n";
    }

    double loadFactor() {
        return static_cast<double>(count) / SIZE;
    }

    void display() {
        cout << "\n+-------+---------+\n";
        cout << "| Index |  Value  |\n";
        cout << "+-------+---------+\n";

        for (int i = 0; i < SIZE; i++) {
            cout << "| " << setw(5) << i << " | ";
            if (table[i] == EMPTY)
                cout << setw(7) << "EMPTY";
            else if (table[i] == DELETED)
                cout << setw(7) << "DELETED";
            else
                cout << setw(7) << table[i];
            cout << " |\n";
        }
        cout << "+-------+---------+\n";
    }

    void showHashFunction(int key) {
        int index = hash(key);
        cout << "\n--- HASH FUNCTION DEBUG ---\n";
        cout << "Hash function: index = key % SIZE\n";
        cout << "Given key: " << key << "\n";
        cout << "Table size: " << SIZE << "\n";
        cout << "Calculation: " << key << " % " << SIZE << " = " << index << "\n";
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
    std::string input;

    while (true) {
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Invalid input. You didn't enter anything.\nPlease enter a valid number between " << min << " and " << max << ".\n";
            continue;
        }

        std::stringstream ss(input);

        if (ss >> choice) {
            if (ss.eof() && choice >= min && choice <= max) {
                return choice;
            } else {
                std::cout << "Invalid number. Enter between " << min << " and " << max << ".\n";
            }
        } else {
            std::cout << "Invalid input. Please enter numbers only.\n";
        }
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
            cout << "Enter element to insert: ";
            int val;
            cin >> val;
            cin.ignore();
            ht.insert(val);
            break;
        }
        case 3: {
            cout << "Enter element to delete: ";
            int val;
            cin >> val;
            cin.ignore();
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
            cout << "Enter element to search for: ";
            int val;
            cin >> val;
            cin.ignore();
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
            int key;
            cin >> key;
            cin.ignore();
            ht.showHashFunction(key);
            break;
        }
        }
        cout << "\n";
    }
    return 0;
}
