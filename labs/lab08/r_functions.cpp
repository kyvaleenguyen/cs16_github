// file: r_functions.cpp
// YOUR NAME HERE
// Kyvalee Khloy Nguyen

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

#include "r_structs.h"

using namespace std;

// Define the functions, per the list in r_headers.
void bubbleSort(string *array, int size);


// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
void bubbleSort(string *array, int size) {
  bool swapped = true;
  int j = 0;
  string temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < size - j; i++) {
        if (tolower(array[i][0]) > tolower(array[i + 1][0])) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            swapped = true;
        }
    }
  }
}

void NameSort(UndergradStudents array[], int size) {

}

void InitializeStructures(UndergradStudents us[], int &size) {

}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {

}