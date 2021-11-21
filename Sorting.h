#ifndef SORTING_H
#define SORTING_H

template<class T> class Sorting {
public:
    Sorting();
    void swap (int* vals[], int first, int second);
    int minIndex(int* vals[], int start, int end);
    void selectionSort (int* vals[], int length);
    void mergeSort (int* vals[] , int first, int last);
    void merge (int* vals[], int leftF, int leftL, int rightF, int rightL);
    void heapSort (int* vals[], int length);
    void reheapDown (int* vals[], int root, int bottom);
    int splitArrayF(int* vals[], int start, int end, int pivotInd);
    void quickSortF(int* vals[], int start, int end);
    int splitArrayR(int* vals[], int start, int end, int pivotInd);
    void quickSortR(int* vals[], int start, int end);
    int getComps();
    void resetComps();
private:
    int comps;
    int maxItems;
};

template class Sorting<int>;

#endif
