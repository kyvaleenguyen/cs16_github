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

    return 0;
}

// Pre-condition: String line must already be defined in file being opened. Function finds last word in string. 
// There MUST already be AT LEAST one word in the string. 
// Post-condition: The function returns the last word found in the string. If there are no spaces, the whole string is returned
//      Note: the string MUST be a string (no numbers??)
string findLastWord(string line) {
    int words = 1;
    int start = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] = " " && i != 0) {
            words += 1;
        }
    }
    for (int i = 0; i < words; i++) {
        if (line[i] = " " && i != 0) {
            string word_list[i] = line.substr(start, i - start);
            start = i + 1;
            //word_list[i].append(line.substr(start, i - start));
        }
    }
    // Return last word in string line
    return word_list[words];
}