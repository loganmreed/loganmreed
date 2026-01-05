#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;

const int TH = 16;
const int LIM = 4;

void ins(int a[], int l, int h) {
    for (int i = l + 1; i <= h; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= l && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

int part(int a[], int l, int h) {
    int p = l + (h - l + 1) / 2 - 1;
    int x = a[p];
    int i = l - 1;
    int j = h + 1;

    while (true) {
        do { i++; } while (a[i] < x);
        do { j--; } while (a[j] > x);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}

void qs(int a[], int l, int h, int d = 0) {
    while (l < h) {
        if (h - l + 1 <= TH) {
            ins(a, l, h);
            break;
        }

        int m = part(a, l, h);

        if (d < LIM) {
            if (m - l < h - m) {
                thread t(qs, a, l, m, d + 1);
                qs(a, m + 1, h, d + 1);
                t.join();
            } else {
                thread t(qs, a, m + 1, h, d + 1);
                qs(a, l, m, d + 1);
                t.join();
            }
            break;
        } else {
            if (m - l < h - m) {
                qs(a, l, m, d);
                l = m + 1;
            } else {
                qs(a, m + 1, h, d);
                h = m;
            }
        }
    }
}

int main() {
    int v;
    int n = 0;

    cout << "Enter numbers (-1 to stop): ";
    while (cin >> v && v != -1) {
        n++;
    }

    if (n == 0) {
        cout << "No numbers entered." << endl;
        return 0;
    }

    int* a = new int[n];

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the numbers again: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    qs(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    string s;
    cin >> s;

    delete[] a;
    return 0;
}
