#include "PriorityQueue.h"

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
                std::cout << "AInvalid input. The number " << choice << " is out of the valid range (" << min << " to " << max << ").\nPlease enter a number within this range." << std::endl;
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

void showMenu() {
    std::cout << "====================================\n"
              << "        PRIORITY QUEUE PROGRAM       \n"
              << "====================================\n\n";

    std::cout << "  [1]  Insert element\n";
    std::cout << "  [2]  Delete minimum element\n";
    std::cout << "  [3]  Display heap contents\n";
    std::cout << "  [4]  Check if heap is empty\n";
    std::cout << "  [5]  Clear allocated heap\n";
    std::cout << "  [6]  Quit\n";

    std::cout << "====================================\n\n";

    std::cout << "Please choose an option: ";
}


int main() {
    PriorityQueue priorityqueue;
    int choice;

    while(true){
        showMenu();
        choice = getValidIntInput(1, 6);
        switch (choice){
            case 1: {
                std::string number;
                std::string value;
                
                while(true){
                    std::cout << "Enter the priority of the element:\n";
                    std::cin >> number;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    bool allNum = true;
                    for (char c : number){
                        if(!isdigit(c)){
                            std::cout << "Invalid input. Please input a number.\n";
                            allNum = false;
                            break;
                        }
                    }
                    if (allNum){
                        break;
                    }
                }

                while (true){
                    std::cout << "Enter the element's data:\n";
                    //std::cin >> value;
                    std::getline(std::cin, value);
                    if (value.empty()){
                        std::cout << "Please enter data.\n";
                        continue;
                    } else{
                        break;
                    }
                }
                
                priorityqueue.insert(stoi(number), value);
                std::cout << "\nElement inserted.\n";
                break;
            }
        case 2:
            cout << "\nMinimum element deleted.\nMinimum was:\n";
            priorityqueue.deleteMinimumItem();
            cout << "\n";
            break;

        case 3:
            priorityqueue.displayHeapContents();
            break;

        case 4:
            cout << "\n" << (priorityqueue.isAllocatedHeapEmpty() ? "Allocated Heap is empty." : "Allocated Heap is not empty.") << "\n";
            break;

        case 5:
            priorityqueue.clearAllocatedHeap();
            cout << "\nThe Allocated heap is cleared.";
            break;
        case 6:
            priorityqueue.clearAllocatedHeap();
            cout << "\nExiting program.\n";
            return 0;   
        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    }

}