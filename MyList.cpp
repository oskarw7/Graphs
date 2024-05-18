#include "MyList.h"

MyList::MyList(){
    this->head = nullptr;
}

void MyList::addNode(int value){
    Node* newNode = new Node(value);
    newNode->next = this->head;
    this->head = newNode;
}

int MyList::deleteNode(){
    Node* temp = this->head;
    int value = temp->getValue();
    this->head = this->head->next;
    delete temp;
    return value;
}

int MyList::getSize() const {
    int size = 0;
    Node* temp = this->head;
    while(temp != nullptr){
        size++;
        temp = temp->next;
    }
    return size;
}

Node* MyList::getTopElement() const {
    return this->head;
}

MyList::~MyList(){
    while(this->head != nullptr)
        deleteNode();
}