#include "MyStack.h"

MyStack::MyStack() {
    this->top = -1;
}

// add element to the top of the stack
void MyStack::push(int element) {
    this->top++;
    insertElement(element, this->top);
}

// remove element from the top of the stack (last element added)
int MyStack::pop() {
    int val = getElement(this->top);
    this->top--;
    return val;
}

// check if the stack is empty
bool MyStack::isEmpty() const {
    return this->top==-1;
}

MyStack::~MyStack() = default;