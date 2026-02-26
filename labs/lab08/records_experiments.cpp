#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// Bubblesort function declaration
void bubbleSort(char *array, int size);
void bubbleSort2(string *array, int size);

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