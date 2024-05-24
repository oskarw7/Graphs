#ifndef MYVECTOR_H
#define MYVECTOR_H


class MyVector {
public:
    MyVector();

    // set capacity of the vector
    void initCapacity(int n);

    // add element to the end of the vector
    void addElement(int element);

    // insert element at index
    void insertElement(int element, int index);

    // get element at index
    int getElement(int index) const;

    // get size of the vector
    int getSize() const;

    ~MyVector();

private:
    // reallocate memory of the vector
    void reallocate();

    int* vector;
    int size;
    int capacity;
};


#endif