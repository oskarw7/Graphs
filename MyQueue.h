#ifndef MYQUEUE_H
#define MYQUEUE_H


class MyQueue {
public:
    explicit MyQueue(int size);

    void push(int element);

    int pop();

    bool isEmpty() const;

    ~MyQueue();
private:
    int* queue;
    int front;
    int back;
};


#endif
