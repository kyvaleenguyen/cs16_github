#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath> // for std::pow()

using namespace std;

// #4 function declaration
int sumOdds(int N);

// #5 function declaration
int RecursiveFunc(int num);

// #6 function declarations
int Fibo(int n);
vector<int> SFS(int n);

// #7 function declaration
int CountA(string sentence);

int main () {
    // #4
    int lim;
    cout << "Enter a value to calculate until: ";
    cin >> lim;
    cout << "The sum of all odd integers up until " << lim << " are: " << sumOdds(lim) << endl;
    cout << endl;

    // #5
    int elementN;
    cout << "Which element of the sequence would you like to know ";
    cin >> elementN;
    cout << "Element number " << elementN << " in the sequence is " << RecursiveFunc(elementN) << endl;
    cout << endl;

    // #6
    int number;
    cout << "Which element of the fibonnaci sequence would you like to know ";
    cin >> number;
    cout << "Element number " << number << " of the fibonacci sequence is " << Fibo(number) << endl;
    cout << endl;

    int limit;
    cout << "How many squares are in the fibonacci sequence up until: ";
    cin >> limit;

    // make vector
    vector<int> square_fibos = SFS(limit);

    cout << "The squares are: ";
    for (int num : square_fibos) {
        cout << num << " ";
    }
    cout << endl;

    // #7
    string a;
    cout << "Enter string to count number of letter 'a' or 'A's : ";
    cin.ignore();
    getline(cin, a);
    cout << CountA(a);

    return 0;
}

// #4 function definition: Write a function definition of a recursive function that finds the sum of all odd integers in the first int N numbers
//  Ex: If N = 8, the sum is (1 + 3 + 5 + 7 ) = 16
// Pre-condition: takes integer input to find the sum of all odd integers up to n numbers
// Post-condition: returns the sum of all odd ints until limit n
int sumOdds(int N) {
    // Base case: stop once N reaches 0
    if (N <= 0) {
        return 0;
    }
    // If N odd: add odd integer to total
    if (N % 2 != 0) {
        return N + sumOdds(N - 1);
    } else {
        // N is even so skip it & don't add to total
        return sumOdds(N - 1);
    }
}

// #5 function definition
//  Note: arithmetic sequence equation = 2n + 5
// Pre-condition: takes int input to begin calculating nth number in artihmetic sequence
// Post-condition: returns nth number in calculated arithmetic sequence (2n + 5)
int RecursiveFunc(int num) {
    // Base case: The first number in the sequence is 3
    if (num <= 1) {
        return 3;
    } else {
        // Use sequential equation: 2n + 5
        return 2 * RecursiveFunc(num - 1) + 5;
    }
}

// #6 function definitions
//  Note: fibonacci number sequence
// 
// Fibo : find nth element in fibonacci series (recursive function)
//
// SFS : calls Fibo & prints all squares of the Fibonacci sequence for the first N elements

// Pre-condition: takes integer inpt to find the nth number in the fibonacci series sequence
// Post-condition: returns the nth number in the fibonacci series
int Fibo(int n) {
    // Base case: first number in the sequence is 0
    if (n == 0) {
        return 0;
    }
    // Base case 2: second number in sequence is 1
    if (n == 1) {
        return 1;
    }
    // The first two numbers added make the third number, then the second and third numbers added make the fourth & so on
    // Add previous 2 numbers together to get next & keep doing same
    // Recursion
    int next = Fibo(n - 1) + Fibo(n - 2);
    return next;
}

// Pre-condition: n < 256
// Post-condition: SFS prints out all squares in Fibo series of first n elements
//      Note: doesn't need to be recursive
vector<int> SFS(int n) {
    // create vector<int> to store squares
    vector<int> squares;

    // Fibo function call & for loop
    //      Note: set i < 45 to avoid stack overflow
    for (int i = 0; i < 45; i++) {
        int fib = Fibo(i);
        // Check if nth element is perfect square
        int squared = fib * fib;
        squares.push_back(squared);

        // Check if squares.size() hits n
        if (squares.size() == n) {
            break;
        }
    }
    // Return vector<int> vector of all squares
    return squares;
}

// #7 recursive function
// Pre-condition: user enters string in getline. String must be defined as string type variable
// Post-condition: returns a count of the number of lowercase or uppercase 'a' alphbaetical characters there are in the input string
int CountA(string sentence) {
    // Get size of string
    int size = sentence.length();

    // Base case: if sentence length = 0
    if (size == 0) {
        return 0;
    }

    // Search string looking for lowercase & uppercase 'a'
    // Check first character at index 0
    int aFound = 0;
    if (sentence[0] == 'a' || sentence[0] == 'A') {
        // If a character found, add to count
        aFound++;
    }
    // Recursion
    // Add to the result of checking the rest of the string
    // Substr(1) makes a new string starting from index 1 to the end of the string
    return aFound + CountA(sentence.substr(1));
}