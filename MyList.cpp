#include "MyList.h"

MyList::MyList(){
    this->head = nullptr;
}

void MyList::addNode(int value){
    Node* newNode = new Node(value);
    newNode->next = this->head;
    this->head = newNode;
}

void MyList::deleteNode(){
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
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

void MyList::printList(){
    std::cout << this->getSize() << " ";
    Node* temp = this->head;
    while(temp != nullptr){
        std::cout << temp->getValue() << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

MyList::~MyList(){
    while(this->head != nullptr)
        deleteNode();
}