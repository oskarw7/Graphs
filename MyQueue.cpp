#include "MyQueue.h"

MyQueue::MyQueue(int size) {
    this->queue = new int[size];
    this->front = 0;
    this->back = 0;
}

void MyQueue::push(int element) {
    this->queue[this->back++] = element;
}

int MyQueue::pop() {
    return this->queue[this->front++];
}

bool MyQueue::isEmpty() const {
    return this->front == this->back;
}

MyQueue::~MyQueue() {
    delete[] this->queue;
}