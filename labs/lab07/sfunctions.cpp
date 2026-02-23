// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// DEFINE ALL 5 FUNCTIONS PER THE sheaders.h FILE HERE
// Add Pre- and Post-Condition comments
void swap_values(int& v1, int& v2) {
    int temp = 0;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

// Pre-condition: the bool desc value determines whether the index of the smallest or largest number will be returned. It searches through an already defined array
//      For the first run of finding the index of swap, it iterates through the entire array starting at 0 and ends once it reaches the end of the array
// Post-condition: The smallest or largest value found in the entire array is returned depending on if the user wants the array to be sorted in ascending or descending
//      order. 
//      Note: the indexing and shrinking of array for the entire array to be sorted will be done later on in the sort function (which will call this function)
int find_index_of_swap(bool desc, int a[], int start_index, int number_used) {
    // Search through array for smallest or largest value by using the first value in the array as a reference to check if the next value is smaller or larger
    int target_index = start_index;

    for (int i = start_index + 1; i < number_used; i++) {
        // If desc is true -> find index of largest number to sort in descending later on in sort
        if (desc) {
            if (a[i] > a[target_index]) {
                target_index = i;
            }
        // Find smallest index to sort in ascending order later on in sort function
        } else {
            if (a[i] < a[target_index]) {
                target_index = i;
            }
        }
    }
    return target_index;
}

// Pre-condition: MUST call swap & find_index_of_swap inside this function. MUST be a recursive function
// Post-condition: 
void sort(bool desc, int a[], int number_used, int index) {
    // Base case: nothing left to sort
    if (index >= number_used - 1) {
        return;
    }

    // Find the index of the smallest or largest number in the remaining unsorted array
    int swapIndex = find_index_of_swap(desc, a, index, number_used);

    // If the element at the current index isn't the min/max, swap them
    if (swapIndex != index) {
        swap_values(a[index], a[swapIndex]);
    }

    // Recursive call -> sort the rest of the array starting from the next index
    sort(desc, a, number_used, index + 1);
}

int getFileSize(ifstream& inf, string fname) {
    // Open ifstream & open file
    inf.open(fname);
    // If file cant be opened print error & exit program
    if (!inf.is_open()) {
        cerr << "Cannot open" << fname;
        exit(1);
    }
    // Iterate through ints within file
    int next;
    int count = 0;
    // As long as the ifstream is able to read through integers in the file, add to the count to get the amount of integers in the file
    while (inf >> next) {
        count++;
    }
    // Close input file once done reading
    fname.close();

    // Return number of values read from the input value (int values)
    return count;
}

void getArray(ifstream& in, string fname, int arr[], int size) {
    // Open ifstream & open file
    in.open(fname);
    // If opening fails, print error message & exit program
    if (!in.is_open()) {
        cerr << "Cannot open " << fname;
        exit(1);
    }

    // Create dynamic array to be populated
    //  This gets the original array from the file
    int next;

    // Create dynamic array using new()
    int* newArray = new int[size];
    while (in >> next) {
        for (int i = 0; i < size; i++) {
            arr[i] = next;
        }
    }
}