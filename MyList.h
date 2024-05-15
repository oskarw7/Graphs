#ifndef MYLIST_H
#define MYLIST_H

#include "iostream"

#include "Node.h"

class MyList {
public:
    MyList();

    void addNode(int value);

    void deleteNode();

    int getSize() const;

    void printList();

    ~MyList();

    friend class Graph;

private:
    Node* head;
};


#endif
