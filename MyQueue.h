#ifndef MYQUEUE_H
#define MYQUEUE_H


class MyQueue {
public:
    explicit MyQueue(int size);

    // add element to the back of the queue
    void push(int element);

    // remove element from the front of the queue (first element added)
    int pop();

    // check if the queue is empty
    bool isEmpty() const;

    ~MyQueue();
private:
    int* queue;
    int front;
    int back;
};


#endif
