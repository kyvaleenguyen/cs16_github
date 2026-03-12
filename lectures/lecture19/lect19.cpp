#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

double power(int x, int y);

int main () {

    // Destructors
    //      Destroy dynamic variables

    // FINAL REVIEW

    // iClicker 1
        cout << power(3, 2) << endl;

    // iClicker 2
        int a = 10, b = 7, c = 8, d = b;
        for (int k = 0; k <= a; k++) {
            if ((c < k) && (k > d)) {
                cout << b;
            }
        }
        cout << endl;

    // iClicker 3
        /*char c;
        string s;

        ifstream fin;
        ofstream fout;

        fin.open("input.txt");
        fout.open("output.txt");
        fin.get(c);
        fin >> s;
        fin.get(c);
        fin.get(c);
        fin.get(c);
        fin >> s;
        fout << s << endl;
        
        fin.close();
        fout.close();*/

    // iClicker 4
        // Hexadecimal to decimal conversion
        // 0xA5 in hex = 165 in decimal
        // 1011001 in binary = 89 in decimal
        //      Use positional notation right to left 2 to the power of the position from right to left
        // 1023 in hexadecimal = 0x3FFdecimal digits 
        //      Hint 2^10 - 1 = 1023
        //      Note: Every 4 digits in binary is a hex digit (right to left)

    // iClicker 5
        // char s[10] = {'C', 'M', 'P', 'S', 'C', '1', '6', '\0'};
        // char *p1 = s;
        // char *p2 = &s[3];
        // string str = *(p1+6) + *p2;
            // This is incorrect because you can only concatenate two strings using the '+' operator
            // This would have worked if the array was defined as string type
                string s[10] = {"C", "M", "P", "S", "C", "1", "6", "\0"};
                string *p1 = s;
                string *p2 = &s[3];
                string str = *(p1+6) + *p2;
                cout << str << endl;

    // iClicker 7
        vector<float> iv;
        for (int i = 6; i < 10; i++) {
            iv.push_back(i/2);
        }
        cout << iv.size();
        for (int i = 0; i < iv.size(); i++) {
            cout << iv[i];
        }
        cout << endl;

    return 0;
}

// iClicker 1
double power(int x, int y) {
    int p = 1;
    for (int j = 0; j < y; j++) {
        p *=x ;
    }
    return p;
}

