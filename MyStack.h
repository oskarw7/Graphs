#ifndef STACK_H
#define STACK_H

#include "MyVector.h"

class MyStack {
public:
    MyStack();

    void addNode(int element);

    int deleteNode();

    int getTopIndex() const;

    int getSize() const;

    ~MyStack();

private:
    MyVector stack;
    int top;

};


#endif
