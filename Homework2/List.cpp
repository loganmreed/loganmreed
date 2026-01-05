//
//  List.cpp
//  DoublyLinkedList
//
//  Created by Madhuri Debnath on 9/24/20.
//

#include<iostream>
#include "List.h"
using namespace std;

void List::insert(int value){
    Node* newItem = new Node(value);
    if (headPtr->getNextPtr() == nullptr){
        headPtr->setNextPtr(newItem);
        newItem->setPrevPtr(headPtr);
        tailPtr = newItem;
    } else {
        tailPtr->setNextPtr(newItem);
        newItem->setPrevPtr(tailPtr);
        tailPtr = newItem;
    }
}

void List::insertAtIndex(int data, int index){
    Node* newItem = new Node(data);
    if (index < 0){
        index = 0;
    }
    
    Node* temp = headPtr;
    Node* prev = nullptr;
    int i = 0;

    while(temp && i < index) {
        prev = temp;
        temp = temp->getNextPtr();
        i++;
    }
    newItem->setPrevPtr(prev);
    newItem->setNextPtr(temp);
    if(prev){
        prev->setNextPtr(newItem);
    } else{
        headPtr = newItem;
    }
    if(temp) {
        prev->setPrevPtr(newItem);
    } else{
        tailPtr = newItem;
    }
}
void List::deleteAtIndex(int index) 
{
    if (!headPtr) return; // empty

    Node* temp = headPtr;
    int i = 0;
    while (temp && i < index) {
        temp = temp->getNextPtr();
        i++;
    }
    if (!temp) return; // index out of range

    if (temp->getPrevPtr())
        temp->getPrevPtr()->setNextPtr(temp->getNextPtr());
    else
        headPtr = temp->getNextPtr(); // deleting head

    if (temp->getNextPtr()){
        temp->getNextPtr()->setPrevPtr(temp->getPrevPtr());
    }else{
        tailPtr = temp->getPrevPtr(); // deleting tail
    }
    delete temp;
}

void List::readItem(int index)
{
    Node* temp = headPtr;
    int i = 0;
    while (temp && i < index) {
        temp = temp->getNextPtr();
        i++;
    }
    if (temp)
        cout << "Item at index " << index << ": " << temp->getData() << endl;
    else
        cout << "Index out of range." << endl;
}

void List::reverseList()
{
    Node* current = headPtr;
    Node* temp = nullptr;
    
    while (current) {
        temp = current->getPrevPtr();
        current->setPrevPtr(current->getNextPtr());
        current->setNextPtr(temp);
        current = current->getPrevPtr();
    }
    if (temp) {
        tailPtr = headPtr;
        headPtr = temp->getPrevPtr();
    }
}

void List::printForward(){
    Node* temp = headPtr;
    if (temp == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }
    //temp = temp->getNextPtr();
    while (temp) {
        cout << temp->getData() << " ";
        temp = temp->getNextPtr();
    }
    std::cout << std::endl;
    
}
void List::printBackward(){
    Node* temp = tailPtr;

    if (temp == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }
    
    while (temp != nullptr) {
        cout << temp->getData() << " ";
        temp = temp->getPrevPtr();
    }
    std::cout << endl;
}

