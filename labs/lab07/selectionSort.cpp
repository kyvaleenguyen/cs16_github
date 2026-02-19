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

    // Check if file cant be opened
    ifs.open(fname);

    // If opening file fails
    if (!ifs.is_open()) {
        cerr << "Cannot open " << fname;
        exit(1);
    }

    // 2. Get size of file to then create dynamic array
    //      Note: You HAVE to use the functions:
    //      getFileSize() and getArray() here


    // 3. Print original array (see PDF lab description for details)


    // 4. Ask user for ascending or descending sort
    cout << "Asending (0) or Descending (1): ";
    int input;
    switch(input) {
        case '0': 
            // sort ascending
            break;
        case '1': 
            // sort descending
            break;
        default: 
            cout << "Invalid input. Must be (0) or (1)";
            exit (1);
    }

    // 5. Run selection sort on the array
    //      Note: You HAVE to use the function sort() here


    // 6. Print sorted array (see PDF lab description for details)


    return 0;
}