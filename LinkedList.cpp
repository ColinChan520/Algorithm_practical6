#include "LinkedList.h"
#include <limits> 

using namespace std;

LinkedList :: LinkedList(){
    head = nullptr;
}

LinkedList :: LinkedList(int* array, int len){
    for(int i = 0; i < len; i++){
        Node *n = new Node;
        n->setData(array[i]);
        n->setLink(nullptr);

        if(head == nullptr){
            head = n;
        }
        else{
            Node* s = head;
            while(s->getLink() != nullptr){
                s = s->getLink();
            }
            s->setLink(n);
        }
    }
}

// LinkedList :: ~LinkedList(){
//     head = nullptr;
// }

void LinkedList :: insertPosition(int pos, int newNum){
    Node* num = new Node;
    num->setData(newNum);
    num->setLink(nullptr);

    // <1
    if(pos <= 1){
        num->setLink(head);
        head = num;
    }

    // >1
    int currentPosition = 1;
    Node* currentNode = new Node;
    currentNode = head;
    while(currentPosition < pos -1){
        Node* nextNode = currentNode->getLink();
        if(nextNode == nullptr){
            currentNode->setLink(num);
            return;
        }
        else{
            currentNode = nextNode;
            currentPosition++;
        }
    }
    Node* old;
    old = currentNode->getLink();

    currentNode->setLink(num);
    num->setLink(old);
    printList();
}

bool LinkedList :: deletePosition(int pos){
    int currentPosition = 1;
    Node* currentNode = new Node;
    currentNode = head;
    while(currentPosition < pos -1){
        Node* nextNode = currentNode->getLink();
        if(nextNode == nullptr){
            return false;
        }
        currentNode = nextNode;
        currentPosition++;
    }
    Node* nextNextNode = currentNode->getLink()->getLink();
    currentNode->setLink(nextNextNode);
    return true;
}

int LinkedList :: get(int pos){
    int currentPosition = 1;
    Node* currentNode = new Node;
    currentNode = head;
    while(currentPosition < pos ){
        Node* nextNode = currentNode->getLink();
        if(nextNode == nullptr){
            return numeric_limits < int >::max();
        }
        currentNode = nextNode;
        currentPosition++;
    }
    return currentNode->getData();
}

int LinkedList :: search(int target){
    int currentPosition = 1;
    Node* currentNode = new Node;
    currentNode = head;
    while(currentNode != nullptr){
        if(currentNode->getData() == target){
            return currentPosition;
        }
        currentNode = currentNode->getLink();
        currentPosition++;
    }
    return -1;
}

void LinkedList :: printList(){
    int currentPosition = 1;
    Node* currentNode = new Node;
    currentNode = head;
    cout << "[";
    while(currentNode != nullptr){
    cout << currentNode->getData();
    currentNode = currentNode->getLink();
    if(currentNode != nullptr){
        cout << " ";
    }
    currentPosition++;
    }
    cout << "]" << endl;
}

