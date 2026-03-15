#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

// argc & argv testing...

int main (int argc, char *argv[]) {
    cout << "There are: " << argc << " arguments here." << endl;
    cout << "Prining all the arguments..." << endl;
        for(int i = 0; i < argc; i++) {
            cout << "\targv[" << i << "] is : " << argv[i] << endl;
        }
    cout << endl;
    
    return 0;
}