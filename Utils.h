#ifndef UTILS_H
#define UTILS_H

void compare(int* arr, const int* leftArray, const int* rightArray, int low, int leftSize, int rightSize);

void stableCompare(const int* comparator, int* arr, const int* leftArray, const int* rightArray, int low, int leftSize, int rightSize);

void merge(const int* comparator, int* arr, int low, int middle, int leftSize, int rightSize);

void mergeSort(const int* comparator, int* arr, int low, int high);


#endif
