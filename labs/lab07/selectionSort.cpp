<<<<<<< HEAD
/* Main function for selectionSort.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
=======
>>>>>>> 44222289d35e50785869ecca9b221d858ce751a6
#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
<<<<<<< HEAD
using namespace std;
=======

using namespace std;

>>>>>>> 44222289d35e50785869ecca9b221d858ce751a6
#include "sheaders.h"

int main() {
    // 1. Get filename from user and check it
<<<<<<< HEAD
    // 2. Get size of file to then create dynamic array
    //      Note: You HAVE to use the functions:
    //      getFileSize() and getArray() here
    // 3. Print original array (see PDF lab description for details)
    // 4. Ask user for ascending or descending sort
    // 5. Run selection sort on the array
    //      Note: You HAVE to use the function sort() here
    // 6. Print sorted array (see PDF lab description for details)

    return 0;
}
=======
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
    int input = 0;
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
>>>>>>> 44222289d35e50785869ecca9b221d858ce751a6
