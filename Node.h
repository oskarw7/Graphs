#ifndef NODE_H
#define NODE_H


class Node {
public:
    explicit Node(int value);

    int getValue() const;

    int getPrevious() const;

    void setPrevious(int vertex);

    friend class MyList;

private:
    int value;
    int parentValue;
    Node* next;
};


#endif
