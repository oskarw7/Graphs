#include "MyQueue.h"

MyQueue::MyQueue(int size) {
    this->queue = new int[size];
    this->front = 0;
    this->back = 0;
}

// add element to the back of the queue
void MyQueue::push(int element) {
    this->queue[this->back++] = element;
}

// remove element from the front of the queue (first element added)
int MyQueue::pop() {
    return this->queue[this->front++];
}

// check if the queue is empty
bool MyQueue::isEmpty() const {
    return this->front == this->back;
}

MyQueue::~MyQueue() {
    delete[] this->queue;
}