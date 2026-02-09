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
    // Perform the conversion by calling the appropriate function
    // What happens next?!!?

    // Ensure command line arguments are being called correctly. <options: d2b, d2h, b2d>
    // If command line input != decimal to hexadecimal conversion, decimal to binary conversion, binary to decimal end program
    if ((argv[1] != "d2b") || (argv[1] != "b2d") || (argv[1] != "d2h")) {
        exit(1);
    }

    // Argv convresions
    string converter = argv[1];
    string value = argv[2];

    // If user enters inputs correctly. argv[2] should equal the string being converted
    // argv command line format is: <file_path/executable_file> <converter> <value>

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

// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!

// Decimal to binary & hexadecimal
string dec2bh(string sdec, char bh) {
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

// Example: 1101100 (108 in base 10)
// Binary to decimal
int bin2d(string binstring) {
    string bin_string = "1101100";
    int decimal = 0;
    int n = bin_string.size();

    for (int i = 0; i < n; i++) {
        if (bin_string[i] == '1') {
            // Do necessary conversion. Base is 2 for decimal & power is the index from the right
            decimal += pow(2, n - 1 - i);
        }
    }
    return decimal;
}