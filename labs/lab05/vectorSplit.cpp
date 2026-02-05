#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function declaration
vector<string> split(string target, string delimiter);


int main () {

    // Get string from user
    cout << "Enter string to split:" << endl;
    string target;
    getline(cin, target);

    // Enter string delimiter
    cout << "Enter delimiter string" << endl;
    string delimiter;
    getline(cin, delimiter);
    // If delimiter entered has a character value of more than one, exit the program
    if (delimiter.size() > 1) {
        exit(1);
    }

    // Print substrings
    // If no substrings
    if (target.find(delimiter) == string::npos) {
            cout << "No substrings." << endl;
    }

    // If substrings
    if (target.find(delimiter) != string::npos) {
        // Create substrings vector and word string to store substrings in and add to substrings vector
        vector<string> substrings;
        string word;
        // Control size of substrings vector to save memory
        substrings.reserve(target.size());
        // Integer to set start of target index for substrings to 0
        int start = 0;
        for (int i = 0; i < target.size(); i++) {
            // If delimiter found at index i in target and if thw substr size is greater than 0
            if ((target[i] == delimiter[0]) && ((i-start)>=0)) {
                word = target.substr(start, i - start);
                if (word != "") {
                    substrings.push_back(word);
                }
                // Change start index if delimiter found
                start = i + 1;
            }
        }
        // Get last substring after last delimiter
        if (word != "") {
            substrings.push_back(target.substr(start));
        }

        // Print substrings
        cout << "The substrings are: ";
        for (int i = 0; i < substrings.size(); i++) {
            cout << "\"" << substrings[i] << "\"";
            // Print out a comma if the index in substrings vector is not the last index of the vector
            if ((i < substrings.size() - 1)) {
                cout << ", ";
            }
        }
        cout << endl;
    }


    return 0;
}