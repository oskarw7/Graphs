#include "Utils.h"

void merge(int* arr, int left, int middle, int leftSize, int rightSize){
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for(int i=0; i<leftSize; i++)
        leftArray[i] = arr[left+i];
    for(int i=0; i<rightSize; i++)
        rightArray[i] = arr[middle+1+i];

    int i = 0, j = 0, k = left;
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

    delete[] rightArray;
    delete[] leftArray;
}

void mergeSort(int* arr, int low, int high){
    if(low>=high)
        return;
    else {
        int middle = (low+high)/2;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle+1, high);
        merge(arr, low, middle, middle-low+1, high-middle);
    }
}

void twoArraysMerge(int* comparator, int* arr, int low, int middle, int leftSize, int rightSize){
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for(int i=0; i<leftSize; i++)
        leftArray[i] = arr[low+i];
    for(int i=0; i<rightSize; i++)
        rightArray[i] = arr[middle+1+i];

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

    delete[] rightArray;
    delete[] leftArray;
}

void twoArraysMergeSort(int* comparator, int* arr, int low, int high){
    if(low>=high)
        return;
    else {
        int middle = (low+high)/2;
        twoArraysMergeSort(comparator, arr, low, middle);
        twoArraysMergeSort(comparator, arr, middle+1, high);
        twoArraysMerge(comparator, arr, low, middle, middle-low+1, high-middle);
    }
}