#ifndef UTILS_H
#define UTILS_H

// compare left and right array, merge them into arr
void compare(int* arr, const int* leftArray, const int* rightArray, int low, int leftSize, int rightSize);

// compare left and right array using comparator array, merge them into arr
void stableCompare(const int* comparator, int* arr, const int* leftArray, const int* rightArray, int low, int leftSize, int rightSize);

// merge left and right array into arr
void merge(const int* comparator, int* arr, int low, int middle, int leftSize, int rightSize);

// sort arr using comparator array, divide into two parts
void mergeSort(const int* comparator, int* arr, int low, int high);


#endif