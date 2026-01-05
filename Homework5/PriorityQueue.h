#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <string>
using namespace std;
#include <iostream>
#include <limits>
#include <sstream> 
#include <cctype>

class PriorityQueue {
    private:
        vector<pair<int,string>> heap;
        void heapInsertAbove(int index);
        void heapInsertBelow(int index);
    public:
        void insert(int number, const string& value);
        void deleteMinimumItem();
        void displayHeapContents() const;
        bool isAllocatedHeapEmpty() const;
        void clearAllocatedHeap();
    
};

#endif