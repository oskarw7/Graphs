#include "MyStack.h"

MyStack::MyStack() {
    this->top = -1;
}

void MyStack::addNode(int element) {
    this->top++;
    this->stack.insertElement(element, this->top);
}

int MyStack::deleteNode() {
    int val = this->stack.getElement(this->top);
    this->top--;
    return val;
}

int MyStack::getTopIndex() const {
    return this->top;
}

int MyStack::getSize() const {
    return this->stack.getSize();
}

MyStack::~MyStack() {

}