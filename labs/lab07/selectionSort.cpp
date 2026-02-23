#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit

using namespace std;

#include "sheaders.h"

int main() {
    // 1. Get filename from user and check it
    // Create ifstream to read from file & string variable for filename
    ifstream ifs;
    string fname;

    cout << "Enter filename: ";
    cin >> fname;

    // 2. Get size of file to then create dynamic array
    //      Note: You HAVE to use the functions:
    //      getFileSize() and getArray() here
    int size = getFileSize(ifs, fname);

    // Create dynamic array to store values read from input file through ifstream
    int* arr = new int[size]; 

    // Get array from input file
    getArray(ifs, fname, arr, size);

    // 3. Print original array
    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 4. Ask user for ascending or descending sort
    cout << "Asending (0) or Descending (1): ";
    int input = 0;
    cin >> input;

    // Create boolean variable to store value for ascending or descending sorting
    bool desc;
    if (input == 1) {
        // sort descending
        desc = true;
    } else if (input == 0) {
        // sort ascending
        desc = false;
    } else { 
        // If user does not enter valid input (0 or 1 only) when asked for sorting ascending or descending
        cout << "Invalid input. Must be (0) or (1)" << endl;

        // Delete dynamic array to store memory
        delete[] arr;
        exit(1);
    }

    // 5. Run selection sort on the array
    //      Note: You HAVE to use the function sort() here
    // Start at 0 for first run of sort & increment according to user input (ascending or descending)
    sort(desc, arr, size, 0);

    // 6. Print sorted array (see PDF lab description for details)
    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
