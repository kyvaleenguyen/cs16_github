// file: functions.cpp for newanagrams

// Define all member functions for class AString
//    as well as all other functions that need definition

// Accessor function
//
// Get the value of the original string member variables from the class

#include <iostream>
#include <string>
#include <cctype> // To use isalpha() & tolower()

using namespace std;

// Default onstructor
AString::AString() {
    StringValue = "";
}

// Non default constructor
AString::AString(string strVal) {
    StringValue = strVal;
}

// Member functions for AString class
// Pre-condition: 
// Post-condition: 
void AString::cleanUp() {
    string clean = "";
    for (char c : StringValue) {
        if (isalpha(c)) {
            clean += tolower(c);
        }
    }
    // Member variable StringValue is now the cleaned string (all lowercase)
    StringValue = clean;
}

// Accessor member function
//
// Get string value
//
// Pre-condition: 
// Post-condition: 
string AString::getStringValue() {
    return StringValue;
}

// Mutator member function
//
// Get string from user
//
// Pre-condition: 
// Post-condition: 
void AString::getAString() {
    cout << "Enter string value: ";
    getline(cin, StringValue);
}

// Mutator member function
//
// count # of letters found in both strings
//
// Pre-condition: 
// Post-condition: 
void AString::countLetters(int alphabet[26]) {
    // Check every lowercase alphabet ASCII character to add to count of letter found
    // Reset array for second count
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 0;
    }

    // Count letter frequency in sentence
    for (char c : StringValue) {
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a']++;
        }
    }
}

// External function: compareCounts();
//
// Use countLetters(), cleanUp inside the function
// Pre-condition: Takes two defined integer arrays defined in countLetters mutator member function and checks if all values in the array are equal
// Post-condition: Returns true if the two arrays are exactly equal for each value. Returns false otherwise
bool compareCounts(int count1[26], int count2[26]) {
    // Check every count in all 26 values of the array according to each letter in the alphabet
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            // Uh oh! Found a mismatch
            return false;
        }
    }
    // Did not find any mismatches
    return true;
}