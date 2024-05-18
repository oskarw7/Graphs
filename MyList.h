#ifndef MYLIST_H
#define MYLIST_H

#include "iostream"

#include "Node.h"

class MyList {
public:
    MyList();

    void addNode(int value);

    int deleteNode();

    int getSize() const;

    Node* getTopElement() const;

    ~MyList();

private:
    Node* head;
};


#endif
