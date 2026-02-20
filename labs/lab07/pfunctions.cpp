#include <iostream>
#include <string>

using namespace std;

#include "pheaders.h"

// Function call: isPalindrome
bool isPalindrome(string s) {
    // Base case
    if (s.size() <= 1) {
        return true;
    }

    // Check if the first & last letters match. If they do, continue inwards checking if the sentence is a palindrome
    if (s[0] == s[s.size()-1]) {
        // Reassign correct indexing to string s once ends of sentence have been verified to be equal to each other & continue checking inwards. RECURSION :D
        string sub = s.substr(1, s.size()-2);
        // Recursive function call
        return isPalindrome(sub);
    } else {
        // If the letters dont match, the sentence isnt a palindrome. Return false
        return false;
    }
}

// Pre-condition: The string word must already exist and be defined as a string type variable upon function call
// Post-condition: Lowers capitalization for all words & removes non-letter characters within the string
void cleanUp(string &s) {
    // Create string variable to store cleaned string
    string cleanString = "";

    // Remove non-letter characters & lower letter characters in string
    for (char c : s) {
        // Check if character is a letter
        if(isalpha(c)) {
            cleanString += tolower(c);
        }
    }
    // Assign cleaned string to word reference
    s = cleanString;
}