#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

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


int main () {
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

  // 1. Put your individual students into an array
  UndergradStudents students[3] = {KN, PG, KC};
  int nameSize = 3;

  // 2. Pass the ARRAY variable to the function
  NameSort(students, nameSize);

  // 3. Print from the array using the dot operator
  cout << "Sorted Students by Last Name:" << endl;
  for (int i = 0; i < nameSize; i++) {
      cout << students[i].lastName << ", " << students[i].firstName << endl;
  }

  int num = 01;
  cout << num << endl;
  cout << num + 1 << endl;

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