#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    // #1
    cout << "#1" << endl;
    // code version 1
    string name;
    cout << "Enter name: ";
    cin >> name;
    cout << name;
    cout << endl;
    cin.ignore(1000, '\n');
    /* Predicted output: prints out "Enter name: ", then prompts user to enter string name as input, and prints the name after
    The output should look like: 
    "Enter name: <name>. 
    <name>" 
    Note: This version CANNOT get a name with a surname, maiden name, and 1st if the user tries to enter multiple strings 
    separated by spaces, the string stored in name only is the 1st*/

    // code version 2 (can get a full name of a person because getline gets input until the user presses enter)
    string name2;
    cout << "Enter name: ";
    getline(cin, name2);
    cout << name2;
    cout << endl;

    // #2


    return 0;
}