#include "MyVector.h"

MyVector::MyVector(){
    this->size = 0;
    this->capacity = 1;
    this->vector = new int[this->capacity];
}

void MyVector::initCapacity(int n){
    this->capacity = n;
    delete[] this->vector;
    this->vector = new int[this->capacity];
}

void MyVector::addElement(int element){
    if(this->size == this->capacity)
        reallocate();
    this->vector[this->size] = element;
    this->size++;
}

void MyVector::insertElement(int element, int index){
    if(this->size == this->capacity)
        reallocate();
    this->vector[index] = element;
    this->size++;
}

int MyVector::getElement(int index) const {
    return this->vector[index];
}

int MyVector::getSize() const {
    return this->size;
}

MyVector::~MyVector(){
    delete[] this->vector;
}

void MyVector::reallocate() {
    this->capacity *= 2;
    int* newVector = new int[this->capacity];
    for(int i=0; i<this->size; i++)
        newVector[i] = this->vector[i];
    delete[] this->vector;
    this->vector = newVector;
}