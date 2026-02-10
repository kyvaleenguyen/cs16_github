
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

// Split function definition
vector<string> split(string target, string delimiter) {
    // Variable declarations
    vector<string> substrings;
    string word;

    // EDGE CASES @-@

    // If delimiter empty
    if (delimiter == "") {
        return substrings;
    }

    // If delimiter in target
    if (target.find(delimiter) != string::npos) {
        cout << "The substrings are: ";
    } else {
        cout << "No substrings.";
        return substrings;
    }

    // If target == delimite
    if (target == delimiter) {
        return substrings;
    }

    // If there are substrings
    // Create substrings vector and word string to store substrings in and add to substrings vector
    // Control size of substrings vector to save memory
    substrings.reserve(target.size());
    // Integer to set start of target index for substrings to 0
    int start = 0;
    for (int i = 0; i < target.size(); i++) {
        // If delimiter found at index i in target and if the substr size is greater than 0
        if (target[i] == delimiter[0]) {
            // If the word found is not an empty string, add it to the substrings vector
            word = target.substr(start, i - start);
            if (word != "") {
                word.insert(0, "\"");
                word.insert(word.size(), "\"");
                // If word isnt the first element, add comma to last substring
                if (substrings.size() > 0) {
                    substrings.back() += ", ";
                }
                substrings.push_back(word);
            }
            // Change start index if delimiter found
            start = i + 1;
        }
    }

    // Get last substring after last delimiter & make sure the last word found isn't an empty string
    if (start < target.size()) {
        string last_substr = target.substr(start);
        if (last_substr != "") {
            string formatted_substr = "\"" + last_substr + "\"";
            // Add comma before last substring 
            if (substrings.size() > 0) {
                substrings.back() += ", ";
            }
            substrings.push_back(formatted_substr); 
        }
    }
    // Organize substrings with proper formatting and print statement, then return substrings
    for (int i=0; i < substrings.size(); i++) {
        cout << substrings[i];
    }
    return substrings;
}