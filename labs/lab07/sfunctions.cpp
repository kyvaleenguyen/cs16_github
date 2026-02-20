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

}

int find_index_of_swap(bool desc, int a[], int start_index, int number_used) {
    int swapped_index = 0;
    return swapped_index;
}

void sort(bool desc, int a[], int number_used, int index) {

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

    // Populate array
    //  This gets the original array from the file
    int next;
    arr[size] = {};
    while (in >> next) {
        for (int i = 0; i < size; i++) {
            arr[i] = next;
        }
    }
}