#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// lecture 20

int main () {
    int a = 10, b = 7, c = 8, d = b;
    for (int k = 0; k <= a; k++) {
        if (( c < k) && ( k > d)) {
            cout << b << " ";
        }
    }

    return 0;
}