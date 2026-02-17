#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string findLastWord(string line);

int main () {
    string a = "hat cat bat mat rat";

    cout << "words list: ";
    string words[3] = {"a", "b", "c"};
    cout << words << endl;
    cout << "wordle: ";
    string wordle[] = {"h", "i", "j"};
    cout << wordle << endl;
    int wordle_size = sizeof(wordle) / sizeof(wordle[0]);
    for (int i = 0; i < wordle_size; i++) {
        cout << wordle[i] << endl;
    }

    // findLastWord function call test
    string bunga;
    findLastWord(bunga);

    return 0;
}

// Pre-condition: String line must already be defined in file being opened. Function finds last word in string. 
// There MUST already be AT LEAST one word in the string. 
// Post-condition: The function returns the last word found in the string. If there are no spaces, the whole string is returned
//      Note: the string MUST be a string (no numbers??)
/*string findLastWord(string line) {
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
            }
        }
    }
    return last_word;
    }*/

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
            }
        }

    }
}