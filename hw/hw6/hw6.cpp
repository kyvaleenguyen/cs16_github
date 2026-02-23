#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    // #2
    cout << "#2" << endl;
    cout << "Enter a line of input: ";
    char next;
    do {
        cin.get(next);
        cout << next;
    } while((!isdigit(next)) && (next != '\n'));
    cout << "END!" << endl;
    cout << endl;

    // #3
    cout << "#3" << endl;
    ifstream tin;
    char c;

    tin.open("t.txt");
    tin.get(c);
    while(!tin.eof()) {
        if((c!='e') && (c!= 'C')) {
            cout << c;
        }
        tin.get(c);
    }
    // Close ifstream tin
    tin.close();

    cout << endl;

    // #4


    return 0;
}

// #4
string file_name;
FindNum(file_name) {
    
}