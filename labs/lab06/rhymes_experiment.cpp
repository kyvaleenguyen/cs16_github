#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    string a = "hat cat bat mat rat";
    return 0;
}

// Pre-condition: String line must already be defined in file being opened. Function finds last word in string. 
// There MUST already be AT LEAST one word in the string. 
// Post-condition: The function returns the last word found in the string. If there are no spaces, the whole string is returned
//      Note: the string MUST be a string (no numbers??)
string findLastWord(string line){
    int words = 1;
    for (int i = 0; i < line.size()) {
        if (line[i] == " ") {
            words += 1;
        }
    }
    // Return last word in string line
    return line[words];
}
