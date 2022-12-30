/*
 * Filename:  Sorted.cpp
 * Checks if an array of int is sorted in non-decreasing order.
 */

#include <iostream>

using namespace std;

/* Function prototype */
bool isSorted(int values[], int size);

int main() {

	// test arrays
	int values1[] = {0};
	int values2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int values3[] = {0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5};
	int values4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int values5[] = {9, 9, 9, 9, 9, 9, 9, 9, 1};
	int values6[] = {1, 3, 4, 4, 7, 6, 8, 9};

	// testing
	cout << "Array 1 is " << (isSorted(values1, (sizeof values1 / sizeof values1[0])) ? "" : "not ") << "sorted in non-decreasing order." << endl;
	cout << "Array 2 is " << (isSorted(values2, (sizeof values2 / sizeof values2[0])) ? "" : "not ") << "sorted in non-decreasing order." << endl;
	cout << "Array 3 is " << (isSorted(values3, (sizeof values3 / sizeof values3[0])) ? "" : "not ") << "sorted in non-decreasing order." << endl;
	cout << "Array 4 is " << (isSorted(values4, (sizeof values4 / sizeof values4[0])) ? "" : "not ") << "sorted in non-decreasing order." << endl;
	cout << "Array 5 is " << (isSorted(values5, (sizeof values5 / sizeof values5[0])) ? "" : "not ") << "sorted in non-decreasing order." << endl;
	cout << "Array 6 is " << (isSorted(values6, (sizeof values6 / sizeof values6[0])) ? "" : "not ") << "sorted in non-decreasing order." << endl;

	return 0;
}

/* Checks if an array of given size is sorted in non-decreasing order */
