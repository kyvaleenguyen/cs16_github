#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

// Int factorial func declaration
int factorial(int n);

int main () {
    // Int factorial func use
    int num = 5;
    cout << "The factorial of " << num << " is: " << factorial(5) << endl;

    

    
    return 0;
}

// Int factorial func definition
int factorial(int n) {
    // Base case (prevents infinite recursion)
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}