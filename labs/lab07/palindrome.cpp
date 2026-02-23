<<<<<<< HEAD
/* Main function for palindrome.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
=======
#include <iostream> // for cout, cin, endl
#include <string>   // for string

using namespace std;

>>>>>>> 44222289d35e50785869ecca9b221d858ce751a6
#include "pheaders.h"

int main() {
    // 1. Get a string from the user (see examples given)
<<<<<<< HEAD
    // 2. Clean up the string using the required function
    // 3. Check to see if string is a palindrome
    // 4. Print out message accordingly (see examples given)

    return 0;
}

=======
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
>>>>>>> 44222289d35e50785869ecca9b221d858ce751a6
