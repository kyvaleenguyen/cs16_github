#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
int FindNum(ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    // If opening file fails
    if (!ifs.is_open()) {
        cerr << "Cannot open " << fname;
        exit(1);
    }

    // find the 2nd largest int and print it
    cout << FindNum(ifs) << endl;
    
    ifs.close();
    return 0;
}


// Pre-condition: File MUST contain integers & have at least 2 integers within the file (don't need to check for how many ints are in file) 
//      Keeps a running maximum to check if the next int is bigger than the last

// Post-condition: Will return second largest int found from file throughout entire file
int FindNum(ifstream &ifs) {
    // Create int variable to track ints read from ifstream
    // Initialize largest & secondLargest as ints before running total begins
    int current;
    int largest, secondLargest;
    
    // Create 1st & 2nd int values to be read from in file first & increment from there
    int first, second;
    ifs >> first;
    ifs >> second;

    if (first > second) {
        largest = first;
        secondLargest = second;
    } else {
        largest = second;
        secondLargest = first;
    }

    while (ifs >> current) {
        // Check if the current value found & read in the file is greater than the largest value initialized earlier
        if (current > largest) {
            // If it is large, the old largest is now the 2nd largest
            secondLargest = largest;
            largest = current;
        } 
        // Check if the current value is greater than the secondLargest & does not equal the largest value
        else if (current > secondLargest) {
            // If current is greater than secondLargest, assign current to secondLargest
            secondLargest = current;
        }
    }

    // Return secondLargest value found within file
    return secondLargest;
}