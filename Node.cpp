#include "Node.h"

Node::Node(int value){
    this->value = value;
    this->next = nullptr;
    this->parentValue = 0;
}

int Node::getValue() const{
    return this->value;
}

int Node::getPrevious() const {
    return this->parentValue;
}

void Node::setPrevious(int vertex){
    this->parentValue = vertex;
}