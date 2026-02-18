// Do not add any other #include statement!
#include <iostream>

using namespace std;

// Declare printV() here
void printV(long long n);

int main() {
    // 1. Get user input
    cout << "Enter integer: ";
    long long intInput;
    cin >> intInput;

    // 2. Check input and pass it on to printV()
    //  Input MUST be positive (greater than 0). If input is less than 1, print error message & quit program
    if (intInput < 1) {
        cerr << "Input must be a positive integer.";
        exit(1);
    }

    // 3. printV() function call
    printV(intInput);

    return 0;
}

// Define printV() here
void printV(long long n) {
    // Use statements to sort out digits within the function since I can't use arrays vectors OR strings
    // Check if n < 10 first. (If n < 10, only print out n once & end program)
    if (n < 10) {
        cout << n << endl;
    } else {
        printV(n / 10);
        cout << (n % 10) << endl;
    }
}