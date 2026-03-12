// file: r_functions.cpp
// YOUR NAME HERE
// Kyvalee Khloy Nguyen

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip> //required for set precision

using namespace std;

// Define the functions, per the list in r_headers.

void NameSort(UndergradStudents array[], int size) {
  // Create for loop within a for loop to access lastName variables within the UndergradStudents struct
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // If first letter of last name precedes the last name before, swap the two's positions in the array
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
  // Max size for number of students in input database
  int maxStudents = 20;

  // Student ID number for each student entered by order entered
  int studentID = 1;

  // Counter for number of students in database
  int count = 0;

  // Student information variables
  string firstName, lastName, major;
  // Were going to declare studentIDnumber & GPA as strings, then convert to appropriate numerical types using stoi & stod
  // For studentIDnumber use stoi
  string studentIDnumber;
  // For GPA use stod
  string GPA;

  double gpa;

  // Set precision for GPA calculation
  cout << fixed << showpoint;
  cout << setprecision(2);
  
  // Use for loop to get all user input (up to 20) in Undergrad students array
  for (int i = 0; i < maxStudents; i++) {
    // Printing
    cout << "Student 0" << i + 1 << ": Enter first name (or x to quit): ";
    getline(cin, firstName);

    // Check if user wants to quit program (using 'x' or 'X' key)
    if (firstName == "x" || firstName == "X") {
      break;
    }

    // Save first name to undergrad students strcuture firstNames variable (do the same for the other variables in the structure)
    //    Note: the firstNames in the next line arent the same variable, they are different (.firstname is structure variable, 2nd is local string variable)
    us[i].firstName = firstName;

    // If user enters entire student information
    // Get last name from user
    cout << "Student 0" << i + 1 << ": Enter last name: ";
    getline(cin, lastName);
    us[i].lastName = lastName;

    // Get major
    cout << "Stuent 0" << i + 1 << ": Enter major: ";
    getline(cin, major);
    us[i].major = major;

    // Get GPA (years 1 - 4)
    //  Note: the actual GPA variable stored in the .GPA structure variable is the average GPA over all 4 years
    double gpaTotal[4] = {};
    for (int j = 0; j < 4; j++) {
      cout << "Student 0" << i + 1 << ": Enter GPA Year " << j + 1 << ": ";
      getline(cin, GPA);
      gpaTotal[j] = stod(GPA);
    }
    // Create double average variable to save actual average in the GPA structure variable
    double totalGPA = 0;
    for (int i = 0; i < 4; i++) {
      totalGPA += gpaTotal[i];
    }
    double avGPA = totalGPA / 4;
    // Add to GPA variable in struct
    us[i].GPA = avGPA;

    // Add to student counter for every new entry in database
    count++;

    // Set size equal to count for write results later on
    size = count;

    // Add student ID number to current student in struct variable id number
    us[i].studentIDnumber = studentID;

    // Add to student ID number
    studentID++;

    // New line for syntax between student entrys in the database
    cout << endl;
  }
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
  // Call NameSort
  NameSort(us, size);

  // Open output file, aka "results.txt" for printing output in ofstream
  outf.open(OUTPUTFILE);

  // Print output appropriately
  outf << "These are the results sorted by last name:" << endl;
  for (int i = 0; i < size; i++) {
    outf << "ID# " << us[i].studentIDnumber << ": " << us[i].lastName << ": " << us[i].firstName << ": " << us[i].major << ": " << fixed << showpoint << setprecision(2) << us[i].GPA << endl;
  }
  
  // Close output file once done
  outf.close();

}