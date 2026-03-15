#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <fstream>

using namespace std;

// FINAL REVIEW
//      Using worksheet for final review posted on canvas

int main () {
    // #1
    // Bool func NOT can be used using symbols: 
    // || OR
    // ! NOT
    // != NOT EQUAL (comparison)
    // not() (nothing)
    // && AND

    // #2
    int num = 5;
    for (++num; num < 10; num++) {
        cout << num;
    }
    cout << endl;

    // #3
    // Cannot use String in a switch statement
    //      Can use int, char, bool

    // #4
    // funcs cant be defined in the body of another funcs

    // #5
    string str = "Apple Pie";
    // str.erase() erases everything in the string
    // str.replace(1, 1, "a") format -> replace(position, length, character replacing) -> new string == "Aaple Pie"

    // #6
    int y[4] = {1, 2, 0, 3};
    int x[2][3] = {{2, 4, 6}, {10, 20, 40}};
    int z[2][2][2] = { { {1, 2}, {3, 4} }, { {5, 6}, {7, 8} } };

    cout << y[y[0]] << endl;
    cout << x[1][2] << endl;
    cout << x[0][1] << endl;
    cout << x[1][y[2]] << endl;
    cout << z[0][1][0] << endl;

    // #7
    int w = 0, v = 14, count = 0;
    string s= "a";
    while ( (w < 10) && (v > 10) ) {
        s += s;
        for (int j = 0; j < 2; j++) {
            cout << "j = " << j << "; w = " << w << "; v = " << v << endl;
            count++;
        }
        w += 5;
        v -= 3;
    }
    cout << s << ++count << endl;

    return 0;
}