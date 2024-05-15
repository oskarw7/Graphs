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

    int getNodeValue(int index) const;

    Node* getTopElement() const;

    void printList();

    ~MyList();

    friend class Graph;

private:
    Node* head;
};


#endif
