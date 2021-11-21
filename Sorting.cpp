#include "Sorting.h"
#include <iostream>

using namespace std;

Sorting::Sorting(int max) {
    resetComps();
    maxItems = max;
}

void Sorting::swap (int* vals[], int first, int second) {
    if (first != second) {
        T tempVal = vals[first];
        vals[first] = vals[second];
        vals[second] = tempVal;
    } //if
} //swap end

int Sorting::minIndex(int* vals[], int start, int end) {
    int min = start;
    for (int i = start + 1; i <= end; i++) {
        if (vals[i] < vals[min]) {
            min = i;
        } //if
        comps++;
    } //for
    return min;
} //minIndex

void Sorting::selectionSort (int* vals[], int length) {
    int end = length - 1;
    for (int i = 0; i < end; i++) {
        swap (vals, i, minIndex(vals, i, end));
    } //for
} //selectionSort

void Sorting::mergeSort (int* vals[] , int first, int last) {
    if (first < last) {
        int mid = (first + last)/2;
        mergeSort(vals, first, mid);
        mergeSort(vals, mid+1, last);
        merge(vals, first, mid, mid+1, last);
    } //if
} //mergeSort

void Sorting::merge (int* vals[], int leftF, int leftL, int rightF, int rightL) {
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

void Sorting::heapSort (int* vals[], int length) {
    int i;
    for (i = (length/2) - 1; i >= 0; i--) {
        reheapDown (vals, i, length - 1);
    } //for
    for (i = length - 1; i >= 1; i--) {
        swap (vals[0], vals[i]);
        reheapDown (vals, 0, i - 1);
    } //for
} //heapSort

void Sorting::reheapDown (int* vals[], int root, int bottom) {
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

int Sorting::splitArrayF(int* vals[], int start, int end) {
    int pivot = vals[start];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (vals[j] <= pivot) {
            i++;
            swap(vals, i, j);
        } //if
        comps++;
    } //for
    swap(vals[i+1], vals[end]);
    return i + 1;
} //splitArrayF

void Sorting::quickSortF(int* vals[], int start, int end) {
    if (start < end) {
        int partition = splitArrayF(vals, start, end);
        quickSortF(vals, start, partition-1);
        quickSortF(vals, partition+1, end);

    } //if
} //quickSortF

int Sorting::splitArrayR(int* vals[], int start, int end) {
    int pivInd = start + (rand() % (end - start + 1));
    int pivot = vals[pivInd];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (vals[j] <= pivot) {
            i++;
            swap(vals, i, j);
        } //if
        comps++;
    } //for
    swap(vals[i+1], vals[end]);
    return i + 1;
} //splitArrayF

void Sorting::quickSortR(int* vals[], int start, int end) {
    if (start < end) {
        int partition = splitArrayR(vals, start, end);
        quickSortR(vals, start, partition-1);
        quickSortR(vals, partition+1, end);

    } //if
} //quickSortF

int Sorting::getComps () {
    return comps;
}

void Sorting::resetComps () {
    comps = 0;
}
