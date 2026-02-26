#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// SeqSearch declaration
// For loop version
int SeqSearch(int array[], int size, int target);

// SeqSearch function definition
//  While loop version
int SeqSearch2(int array[], int size, int target);

// binSearch function declaration
int binarySearch(int arr[], int size, int target, bool &found, int &location);

int main () {
    // SeqSearch example
    int target = 5;
    int list[5] = {1, 3, 5, 7, 9};
    int size = 5;

    // For loop version
    SeqSearch(list, size, target);

    // While loop version
    SeqSearch2(list, size, target);

    // binSearch size testing for odd array size
    cout << 7/2 + 1 << endl;

    // binSearch test
    bool found;
    int location;
    binarySearch(list, size, target, found, location);

    return 0;
}

// SeqSearch function definition
//  For loop version
int SeqSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            cout << "Target found at: " << i << endl;
            return i;
        }
    }
    cout << "Target not found :(" << endl;
    return -1;
}

// SeqSearch function definition
//  While loop version
int SeqSearch2(int array[], int size, int target) {
    int index = 0;
    while (index < size) {
        index++;
        if (array[index] == target) {
            // Found target
            cout << "Target found at: " << index << endl;
            return index;
        }
    }
    // Didnt find target
    cout << "Target not found :(" << endl;
    return -1;
}

// Binary search
int binarySearch(int arr[], int size, int target, bool &found, int &location) {
    // Location initializations
    int first = 0, last = size - 1, mid;

    // Found bool variable
    found = false;

    // While loop to check for midpoints & update accordingly
    while ((first <= last) && !(found)) {
        mid = (first + last) / 2;
        // Target found
        if (target == arr[mid]) {
            found = true;
            location = mid;

            cout << "Target found at: " << location << endl;
            return arr[mid];

        } else  if (target < arr[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    // Target not found
    cout << "Target not found :(" << endl;
    return -1;
}