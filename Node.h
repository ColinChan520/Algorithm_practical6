#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
    private:
    int data;
    Node *link;

    public:
    int getData();
    void setData(int inputData);
    Node* getLink();
    void setLink(Node* inputLink);
};

#endif
