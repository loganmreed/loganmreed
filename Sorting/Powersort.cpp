#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void insertionSort(vector<double>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
vector<double> powerSort(const vector<double>& input) {
    vector<double> small, big;
    for (double x : input) {
        if (x > M_E) {
            big.push_back(x);
        } else {
            small.push_back(x);
        }
    }
    sort(big.begin(), big.end());
    insertionSort(small);
    vector<double> result;
    result.reserve(input.size());
    result.insert(result.end(), small.begin(), small.end());
    result.insert(result.end(), big.begin(), big.end());
    return result;
}

int main() {
    vector<double> nums;
    double x;

    cout << "Enter numbers (-1 to stop): ";
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }

    vector<double> sorted = powerSort(nums);

    cout << "Power-sorted array: ";
    for (double num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
