#include "MyVector.h"

MyVector::MyVector(){
    this->size = 0;
    this->capacity = 1;
    this->vector = new int[this->capacity];
}

// set capacity of the vector
void MyVector::initCapacity(int n){
    if(n<=this->capacity)
        return;
    this->capacity = n;
    delete[] this->vector;
    this->vector = new int[this->capacity];
}

// add element to the end of the vector
void MyVector::addElement(int element){
    if(this->size == this->capacity)
        reallocate();
    this->vector[this->size] = element;
    this->size++;
}

// insert element at index
void MyVector::insertElement(int element, int index){
    if(this->size == this->capacity)
        reallocate();
    this->vector[index] = element;
    this->size++;
}

// get element at index
int MyVector::getElement(int index) const {
    return this->vector[index];
}

// get size of the vector
int MyVector::getSize() const {
    return this->size;
}

MyVector::~MyVector(){
    delete[] this->vector;
}

// reallocate memory of the vector
void MyVector::reallocate() {
    this->capacity *= 2;
    int* newVector = new int[this->capacity];
    for(int i=0; i<this->size; i++)
        newVector[i] = this->vector[i];
    delete[] this->vector;
    this->vector = newVector;
}