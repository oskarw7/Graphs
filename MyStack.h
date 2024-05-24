#ifndef MYSTACK_H
#define MYSTACK_H

#include "MyVector.h"

class MyStack : public MyVector {
public:
    MyStack();

    void push(int element);

    int pop();

    bool isEmpty() const;

    ~MyStack();
private:
    int top;

};


#endif