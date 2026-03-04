#include <iostream>
#include <string>

using namespace std;

// cleanUp v1 declaration
void cleanUp1(string &s);

// cleanUp v2 declaration
void cleanUp2(string &s);

int main () {
    // Experimenting w/ .erase() built in function for strings
    string s = "H1! I hAve 2 appl3s!";

    // cleanUp v1 call
    cleanUp1(s);

    // cleanUp v2 call
    cleanUp2(s);

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