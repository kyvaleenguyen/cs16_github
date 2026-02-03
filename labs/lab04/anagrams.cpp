#include <iostream>
#include <string>

using namespace std;

// MISSING FUNCTION DECLARATIONS HERE (you can remove these comments)

int main()
{
	// Get strings from user -- USE:   getline(cin, <string_variable>);
	string maybe_anagram1, maybe_anagram2;
	getline(cin, maybe_anagram1);
	getline(cin, maybe_anagram2);
	
	/* I found it easier to utilize the isalpha function in the book on page 393 and count
	all ascii characters to check if they are a letter since one of the parameters is that
	an anagram is true if both strings have the same exact characters and if one has a
	character like an apostrophe*/

	// create array for all 256 ascii characters initialized to 0
	int counts[256] = {0};

	// clean the first string and check for letters and characters
    for (int i = 0; i < maybe_anagram1.size(); i++) {
        if (isalpha(maybe_anagram1[i])) {
            counts[(unsigned char)tolower(maybe_anagram1[i])]++;
        }
    }

	// clean the second string and check for letters and characters
    for (int i = 0; i < maybe_anagram2.size(); i++) {
        if (isalpha(maybe_anagram2[i])) {
            counts[(unsigned char)tolower(maybe_anagram2[i])]--;
        }
    }

	// print if an anagram or not an anagram
    // if they are anagrams, all counts at index i must be 0
    for (int i = 0; i < 256; i++) {
        if (counts[i] != 0) {
            cout << "Not anagrams" << endl;
            return 0;
        }
    }
    cout << "Are anagrams" << endl;
    return 0;
}