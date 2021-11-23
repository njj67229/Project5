#ifndef SORTING_H
#define SORTING_H
#include <string>

class Sorting {
public:
    Sorting();
    void swap (int* first, int* second);
    int minIndex(int vals[], int start, int end);
    void selectionSort (int vals[], int length);
    void mergeSort (int vals[] , int first, int last);
    void merge (int vals[], int leftF, int leftL, int rightF, int rightL);
    void heapSort (int vals[], int length);
    void reheapDown (int vals[], int root, int bottom);
    int splitArrayF(int vals[], int start, int end);
    void quickSortF(int vals[], int start, int end);
    int splitArrayR(int vals[], int start, int end);
    int splitArrayEnd(int vals[], int start, int end);
    void quickSortR(int vals[], int start, int end);
    int getComps();
    void resetComps();
    void print(std::string algo, int vals[], int length);
    void setMax(int max);
private:
    int comps;
    int maxItems;
};


#endif
