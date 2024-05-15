#ifndef NODE_H
#define NODE_H


class Node {
public:
    Node(int value);

    int getValue() const;

    friend class MyList;

private:
    int value;
    Node* next;

};


#endif
