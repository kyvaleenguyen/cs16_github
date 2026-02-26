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
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      if (array[j].lastName > array[j + 1].lastName) {
        UndergradStudents temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void InitializeStructures(UndergradStudents us[], int &size) {
  // Initialize first student entry. The database can hold from 1 to 20 students
  // Counter for number of students in database
  int student = 1;
  int max = 20;

  // Student information variables
  string firstName, lastName, major;
  int studentIDnumber;
  float GPA;
  cout << "Student 0" << student << ":Enter first name (or x to quit): ";
  cin >> firstName;
  cout << endl;

  

}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {

}