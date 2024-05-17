#include "Utils.h"

void merge(int* copy, int left, int middle, int right){
    int leftSize = middle-left+1, rightSize = right-middle;
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for(int i=0; i<leftSize; i++)
        leftArray[i] = copy[left+i];
    for(int i=0; i<rightSize; i++)
        rightArray[i] = copy[middle+1+i];
    int i = 0, j = 0, k = left;
    while(i<leftSize && j<rightSize){
        if(leftArray[i] >= rightArray[j]){
            copy[k] = leftArray[i];
            i++;
        }
        else{
            copy[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while(i<leftSize){
        copy[k] = leftArray[i];
        i++;
        k++;
    }
    while(j<rightSize){
        copy[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] rightArray;
    delete[] leftArray;
}

void mergeSort(int* copy, int left, int right){
    if(left<right){
        int middle = left+(right-left)/2;
        mergeSort(copy, left, middle);
        mergeSort(copy, middle+1, right);
        merge(copy, left, middle, right);
    }
}