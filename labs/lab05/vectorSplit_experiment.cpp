#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function declaration
vector<string> split(string target, string delimiter);


int main () {
    // Experimental vector<int> (and other vectors)
    vector<int> integers;
    int vector_size;
    cin >> vector_size;
    for (int i = 0; i < vector_size; i++) {
        integers.push_back(i+1);
        cout << integers[i];
    }
    return 0;
}