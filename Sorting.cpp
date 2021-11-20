#include "Sorting.h"
#include <iostream>

using namespace std;

template<class T>
Sorting(int max) {
    resetComps();
    maxItems = max;
}

template<class T>
void swap (T* vals[], int first, int second) {
    if (first != second) {
        T tempVal = vals[first];
        vals[first] = vals[second];
        vals[second] = tempVal;
    } //if
} //swap end

template <class T>
int minIndex(T vals[], int start, int end) {
    int min = start;
    for (int i = start + 1; i <= end; i++) {
        if (vals[i] < vals[min]) {
            min = i;
        } //if
        comps++;
    } //for
    return min;
} //minIndex

template <class T>
void selectionSort (T vals[], int length) {
    int end = length - 1;
    for (int i = 0; i < end; i++) {
        swap (vals, i, minIndex(vals, i, end));
    } //for
} //selectionSort

template <class T>
void mergeSort (T vals[] , int first, int last) {
    if (first < last) {
        int mid = (first + last)/2;
        mergeSort(vals, first, mid);
        mergeSort(vals, mid+1, last);
        merge(vals, first, mid, mid+1, last);
    } //if
} //mergeSort

template <class T>
void merge (T* vals[], int leftF, int leftL, int rightF, int rightL) {
    T temp[maxItems];
    int i = leftF;
    int saveFirst = leftFirst;
    while ((leftF <= leftL) && (rightF <= rightL)) {
        if (vals[leftF] < vals[rightFirst]) {
            temp[i] = vals[leftF];
            leftF++;
        } else {
            temp[i] = vals[rightF];
            rightF++;
        } //if/else
        i++;
        comps++; //one comparison
    } //while

    while (leftF <= leftL) {
        temp[i] = vals[leftF];
        leftF++;
        i++;
    } //while
    while (rightFirst <= rightLast) {
        temp[i] = vals[rightF];
        rightF++;
        i++;
    } //while
    for (i = saveFirst; i <= rightL; i++) {
        vals[i] = temp[i];
    }
} //merge

template <class T>
void heapSort (T* vals[], int length) {
    int i;
    for (i = (length/2) - 1; i >= 0; i--) {
        reheapDown (vals, i, length - 1);
    } //for
    for (i = length - 1; i >= 1; i--) {
        swap (vals[0], vals[i]);
        reheapDown (vals, 0, i - 1);
    } //for
} //heapSort

void reheapDown (T* vals[], int root, int bottom) {
    int maxChild;
    int rightChild;
    int leftChild;
    leftChild = root*2 + 1;
    rightChild = root*2 + 2;
    if (leftChild <= bottom) {
        if (leftChild == bottom) {
            maxChild = leftChild;
        } else {
            if (vals[leftChild] <= vals[rightChild]) {
                maxChild = rigthChild;
            } else {
                maxChild = leftChild;
            } //if/else
            comps++;
        } //if/else
        if (vals[root] < vals[maxChild]) {
            swap(vals[root], vals[maxChild]);
            reheapDown(maxChild, bottom);
        } //if
        comps++;
    } //if
} //reheapDown

template <class T>
int getComps () {
    return comps;
}

template <class T>
void resetComps () {
    comps = 0;
}
