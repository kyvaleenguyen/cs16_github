#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// argc & argv test converting argv to double or int (using stoi & stod from cstdlib library)

int main (int argc, char *argv[]) {
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int add = num1 + num2;
    int prod = num1 * num2;
    cout << add << " " << prod << endl;

    return 0;
}