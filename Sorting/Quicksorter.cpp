#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;

const int INSERTION_SORT_THRESHOLD = 16;
const int MAX_THREADS = 4;

void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int hoarePartition(int arr[], int low, int high) {
    int pivotIndex = low + (high - low + 1) / 2 - 1;
    int pivot = arr[pivotIndex];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high, int depth = 0) {
    while (low < high) {
        if (high - low + 1 <= INSERTION_SORT_THRESHOLD) {
            insertionSort(arr, low, high);
            break;
        }

        int pi = hoarePartition(arr, low, high);

        if (depth < MAX_THREADS) {
            if (pi - low < high - pi) {
                thread t(quickSort, arr, low, pi, depth + 1);
                quickSort(arr, pi + 1, high, depth + 1);
                t.join();
            } else {
                thread t(quickSort, arr, pi + 1, high, depth + 1);
                quickSort(arr, low, pi, depth + 1);
                t.join();
            }
            break;
        } else {
            if (pi - low < high - pi) {
                quickSort(arr, low, pi, depth);
                low = pi + 1;
            } else {
                quickSort(arr, pi + 1, high, depth);
                high = pi;
            }
        }
    }
}

int main() {
    int temp;
    int count = 0;

    cout << "Enter numbers (-1 to stop): ";
    while (cin >> temp && temp != -1) {
        count++;
    }

    if (count == 0) {
        cout << "No numbers entered." << endl;
        return 0;
    }

    // Allocate dynamic array
    int* arr = new int[count];

    // Reset input stream to read numbers again
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the numbers again: ";
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, count - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    std::string x;
    cin >> x;
    delete[] arr; // free memory
    return 0;
}
