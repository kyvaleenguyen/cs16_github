#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.

// Binary to decimal
int bin2d(string binstring);

// Decimal to binary & hexadecimal
string dec2bh(string sdec, char bh);


// The parameters within int main prompt the user to enter command line arguments
int main ( int argc, char *argv[] ) {
    // Check to see if the command-line arguments are being used correctly
    // If there are not 3 arguments being used in the command line, exit the program
    if (argc != 3) {
        return 1;
    }

    // Argv convresions
    string converter = argv[1];
    string value = argv[2];

    // If converter != "d2b" "b2d" "d2h" end program
    if ((converter != "d2b") && (converter != "b2d") && (converter != "d2h")) {
        exit(1);
    }

    // If converter = "d2b" or "d2h" & value != an integer end program
    for (int i = 0; i < value.size(); i++) {
        // If character is not between 0 and 9, not a valid decimal
        if ((value[i] < '0') || (value[i] > '9')) {
            exit(1); 
        }
    }


    // If user enters inputs correctly. argv[2] should equal the string being converted
    // Argv command line format is: <file_path/executable_file> <converter> <value>
    if (converter == "b2d") {
        // Binary to decimal
        cout << bin2d(value) << endl;
    } else if (converter == "d2b") {
        // Decimal to binary
        cout << dec2bh(value, 'b') << endl;
    } else if (converter == "d2h") {
        // Decimal to hexadecimal
        cout << dec2bh(value, 'h') << endl;
    } else {
        // End program
        exit(1);
    }

    return 0;
}

// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!

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
            base = 2;
            break;
        // If bh = 'h'
        case 'h': 
            base = 16;
            break;
        // If bh is not 'b' or 'h'
        default: 
            return "Invalid base";
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
    return decimal;
}