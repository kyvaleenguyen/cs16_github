#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[])
{
    cout << "There are " << argc << " arguments here:" << endl;
    cout << "Let’s print out all the arguments:" << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] is : " << argv[i] << endl;
    }

    string words = "HELLO";
    for (int i=0; i < words.size(); i++) {
        char letter = tolower(words[i]);
        cout << letter << endl;
    }

    string a = "Rats and Mice";
    string b = "in cat's dream";
    cout << a.size() << endl;
    cout << b.size() << endl;

    
   return 0;
}

