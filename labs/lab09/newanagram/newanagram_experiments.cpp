#include <iostream>
#include <string>

using namespace std;

// cleanUp v1 declaration
void cleanUp1(string &s);

// cleanUp v2 declaration
void cleanUp2(string &s);

// CountLetters2 identifiers
void countLetters2(string sentence);

//      Google Gemini version
void countLetters3(string sentence);

int main () {
    // Experimenting w/ .erase() built in function for strings
    string s = "H1! I hAve 2 appl3s!";

    // cleanUp v1 call
    cleanUp1(s);

    // cleanUp v2 call
    cleanUp2(s);

    // String array experiments
    // Initialize all 26 values of strings in the array to ""
    string letters[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int lettersSize = 26;
    // Print string array
    for (int i = 0; i < lettersSize; i++) {
        cout << letters[i] << " ";
    }
    cout << endl;

    // Alphabet array experimentation
    int alpha[26] = {0};
    int alphaSize = 26;
    for (int i = 0; i < alphaSize; i++) {
        cout << alpha[i] << " ";
    }
    cout << endl;

    // Editing alpha array
    alpha[0] += 1;
    for (int i = 0; i < alphaSize; i++) {
        cout << alpha[i] << " ";
    }
    cout << endl;

    // ASCII int printing experiment
    char firstLetter = 97;
    cout << "The first lowercase letter of the alphabet is: " << firstLetter << endl;

    // Count letters2 function test
    string test1 = "apple orange banana";
    countLetters3(test1);
    cout << endl;

    return 0;
}

// cleanUp v1
void cleanUp1(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (!isalpha(s[i])) {
            s.erase(i, 1);
        }
    }
    cout << "new string is: " << s << endl;
}

// cleanUp v2
void cleanUp2(string &s) {
    string clean_s = "";

    for (char c : s) {
        if (isalpha(c)) {
            clean_s += tolower(c);
        }
    }
    s = clean_s;

    cout << "new string is: " << s << endl;
}

// Count letters new anagrams func experiment
/*void countLetters(int alpaha[26] = {0});
void countLetters(int alpha[26] = {0}) {
    int alphaSize = 26;
    // ASCII version
    for (int i = 0; i < StringValue.size(); i++) {
        // Check every lowercase alphabet ASCII character to add to count of letter found
        for (char j = 97; j < 122; j++) {
            if (StringValue[i] = j) {
                alpha[j-97] += 1;
            }
        }
    }

    for (int k = 0; k < alphaSize; k++) {
        cout << alpha[k] << " ";
    }
}*/

// Count letters 2 new anagrams func experiment
//      Less efficient version: runs 2600 checks
void countLetters2(string sentence) {
    int alpha[26] = {0};
    int alphaSize = 26;
    // ASCII version
    for (int i = 0; i < sentence.size(); i++) {
        // Check every lowercase alphabet ASCII character to add to count of letter found
        for (char j = 97; j <= 122; j++) {
            if (sentence[i] == j) {
                alpha[j-97] += 1;
            }
        }
    }

    for (int k = 0; k < alphaSize; k++) {
        cout << alpha[k] << " ";
    }
}

// Count letters 2 new anagrams func experiment
//      Google Gemini version
//      More efficient version: runs 100 checks
void countLetters3(string sentence) {
    int alpha[26] = {0};
    int alphaSize = 26;
    // ASCII version
    for (int i = 0; i < sentence.size(); i++) {
        // Check every lowercase alphabet ASCII character to add to count of letter found
        char c = sentence[i];
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
        if (c >= 97 && c <= 122) {
            alpha[c - 97]++;
        }
    }

    for (int k = 0; k < alphaSize; k++) {
        cout << alpha[k] << " ";
    }
}