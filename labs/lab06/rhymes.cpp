#include <fstream>
#include <iostream>
#include <string>
#include <iomanip> //required for set precision

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
    string file_name, line1, line2;

    // Get file name from user and open ifstream
    cout << "Enter filename: ";
    getline(cin, file_name);
    in_stream.open(file_name);

    // If opening file fails
    if (!in_stream.is_open()) {
        cerr << "Cannot open " << file_name;
        exit(1);
    }

    // Read the lines in your file and check on rhyming, per our definition
    // Create count of rhymes found
    int rhymesFound = 0;

    // Open out_stream & print get file name line
    out_stream.open("rhymes_results.txt");
    out_stream << "Enter filename: " << file_name << endl;

    // Create count of lines found in poem
    int lines = 0;

    while((getline(in_stream, line1)) && (getline(in_stream, line2))) {
        // Count lines in poem
        lines += 2;

        // Get last word from both lines
        string word1 = findLastWord(line1);
        string word2 = findLastWord(line2);

        // Clean last word from both lines (set all letters to lowercase & remove any non-letter characters in both strings)
        cleanUp(word1);
        cleanUp(word2);

        // Check if both words rhyme
        if (compareWords(word1, word2)) {
            // Create count of rhymes found
            rhymesFound++;

            // Print rhyme found
            out_stream << word1 << " and " << word2 << endl;
        } else {
            continue;
        }
    }

    // Calculate rhyme density
    // Set double precision of rhyme density
    out_stream << fixed << showpoint;
    out_stream << setprecision(2);

    double rhymeDensity = (double)rhymesFound / lines;


    // Close in_stream
    in_stream.close();

    // Check if there are no rhymes & print appropriate statement if no rhymes found in out_stream
    if (rhymesFound == 0) {
        out_stream << "No rhymes found." << endl;
    }

    // Dont print rhymeDensity if no rhymes
    // Print rhymeDensity if rhyme(s) found
    if (rhymesFound < 0) {
        out_stream << "There are " << lines << " lines in this poem.";
    }
    if (rhymesFound > 0) {
        out_stream << "There are " << lines << " lines in this poem";
        out_stream << ", so the rhyme-line density is: " << rhymeDensity;
    }

    // Close out_stream
    out_stream.close();
    return 0;
}

// Pre-condition: String line must already exist for function to work. Function finds last word in string. 
// Post-condition: The function returns the last word found in the string. If there are no spaces, the whole string is returned
//      Note: the string MUST be a variable of string type already defined
string findLastWord(string line) {
    // Last word string
    string last_word;

    // Check if line is empty
    if (line.empty()) {
        return "";
    }

    // Find position of last space in line
    int lastSpace = line.rfind(" ");

    // Check if there is a last space. If not, the whole line is the word
    if (lastSpace == string::npos) {
        return line;
    }
    
    // Get substr of last word
    string lastWord = line.substr(lastSpace + 1);
    return lastWord;
}


// Pre-condition: The string word must already exist and be defined as a string type variable upon function call
// Post-condition: Lowers capitalization for all words & removes non-letter characters within the string
void cleanUp(string &word) {
    // Create string variable to store cleaned string
    string cleanString = "";

    // Remove non-letter characters & lower letter characters in string
    for (char c : word) {
        // Check if character is a letter
        if(isalpha(c)) {
            cleanString += tolower(c);
        }
    }
    // Assign cleaned string to word reference
    word = cleanString;
}


// Pre-condition: There must ONLY be 2 words that are compared with each other. They must BOTH be strings
// Post-condition: Compares both words & checks if they rhyme (must have 2 consecutive letters that are the same in both words at the end of the word)
bool compareWords(string word1, string word2) {
    // Check if both words have greater than 2 letters
    int length1 = word1.length();
    int length2 = word2.length();
    if ((length1 < 2) || (length2 < 2)) {
        return false;
    }
    // Check last 2 letters of both strings being compared
    string comparison1;
    string comparison2;
    comparison1 = word1.substr(word1.length() - 2);
    comparison2 = word2.substr(word2.length() - 2);
    if (comparison1 == comparison2) {
        return true;
    } else {
        return false;
    }
}