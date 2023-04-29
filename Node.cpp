#include "Node.h"

using namespace std;

int Node :: getData(){
    return data;
}

void Node :: setData(int inputData){
    data = inputData;
}

Node* Node :: getLink(){
    return link;
}

void Node :: setLink(Node* inputLink){
    link = inputLink;
}