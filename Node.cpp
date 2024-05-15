#include "Node.h"

Node::Node(int value){
    this->value = value;
    this->next = nullptr;
}

int Node::getValue() const{
    return this->value;
}