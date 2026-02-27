// file: r_functions.cpp
// YOUR NAME HERE
// Kyvalee Khloy Nguyen

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

#include "r_structs.h"
#include "r_headers.h"

using namespace std;

// Define the functions, per the list in r_headers.
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

  // Student information variables
  string firstName, lastName, major;
  // Were going to declare studentIDnumber & GPA as strings, then convert to appropriate numerical types using stoi & stod
  // For studentIDnumber use stoi
  string studentIDnumber;
  // For GPA use stod
  string GPA;

  // Numerical variables to store the values in after using stoi & stod
  int studentID;
  double gpa;
  
  // Use for loop to get all user input (up to 20) in Undergrad students array
  for (int i = 1; i <= size; i++) {
    // Printing
    cout << "Student 0" << student << ": Enter first name (or x to quit): ";
    getline(cin, firstName);

    // Check if user wants to quit program (using 'x' or 'X' key)
    if (firstName == "x" || firstName == "X") {
      exit(1);
    }

    // Save first name to undergrad students strcuture firstNames variable (do the same for the other variables in the structure)
    //    Note: the firstNames in the next line arent the same variable, they are different (.firstname is structure variable, 2nd is local string variable)
    us[i].firstName = firstName;

    // If user enters entire student information
    // Get last name from user
    cout << "Student 0" << student << ": Enter last name: ";
    getline(cin, lastName);
    us[i].lastName = lastName;

    // Get major
    cout << "Stuent 0" << student << ": Enter major: ";
    getline(cin, major);
    us[i].major = major;

    // Get GPA (years 1 - 4)
    //  Note: the actual GPA variable stored in the .GPA structure variable is the average GPA over all 4 years
    double gpaTotal[4] = {};
    for (int i = 1; i <= 4; i++) {
      cout << "Student 0" << student << ": Enter GPA Year " << i << ": ";
      getline(cin, GPA);
      gpaTotal[i] = stod(GPA);
    }
    // Create double average variable to save actual average in the GPA structure variable
    double totalGPA = 0;
    for (int i = 0; i <= 4; i++) {
      totalGPA += gpaTotal[i];
    }
    double avGPA = totalGPA / 4;
  }
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
  // Open output file, aka "results.txt" for printing output in ofstream
  outf.open(OUTPUTFILE);

  // 

}