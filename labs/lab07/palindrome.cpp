#include <iostream> // for cout, cin, endl
#include <string>   // for string

using namespace std;

#include "pheaders.h"

int main() {
    // 1. Get a string from the user (see examples given)
    cout << "Enter sentence:" << endl;
    string sentence;
    getline(cin, sentence);

    // 2. Clean up the string using the required function
    cleanUp(sentence);

    // Test case: test for int only inputs & if sentence is being properly cleaned
    cout << sentence << endl;
    
    // 3. Check to see if string is a palindrome
    isPalindrome(sentence);
    cout << sentence[0] << " " << sentence[sentence.size()-1] << endl;

    // 4. Print out message accordingly (see examples given)
    // Print if it is or is not a palindrome
    if (isPalindrome(sentence) == true) {
        cout << "It is a palindrome.";
    } 
    if (isPalindrome(sentence) == false) {
        cout << "It is not a palindrome.";
    }
    return 0;
}

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