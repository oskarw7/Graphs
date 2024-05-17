#ifndef STACK_H
#define STACK_H

#include "MyVector.h"

class MyStack {
public:
    MyStack();

    void addNode(int element);

    int deleteNode();

    int getTopElement() const;

    int getSize() const;

    ~MyStack();

private:
    MyVector* stack;
    int top;

};


#endif
