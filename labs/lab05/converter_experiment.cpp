#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main (int argc, char *argv[]) {

    // Test case using *argv[]
    cout << "There are " << argc << " arguments here:" << endl;
    cout << "Lets print out all the arguments:" << endl;
    for (int i = 0; i < argc; i++)
    cout << "argv[" << i << "] is : " << argv[i] << endl;

    // Decimal array experiment
    string sdec = "1101100";
    int decimal = 0;
    int n = sdec.size();

    for (int i = 0; i < n; i++) {
        if (sdec[i] == '1') {
            // Calculate power: rightmost bit is 2^0
            decimal += pow(2, n - 1 - i);
        }
    }
    // decimal now equals 108

    cout << decimal << endl;

    return 0;
}