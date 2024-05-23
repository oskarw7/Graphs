#include "Utils.h"

void compare(int* arr, const int* leftArray, const int* rightArray, int low, int leftSize, int rightSize){
    int i = 0, j = 0, k = low;

    while(i<leftSize && j<rightSize){
        if(leftArray[i] >= rightArray[j])
            arr[k] = leftArray[i++];
        else
            arr[k] = rightArray[j++];
        k++;
    }

    while(i<leftSize)
        arr[k++] = leftArray[i++];
    while(j<rightSize)
        arr[k++] = rightArray[j++];
}

void stableCompare(const int* comparator, int* arr, const int* leftArray, const int* rightArray, int low, int leftSize, int rightSize){
    int i = 0, j = 0, k = low;

    while(i<leftSize && j<rightSize){
        if(comparator[leftArray[i]] > comparator[rightArray[j]] || (comparator[leftArray[i]] == comparator[rightArray[j]] && leftArray[i] < rightArray[j]))
            arr[k] = leftArray[i++];
        else
            arr[k] = rightArray[j++];
        k++;
    }

    while(i<leftSize)
        arr[k++] = leftArray[i++];
    while(j<rightSize)
        arr[k++] = rightArray[j++];
}

void merge(const int* comparator, int* arr, int low, int middle, int leftSize, int rightSize){
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for(int i=0; i<leftSize; i++)
        leftArray[i] = arr[low+i];
    for(int i=0; i<rightSize; i++)
        rightArray[i] = arr[middle+1+i];

    if(comparator==nullptr)
        compare(arr, leftArray, rightArray, low, leftSize, rightSize);
    else
        stableCompare(comparator, arr, leftArray, rightArray, low, leftSize, rightSize);

    delete[] rightArray;
    delete[] leftArray;
}

void mergeSort(const int* comparator, int* arr, int low, int high){
    if(low>=high)
        return;
    else {
        int middle = (low+high)/2;
        mergeSort(comparator, arr, low, middle);
        mergeSort(comparator, arr, middle + 1, high);
        merge(comparator, arr, low, middle, middle - low + 1, high - middle);
    }
}