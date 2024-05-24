#include "MyStack.h"

MyStack::MyStack() {
    this->top = -1;
}

void MyStack::push(int element) {
    this->top++;
    insertElement(element, this->top);
}

int MyStack::pop() {
    int val = getElement(this->top);
    this->top--;
    return val;
}

bool MyStack::isEmpty() const {
    return this->top==-1;
}

MyStack::~MyStack() = default;