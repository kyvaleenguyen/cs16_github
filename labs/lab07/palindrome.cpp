#include <iostream> // for cout, cin, endl
#include <string>   // for string

using namespace std;

#include "pheaders.h"

int main() {
    // 1. Get a string from the user (see examples given)
    cout << "Enter sentence:" << endl;
    string sentence;
    cin >> sentence;

    // 2. Clean up the string using the required function
    cleanp(sentence);

    // 3. Check to see if string is a palindrome


    // 4. Print out message accordingly (see examples given)


    return 0;
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

// Function call: isPalindrome
bool isPalindrome(string s) {
    cleanUp(string s);
    // Create 2 ints to get first & last position when comparing letter from front to back going inwards
    int firstLetter = s[0];
    int lastLetter = s[s.size()];
    // Check if the first & last letters match. If they do, continue inwards checking if the sentence is a palindrome
    if (s[firstLetter] == s[lastLetter]) {
        // Recursive function
        isPalindrome(s);
        // Update position of first & last letter to continue checking inwards
        firstLetter++;
        lastLetter--;
    }
    if (n < 10) {
        cout << n << endl;
    } else {
        printV(n / 10);
        cout << (n % 10) << endl;
    }
}