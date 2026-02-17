#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 3 functions below.
// See lab description for more on these functions.

string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {
    // Create input stream object, then get a filename from user (check it too)
    ifstream in_stream;
    ofstream out_stream;
    string file_name;

    // Get file name from user and open ifstream
    cout << "Enter file name: ";
    getline(cin, file_name);
    in_stream.open(file_name);

    // Get lines from input file
    // in_stream >> 

    // Open ofstream & print get file name line
    out_stream.open("rhymes_results.txt");
    out_stream << "Enter file name: " << file_name << endl;

    // If opening file fails
    if (!in_stream.is_open()) {
        out_stream << "Cannot open " << file_name;
        return 0;
    }

    // Read the lines in your file and check on rhyming, per our definition
    in_stream >> findLastWord(file_name);

    // Finally, print the results (see lab descriptions for examples)
    // output_stream << 
    

    // Close in_stream & out_stream
    in_stream.close();
    out_stream.close();
    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!

// Pre-condition: String line must already be defined in file being opened. Function finds last word in string. 
// There MUST already be AT LEAST one word in the string. 
// Post-condition: The function returns the last word found in the string. If there are no spaces, the whole string is returned
//      Note: the string MUST be a string (no numbers??)
string findLastWord(string line) {
    // Create ifstream to read lines from
    ifstream in_stream;
    string last_word;
    // Iterate through each line in the file
    while (getline(in_stream, line)) {
        // Iterate in reverse through each character in the line until a space is found
        for (int i = line.length(); i > 0; i--) {
            // If a space is found in the line, make sure that it is not at the beginning or end of the line because it can't be counted as a word
            if ((line.find(" ")) && (line.find(" ") < line.length()) && (line.find(" ") > 0)) {
                // Take substring of line and assign it to the last_word string
                last_word = line.substr(i, line.length() - i);
                return last_word;
            }
        }
    }
}


// Pre-condition: 
// Post-condition: 
void cleanUp(string &word) {

}


// Pre-condition: 
// Post-condition: 
bool compareWords(string word1, string word2) {
    string comparison;
    return true;
}