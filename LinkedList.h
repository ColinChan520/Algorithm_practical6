#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList();
    LinkedList(int* array, int len);
    // ~LinkedList();
    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos);
    int search(int target);
    void printList();
};

#endif