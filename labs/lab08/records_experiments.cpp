#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip> //required for set precision

using namespace std;

// DECLARE THE struct UndergradStudents HERE:
struct UndergradStudents {
    int studentIDnumber;
    string firstName;
    string lastName;
    string major;
    float GPA;
};

// Bubblesort function declaration
void bubbleSort(char *array, int size);
void bubbleSort2(string *array, int size);

// Name sort function definition
void NameSort(UndergradStudents array[], int size);

// Intiailize structures function definition
void InitializeStructures(UndergradStudents us[], int &size);

int main () {
    // Set precision
  cout << fixed << showpoint;
  cout << setprecision(2);
  
  char letter = 97;
  cout << letter << endl;
  cout << tolower('a') << endl;
  cout << tolower('A') << endl;

  string bub[5] = {"apple", "orange", "grape", "pear", "cherry"};
  int size = 5;
  bubbleSort2(bub, size);
  for (int i = 0; i < size; i++) {
      cout << bub[i] << " ";
  }
  cout << endl;
  
  for (int i = 0; i < size; i++) {
      cout << bub[i].length() << " ";
  }
  cout << endl;

  char letters[5] = {'e', 'b', 'k', 'j', 'x'};
  int lettersSize = 5;
  for (int i = 0; i < lettersSize; i++) {
      cout << tolower(letters[i]) << " ";
  }
  cout << endl;
  bubbleSort(letters, lettersSize);
  for (int i = 0; i < lettersSize; i++) {
      cout << tolower(letters[i]) << " ";
  }
  cout << endl;

  UndergradStudents KN, PG, KC;
  KN.studentIDnumber = 4595;
  KN.firstName = "Kyvalee";
  KN.lastName = "Nguyen";
  KN.major = "EE";
  KN.GPA = 3.75;

  PG.studentIDnumber = 4595;
  PG.firstName = "Peter";
  PG.lastName = "Gutierrez";
  PG.major = "GEOG SOC";
  PG.GPA = 3.75;

  KC.studentIDnumber = 4596;
  KC.firstName = "Kayla";
  KC.lastName = "Chan";
  KC.major = "UNDECLARED";
  KC.GPA = 3.85;

  cout << "Undergrad student 1's first name is: " << KN.firstName << endl;
  cout << endl;

  // Sort Undergrad students into array
  UndergradStudents students[3] = {KN, PG, KC};
  int studentsSize = 3;
  int ptr = studentsSize;

  // Sort array using namesort function
  NameSort(students, ptr);

  // print all last names stored in array using '.' for according printing from the structure (structures use '.' for accessing variables within the structure)
  cout << "Sorted Students by Last Name:" << endl;
  for (int i = 0; i < studentsSize; i++) {
      cout << students[i].lastName << ", " << students[i].firstName << endl;
  }

  // Intialize structures test
  UndergradStudents undergrads[20];
  int undergradsSize = 20;
  int ptr2 = undergradsSize;
  InitializeStructures(undergrads, undergradsSize);

  // Testing average GPA division
  double GPA1 = 4.0;
  double GPA2 = 3.9;
  double GPA3 = 3.8;
  double GPA4 = 4.0;
  double avrGPA = (GPA1 + GPA2 + GPA3 + GPA4) / 4;
  cout << "Average GPA is: " << avrGPA << endl;
  cout << endl;

  // Get GPA (years 1 - 4)
  //  Note: the actual GPA variable stored in the .GPA structure variable is the average GPA over all 4 years
  string GPA;
  double gpaTotal[4] = {};
  for (int i = 1; i <= 4; i++) {
    cout << "Enter GPA Year " << i << ": ";
    getline(cin, GPA);
    gpaTotal[i] = stod(GPA);
  }
  // Create double average variable to save actual average in the GPA structure variable
  double totalGPA = 0;
  for (int i = 0; i <= 4; i++) {
    totalGPA += gpaTotal[i];
  }
  double avGPA = totalGPA / 4;
  cout << "Average GPA is: " << avGPA << endl;
  cout << endl;

  return 0;
}

// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
void bubbleSort(char *array, int size) {
  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < size - j; i++) {
      if (tolower(array[i]) > tolower(array[i + 1])) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
  }
}

// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
void bubbleSort2(string *array, int size) {
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

// Name sort function definition
void NameSort(UndergradStudents array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j].lastName > array[j + 1].lastName) {
        UndergradStudents temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// Initialize structures function definition
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
    
    // Newline syntax
    cout << endl;

    // Add to student counter to keep track of students within database
    student++;
  }
}