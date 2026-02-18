#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
vector<int> SeqSearchAll (int target, ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    // If opening file fails
    if (!ifs.is_open()) {
        cerr << "Cannot open " << fname;
        exit(1);
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> returned = SeqSearchAll (target, ifs);
    ifs.close();

    if (returned[0] == -1)
        cout << "Target not found!\n";
    else {
        cout << "Target found at position(s): ";
        for (int i = 0; i < returned.size(); i++) {
            cout << returned[i] - 1 << " ";
        } // for
        cout << endl;
    } // else
    return 0;
}

// DEFINE FUNCTION HERE. 
// Include Pre-Condition and Post-Condition comments.
vector<int> SeqSearchAll (int target, ifstream &ifs) {
    // Create int vector to store target indexes that are found
    vector<int> targetIndexes;

    // Create int values to increment throughout file
    int index = 0;
    int next;

    // While loop to increment
    while (ifs >> next) {
        index++;
        if(next == target) {
            targetIndexes.push_back(index);
        }
    }
    return targetIndexes;
}