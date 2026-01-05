#include "PriorityQueue.h"

void PriorityQueue::heapInsertAbove(int index){
    while(index > 0){
        int parent = (index-1)/2;
        if(heap[index].first < heap[parent].first){
            swap(heap[index],heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapInsertBelow(int index){
    int size = heap.size();
    while(true){
        int left = 2 * index + 1;
        int right = 2* index + 2;
        int smallest = index;
        if (left < size && heap[left].first < heap[smallest].first){
            smallest = left;
        }
        if (right < size && heap[right].first < heap[smallest].first){
            smallest = right;
        }
        if (smallest != index){
            swap(heap[index],heap[smallest]);
            index = smallest;
        } else{
            break;
        }
    }
}

void PriorityQueue::insert(int number, const string& value){
    heap.push_back({number,value});
    heapInsertAbove(heap.size() - 1);
}

void PriorityQueue::deleteMinimumItem(){
    if (heap.empty()){
        return;
    }
    cout << heap[0].first;
    heap[0] = heap.back();
    heap.pop_back();
    heapInsertBelow(0);
}

void PriorityQueue::displayHeapContents() const{
    if (heap.empty()){
        cout << "The queue is empty.\n";
        return;
    }
    for (auto& element: heap){
        cout << "(" << element.first << ", " << element.second << ")\n";
    }
}

bool PriorityQueue::isAllocatedHeapEmpty() const{
    return heap.empty();
}

void PriorityQueue::clearAllocatedHeap(){
    heap.clear();
}