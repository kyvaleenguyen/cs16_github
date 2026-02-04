#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);

int main() {
    // Get target string from user, get delimiter string from user
    // Call function split()
    // What happens next?!!?
    /*string a = "bun's";
    string delim = "'";
    split(a, delim);*/


    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)

vector<string> split(string target, string delimiter) {
    // Function definition

    // Get string from user
    cout << "Enter string to split:" << endl;
    getline(cin, target);

    // Enter string delimiter
    cout << "Enter delimiter string" << endl;
    getline(cin, delimiter);
    if (delimiter.size() > 1) {
        exit(1);
    }

    // Form substrings
    vector<string> sample;
    for (int i = 0; i < target.size(); i++) {
        if (target.find(delimiter)) {
            vector<int> delimiter_indexes[i] = i;
        }


        if (target[i] == target.find(delimiter, i)) {
            sample.push_back(target.substr(i, -((size-1)-i)));
        }
    }

    // Print substrings
    cout << "The substrings are:" << endl;

    return sample;
}