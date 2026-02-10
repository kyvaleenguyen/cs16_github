#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function declaration
vector<string> split(string target, string delimiter);

/* Pre-condition: user must enter string to be split after being prompted by first getline command. In the second getline
command, the user enters a delimiter string that MUST only be one character long.*/

/*Post-condition: the split() function is run and formats the strings into a substring string vector according to what has
been defined as the delimiter string in the getline command in the int main function.*/
int main () {
    string target, delimiter;
    // Get string from user
    cout << "Enter string to split:" << endl;
    getline(cin, target);

    // Enter string delimiter
    cout << "Enter delimiter string:" << endl;
    getline(cin, delimiter);

    // Split function call
    split(target, delimiter);
    return 0;
}

vector<string> split(string target, string delimiter) {
    // Variable declarations
    vector<string> substrings;

    // EDGE CASES @-@

    // if delimiter empty
    if (delimiter == "") {
        return substrings; 
    }

    // if delimiter not present in target
    if (target.find(delimiter) == string::npos) {
        cout << "No substrings." << endl;
        return substrings;
    }

    // If delimiter found print header "The substrings are: "
    cout << "The substrings are: ";

    // Edge case: target == delimiter
    if (target == delimiter) {
        return substrings;
    }

    // If there are substrings
    // Create substrings vector and word string to store substrings in and add to substrings vector
    int start = 0;
    for (int i = 0; i < (int)target.size(); i++) {
        if (target[i] == delimiter[0]) {
            // If the word found is not an empty string, add it to the substrings vector
            string word = target.substr(start, i - start);
            // If word isnt the first element, add comma to last substring
            if (word != "") {
                if (substrings.size() > 0) substrings.back() += ", ";
                substrings.push_back("\"" + word + "\"");
            }
            // Change start index if delimiter found
            start = i + 1;
        }
    }

    // Get last substring after last delimiter & make sure the last word found isn't an empty string
    if (start < (int)target.size()) {
        string last = target.substr(start);
        if (last != "") {
            if (substrings.size() > 0) substrings.back() += ", ";
            substrings.push_back("\"" + last + "\"");
        }
    }

    // Print formatted substrings
    for (int i = 0; i < (int)substrings.size(); i++) {
        cout << substrings[i];
    }
    return substrings;
}