// file: headers.h for newanagrams

// Define class AString here!
// See PDF for details

#include <string>

using namespace std;

class AString {
    public:
        AString();  // Default constructor
        AString(string strVal);     // Non default constructor
        string getStringValue();    // Accessor function
        void cleanUp();  // Mutator
        void countLetters(int alphabet[26]);    // Mutator
        void getAString();  // Mutator
    private:
        string StringValue; // Member variable

};

// DO NOTE CHANGE THESE AND DO NOT ADD TO THEM!
bool compareCounts(int a[], int b[]);
const int ARRAYSIZE = 26;