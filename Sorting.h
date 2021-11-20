#ifndef SORTING_H
#define SORTING_H
#include <string>

template<class T> class Sorting {
public:
    Sorting();
    void swap (T* vals[], int first, int second);
    int minIndex(T* vals[], int start, int end);
    void selectionSort (T* vals[], int length);
    void mergeSort (T* vals[] , int first, int last);
    void merge (T* vals[], int leftF, int leftL, int rightF, int rightL);
    void heapSort (T* vals[], int length);
    void reheapDown (T* vals[], int root, int bottom);
    int getComps();
    void resetComps();
private:
    int comps;
    int maxItems;
};

template class Sorting<int>;

#endif
