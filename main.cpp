#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include "Sorting.h"
using namespace std;

// Intro that gives commands
void intro() {
	cout << "selection-sort (s)    merge-sort (m)    heap-sort (h)    quick-sort-fp" << endl;
	cout << "(q)    quick-sort-rp (r)" << endl;
} // end intro

// Function for generating a random list and comparing the algorithm
void comparison(Sorting s) {
	int sizeOfInput = 0;
	char algo = 0;
	cout << "Now beginning algorithm comparison counting. Enter the algorithm: ";
	cin >> algo;
	cout << "Enter size of input: ";
	cin >> sizeOfInput;
	int arr[sizeOfInput];
	srand(time(0));
    s.setMax(sizeOfInput+10);
	for (int i = 0; i < sizeOfInput; i++) {
		arr[i] = rand() % (200001);
	} // for
	if (algo == 's') { // selection-sort
		s.selectionSort(arr, sizeOfInput);
        s.print("Selection-sort", arr, sizeOfInput);
	} else if (algo == 'm') { // merge-sort
		s.mergeSort(arr, 0, sizeOfInput-1);
        s.print("Merge-sort", arr, sizeOfInput);
	} else if (algo == 'h') { // heap-sort
		s.heapSort(arr, sizeOfInput);
        s.print("Heap-sort", arr, sizeOfInput);
	} else if (algo == 'q') { // quick-sort-fp
		s.quickSortF(arr, 0, sizeOfInput-1);
        s.print("Quick-sort-fp", arr, sizeOfInput);
	} else if (algo == 'r') { // quick-sort-rp
		s.quickSortR(arr, 0, sizeOfInput-1);
        s.print("Quick-sort-rp", arr, sizeOfInput);
	} // if/else

} // end comparison

// Handles selecting the algorithm the user wants
void commands(int numList[], int length, Sorting s) {
	char command = 0;
	cout << "Enter the algorithm: ";
	cin >> command;
	if (command == 's') { // selection-sort
		s.selectionSort(numList, length);
        s.print("Selection-sort", numList, length);
	} else if (command == 'm') { // merge-sort
		s.mergeSort(numList, 0, length-1);
        s.print("Merge-sort", numList, length);
	} else if (command == 'h') { // heap-sort
		s.heapSort(numList, length);
        s.print("Heap-sort", numList, length);
	} else if (command == 'q') { // quick-sort-fp
		s.quickSortF(numList, 0, length-1);
        s.print("Quick-sort-fp", numList, length-1);
	} else if (command == 'r') { // quick-sort-rp
		s.quickSortR(numList, 0, length-1);
        s.print("Quick-sort-rp", numList, length);
	} // if/else
} //end commands

// Function to make the list from the file
void makeList(string file) {
	ifstream libFile;
	libFile.open(file, ios::in);
	char n;
	string item;
	vector<int> v; // dynamically grows, will switch to an array once done adding
	// While loop to put items into list
	while(libFile.get(n)) {
		if (n != ' ' && n != '\n' && n != '\0') {
			item.push_back(n);
		} else {
			stringstream st;
			int nu;
			st << item;
			st >> nu;
			v.push_back(nu);
			item = "";
		} // if/else
	} // while
	if (item.length() != 0) {
		stringstream st;
		int nu;
		st << item;
		st >> nu;
		v.push_back(nu);
		item = "";
	} // if
	int numList[v.size()];
	copy(v.begin(), v.end(), numList);
    Sorting s;
    s.setMax(v.size() + 100);
	commands(numList, v.size(), s);
	libFile.close();
} // end makeList

// Program main (if -1, empty list)
int main(int argc, char **argv) {
	if (argc != 2 && argc != 1) { // error check for correct argument number
		cerr << "Usage: main [text_file] OR main" << endl;
		exit (1);
	} // if
	intro();
	if (argc == 2) {
		string file = argv[1];
		makeList(file); // makeList function, above
	} else if (argc == 1) {
         Sorting s;
         comparison(s);
	} // if/else
    return 0; // quit
} //end main
