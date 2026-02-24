#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// #4 function declaration
int sumOdds(int N);

int main () {
    // #4
    int a = 8;
    sumOdds(a);
}

// #4 function definition: Write a function definition of a recursive function that finds the sum of all odd integers in the first int N numbers
//  Ex: If N = 8, the sum is (1 + 3 + 5 + 7 ) = 16
int sumOdds(int N) {
    // Base case: stop once N reaches 0
    if (N <= 0) {
        return 0;
    }
    // If N odd: add odd integer to total
    if (N % 2 != 0) {
        return N + sumOdds(N - 1);
    } else {
        // N is even so skip it and don't add to total
        return sumOdds(N - 1);
    }
}