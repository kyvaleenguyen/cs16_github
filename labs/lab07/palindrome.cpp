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