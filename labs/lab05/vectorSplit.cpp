#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function declaration
vector<string> split(string target, string delimiter);


int main () {
    // Split function call
    string t, d;
    split(t, d);
    
    return 0;
}

// Split function definition
vector<string> split(string target, string delimiter) {
    // Variable declarations
    vector<string> substrings;
    string word;

    // Get string from user
    cout << "Enter string to split:" << endl;
    getline(cin, target);

    // Enter string delimiter
    cout << "Enter delimiter string:" << endl;
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
                word.insert(0, "\"");
                word.insert(word.size(), "\"");
                // Insert comma after word found
                word.insert(word.size(), ", ");
                // If the word is not an empty string, add it to the substrings string vector
                if (word != "") {
                    substrings.push_back(word);
                }
                // Change start index if delimiter found
                start = i + 1;
            }
        }
        // Get last substring after last delimiter & make sure the last word found isn't an empty string
        if (word != "") {
            // Insert quotes before & after last substring found
            target.insert(start, "\"");
            target.insert(start + word.size() + 1, "\"");
            string last_substr = target.substr(start, word.size() + 2);
            // Add last substring to substrings string vector
            substrings.push_back(last_substr);
        }
    }
    // Organize substrings with proper formatting and print statement, then return substrings
    cout << "The substrings are: ";
    for (int i=0; i < substrings.size(); i++) {
        cout << substrings[i];
    }
    return substrings;
}