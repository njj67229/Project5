#include "Sorting.h"
#include <iostream>
#include <string>

using namespace std;

Sorting::Sorting() {
    resetComps();
}

void Sorting::swap (int* first, int* second) {
    int tempVal = *first;
    *first = *second;
    *second = tempVal;
} //swap end

int Sorting::minIndex(int vals[], int start, int end) {
    int min = start;
    for (int i = start + 1; i <= end; i++) {
        if (vals[i] < vals[min]) {
            min = i;
        } //if
        comps++;
    } //for
    return min;
} //minIndex

void Sorting::selectionSort (int vals[], int length) {
    int end = length - 1;
    for (int i = 0; i < end; i++) {
        swap (&vals[i], &vals[minIndex(vals, i, end)]);
    } //for
} //selectionSort

void Sorting::mergeSort (int vals[] , int first, int last) {
    if (first < last) {
        int mid = (first + last)/2;
        mergeSort(vals, first, mid);
        mergeSort(vals, mid+1, last);
        merge(vals, first, mid, mid+1, last);
    } //if
} //mergeSort

void Sorting::merge (int vals[], int leftF, int leftL, int rightF, int rightL) {
    int temp[maxItems];
    int i = leftF;
    int saveFirst = leftF;
    while ((leftF <= leftL) && (rightF <= rightL)) {
        if (vals[leftF] < vals[rightF]) {
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
    while (rightF <= rightL) {
        temp[i] = vals[rightF];
        rightF++;
        i++;
    } //while
    for (i = saveFirst; i <= rightL; i++) {
        vals[i] = temp[i];
    }
} //merge

void Sorting::heapSort (int vals[], int length) {
    int i;
    for (i = (length/2) - 1; i >= 0; i--) {
        reheapDown (vals, i, length - 1);
    } //for
    for (i = length - 1; i >= 1; i--) {
        swap (&vals[0], &vals[i]);
        reheapDown (vals, 0, i - 1);
    } //for
} //heapSort

void Sorting::reheapDown (int vals[], int root, int bottom) {
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
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            } //if/else
            comps++;
        } //if/else
        if (vals[root] < vals[maxChild]) {
            swap(&vals[root], &vals[maxChild]);
            reheapDown(vals, maxChild, bottom);
        } //if
        comps++;
    } //if
} //reheapDown

int Sorting::splitArrayF(int vals[], int start, int end) {
    int pivot = vals[start];
    int i = (start+1);
    for (int j = start+1; j <= end; j++) {
        if (vals[j] <= pivot) {
            if (i != j) {
                swap(&vals[i], &vals[j]);
            }
            i++;
        } //if
        comps++;
    } //for
    swap(&vals[start], &vals[i-1]);
    return (i-1);
} //splitArrayF


int Sorting::splitArrayEnd(int vals[], int start, int end) {
    int pivot = vals[end];
    int i = (start-1);
    for (int j = start; j <= end-1; j++) {
        if (vals[j] <= pivot) {
            i++;
            swap(&vals[i], &vals[j]);
        } //if
        comps++;
    } //for
    swap(&vals[i+1], &vals[end]);
    return (i+1);
} //splitArrayEnd

void Sorting::quickSortF(int vals[], int start, int end) {
    if (start < end) {
        int partition = splitArrayF(vals, start, end);
        quickSortF(vals, start, partition-1);
        quickSortF(vals, partition+1, end);
    } //if
} //quickSortF

int Sorting::splitArrayR(int vals[], int start, int end) {
    srand(time(NULL));
    int pivInd = start + (rand() % (end - start));
    swap(&vals[pivInd], &vals[end]);
    return splitArrayEnd(vals, start, end);
} //splitArrayF

void Sorting::quickSortR(int vals[], int start, int end) {
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

void Sorting::setMax(int max) {
    maxItems = max;
}

void Sorting::print(string algo, int vals[], int length) { // written by Taylor
    for (int i = 0; i < length; i++) {
        cout << vals[i] << " ";
    } // for
    cout << endl << "\t#" << algo << " comparisons: " << comps << endl;
} // end print
