// IMPORTANT NOTE TO USER: 
// The only parts of the program that you should change are:
// 1. The function definitions that are currently on lines 30-32.
// 2. The addition of more test cases in the main() function.
// PLEASE LEAVE ALL OTHER CODE (especially the ASSERT_EQUAL() functions) AS-IS!
//
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <string>
#include <vector>
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)

using namespace std;

// FYI, templates are a way to make a variable type "flexible".
// We'll cover these at some point, but for now just leave these alone.
template <typename T>
void ASSERT_EQUAL(T, T);

template <typename T>
void ASSERT_EQUAL(const vector<T>&, const vector<T>&);

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE IN THE TESTS (do not remove):
vector<string> split(string target, string delimiter);
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

// FUNCTION DEFINITIONS

// Split function definition
vector<string> split(string target, string delimiter) {
    // Variable declarations
    vector<string> substrings;
    string word;

    // Print substrings
    // If no substrings
    if (target.find(delimiter) == string::npos) {
        cerr << "No substrings.";
    }

    // If there are substrings
    if (target.find(delimiter) != string::npos) {
        // Create substrings vector and word string to store substrings in and add to substrings vector
        // Control size of substrings vector to save memory
        substrings.reserve(target.size());
        // Integer to set start of target index for substrings to 0
        int start = 0;
        for (int i = 0; i < target.size(); i++) {
            // If delimiter found at index i in target and if the substr size is greater than 0
            if ((target[i] == delimiter[0]) && ((i-start)>=0)) {
                // If the word found is not an empty string, add it to the substrings vector
                word = target.substr(start, i - start);
                if (word != "") {
                    // Insert comma after word found
                    substrings.push_back(word);
                }
                // Change start index if delimiter found
                start = i + 1;
            }
        }
        // Get last substring after last delimiter & make sure the last word found isn't an empty string
        if (start < target.size()) {
            string last_substr = target.substr(start);
            if (word != "") {
               string formatted_substr = last_substr;
               substrings.push_back(formatted_substr); 
            }
        }
            cout << "The substrings are: ";

    }
    // Organize substrings with proper formatting and print statement, then return substrings
    for (int i=0; i < substrings.size(); i++) {
        cout << substrings[i];
    }
    return substrings;
}

// Pre-condition: user MUST enter 'd2b' or 'd2h' and then proper decimal string into command line
// Post-condition: the value converted from a decimal to binary or decimal to hexadecimal value will be printed
// Decimal to binary & hexadecimal
string dec2bh(string sdec, char bh) {
    // Check if proper decimal integer was entered. If not, exit program
    string digits = "0123456789";
    for (int i = 0; i < sdec.size(); i++) {
        // Exit if any character is not a digit
        if (sdec[i] < '0' || sdec[i] > '9') {
            exit(1);
        }
    }

    // Convert decimal string to int
    int decimal = 0;
    for (int i = 0; i < sdec.size(); i++) {
        int digit = sdec[i] - '0';
        decimal = (decimal * 10) + digit;
    }
    // Check if decimal is already 0
    if (decimal == 0) {
        return "0";
    }

    // Declaring base int to get ready for binary or hexadecimal conversion
    int base;

    // Switch case for binary & hexadecimal conversions
    switch (bh) {
        //if bh = 'b'
        case 'b': 
            cout << "The value in binary is: ";
            base = 2;
            break;
        // If bh = 'h'
        case 'h': 
            cout << "The value in hexadecimal is: ";
            base = 16;
            break;
        // If bh is not 'b' or 'h'
        default: 
            return "Wrong base";
    }

    // Conversion time
    string new_value = "";
    string hex_digits = "0123456789ABCDEF";

    while (decimal > 0) {
        new_value = hex_digits[decimal % base] + new_value;
        decimal /= base;
    }
    // Return new value
    return new_value;
}

//Pre-condition: user MUST enter 'b2d' and then proper binary string into command line. String entered MUST be only 1s or 0s.
// Post-condition: the value converted from a binary to decimal value will be printed
// Binary to decimal
int bin2d(string binstring) {
    // Check if binstring does not have 0 or 1 binary characters. If any character other than 0 or 1 present, exit program
    for (int i = 0; i < binstring.size(); i++) {
        if ((binstring[i] != '0') && (binstring[i] != '1')) {
            cerr << "Binary value contains non-binary digits.";
            exit(1);
        }
    }

    // Creating decimal integer to prepare for conversion from binary to decimal. The converted values will be stored in decimal
    int decimal = 0;
    int n = binstring.size();

    for (int i = 0; i < n; i++) {
        if (binstring[i] == '1') {
            // Do necessary conversion. Base is 2 for decimal & power is the index from the right
            decimal += pow(2, n - 1 - i);
        }
    }
    // Print new value
    cout << "The value in decimal is: ";
    return decimal;
}


int main() {
    cout << "Testing split..." << endl;    
    vector<string> answer;

    // Testing split function
    answer = {"Apples", "Bananas", "Cherries", "Dragon Fruits", "Elderberries"};
    ASSERT_EQUAL(answer, split("Apples,Bananas,Cherries,Dragon Fruits,Elderberries", ","));

    answer = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    ASSERT_EQUAL(answer, split("The quick brown fox jumps over the lazy dog", " "));

    answer = {"It w", "s r", "re, I w", "s there."};
    ASSERT_EQUAL(answer, split("It was rare, I was there.", "a"));

    answer = {"Can you hear me?", " - The Machine"};
    ASSERT_EQUAL(answer, split("\"Can you hear me?\" - The Machine", "\""));


    // Feel free to add additional test cases and edge cases
    // answer = {}
    // ASSERT_EQUAL(answer, split("", ""));


    cout << endl << "Testing bin2d..." << endl;
    // Testing binary to decimal
    ASSERT_EQUAL(0, bin2d("0"));
    ASSERT_EQUAL(2, bin2d("10"));
    ASSERT_EQUAL(9,bin2d("1001"));
    ASSERT_EQUAL(45,bin2d("101101"));
    ASSERT_EQUAL(246, bin2d("11110110"));

    cout << "Testing dec2hb..." << endl;
    // Testing decimal to binary
    ASSERT_EQUAL(string("1010"), dec2bh("10", 'b'));
    ASSERT_EQUAL(string("1111"), dec2bh("15", 'b'));
    ASSERT_EQUAL(string("1100100"), dec2bh("100", 'b'));

    // Testing decimal to hex conversion
    ASSERT_EQUAL(string("A"), dec2bh("10", 'h'));
    ASSERT_EQUAL(string("64"), dec2bh("100", 'h')); 

    // Feel free to add additional test cases and edge cases
    // ASSERT_EQUAL(string("64"), dec2bh("100", 'h')); 


    return 0;
}


// Template function to compare expected and actual values.
// If the values match, it prints a "PASSED" message; otherwise, a "FAILED" message.
template <typename T>
void ASSERT_EQUAL(T expected, T actual) {
    if (expected == actual) {
        cout << "PASSED: Expected and actual values are equal: " << expected << endl;
    } else {
        cout << "FAILED: Expected " << expected << " but got " << actual << endl;
    }
}

template <typename T>
void ASSERT_EQUAL(const vector<T>& expectation, const vector<T>& actuality) {
    T expect;
    T actual;
    if (expectation.size() != actuality.size()) {
	    cout << "FAILED: Expected vector of size " << expectation.size() << " but got " << actuality.size() << endl;
	    return;
    }
    for (size_t i = 0; i < min(expectation.size(), actuality.size()); i++) {
	    expect = expectation[i];
	    actual = actuality[i];
    	if (expect == actual) continue;
        cout << "FAILED: With index=" << i << ", Expected " << endl << "\t\"" << expect << "\"\n" << "\tbut got " << endl << "\t\"" << actual << "\"\n";
	    return;
    }

    cout << "PASSED: Expected and actual values are equal:";
    for (const T& expect: expectation) cout << endl << "\t" << expect;
    cout << endl << endl;    
}

