#ifndef MYVECTOR_H
#define MYVECTOR_H


class MyVector {
public:
    MyVector();

    void addElement(int element);

    int getElement(int index) const;

    int getSize() const;

    ~MyVector();

private:
    int* vector;
    int size;
    int capacity;
};


#endif