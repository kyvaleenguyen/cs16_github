// file: functions.cpp for newanagrams

// Define all member functions for class AString
//    as well as all other functions that need definition

// Accessor function
//
// Get the value of the original string member variables from the class
string getStringValue() {
    cout << "Two objects declared with values: " << StringValue;
}

// Mutator member function
//
// Clean up both strings
void cleanUp(string new_s) {
    string clean_s = "";

    for (char c : s) {
        if (isalpha(c)) {
            clean_s += tolower(c);
        }
    }
    s = clean_s;
}

// Mutator member function
//
// count # of letters found in both strings
void countLetters(int alphabet[26]) {


}

// Mutator member function
//
// Get two lines of string put from user (use getline(cin, s))
void getAString(string input) {
    cout << "Enter string value: ";
    getline(cin, input);

}

// External function: compareCounts();
// Use countLetters(), cleanUp inside the function
bool compareCounts(string thing1[26], thing2[26]) {

}