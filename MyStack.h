#ifndef MYSTACK_H
#define MYSTACK_H

#include "MyVector.h"

class MyStack : public MyVector {
public:
    MyStack();

    // add element to the top of the stack
    void push(int element);

    // remove element from the top of the stack (last element added)
    int pop();

    // check if the stack is empty
    bool isEmpty() const;

    ~MyStack();
private:
    int top;

};


#endif