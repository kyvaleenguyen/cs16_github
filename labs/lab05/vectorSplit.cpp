#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function declaration
vector<string> split(string target, string delimiter);


int main () {
    string target, delimiter;
    // Get string from user
    cout << "Enter string to split:" << endl;
    getline(cin, target);

    // Enter string delimiter
    cout << "Enter delimiter string:" << endl;
    getline(cin, delimiter);
    // If delimiter entered has a character value of more than one, exit the program
    if (delimiter.size() > 1) {
        cerr << "Delimiter must only be one character.";
    }
    // Split function call
    split(target, delimiter);
    return 0;
}

// Split function definition
vector<string> split(string target, string delimiter) {
    // Variable declarations
    vector<string> substrings;
    string word;

    // Print substrings
    // If no substrings
    if (target.find(delimiter) == string::npos) {
        cerr << "No substrings.";
    }

    // If there are substrings
    if (target.find(delimiter) != string::npos) {
        // Create substrings vector and word string to store substrings in and add to substrings vector
        // Control size of substrings vector to save memory
        substrings.reserve(target.size());
        // Integer to set start of target index for substrings to 0
        int start = 0;
        for (int i = 0; i < target.size(); i++) {
            // If delimiter found at index i in target and if the substr size is greater than 0
            if ((target[i] == delimiter[0]) && ((i-start)>=0)) {
                // If the word found is not an empty string, add it to the substrings vector
                word = target.substr(start, i - start);
                if (word != "") {
                    substrings.push_back(word);
                }
                // Change start index if delimiter found
                start = i + 1;
            }
        }
        // Get last substring after last delimiter & make sure the last word found isn't an empty string
        if (start < target.size()) {
            string last_substr = target.substr(start);
            if (word != "") {
               string formatted_substr = last_substr;
               substrings.push_back(formatted_substr); 
            }
        }
            cout << "The substrings are: ";

    }
    // Organize substrings with proper formatting and print statement, then return substrings
    for (int i=0; i < substrings.size(); i++) {
        cout << substrings[i];
    }
    return substrings;
}