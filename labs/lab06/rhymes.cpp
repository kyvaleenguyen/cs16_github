// Include statements go here...
#include <fstream>

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
    ifstream input_stream;
    ofstream output_stream;
    string file_name;

    // Get file name from user and open file
    input_stream << getline(cin, file_name);
    input_stream.open(file_name);

    // If opening file fails
    if (in.fail()) {
        cerr << "Input file opening failed." << endl; 
        exit(1); 
    }

    // Read the lines in your file and check on rhyming, per our definition
    input_stream << 

    // Finally, print the results (see lab descriptions for examples)
    // output_stream << 
    

    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!

// Pre-condition: String line must already be defined in file being opened. Function finds last word in string. 
// There MUST already be AT LEAST one word in the string. 
// Post-condition: The function returns the last word found in the string. If there are no spaces, the whole string is returned
//      Note: the string MUST be a string (no numbers??)
string findLastWord(string line){
    int words = 1;
    int start = 0;
    for (int i = 0; i < line.size()) {
        if (line[i] == " " && i != 0) {
            words += 1;
        }
    }
    string word_list[words] = {};
    for (int i = 0; i < words; i++) {
        if ((line[i] == " ") && (i != 0)) {
            word_list[i] = line.substr(start, i - start);
        }
    }
    // Return last word in string line
    return word_list[words];
}


// Pre-condition: 
// Post-condition: 
void cleanUp(string &word) {

}


// Pre-condition: 
// Post-condition: 
bool compareWords(string word1, string word2) {

}

