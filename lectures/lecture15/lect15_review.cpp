#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Bubble sort declaration (for strings)
void bubbleSort(string *array, int size);

// Structure data type
//      Note: structures can be declared AND initiaized at the same time
//      Note: we declare a structure outside of main to make its scope global
struct CDAccount {
    string full_name;   // First & last name
    double balance;     // Amount in US dollars in bank account savings
    double interestRate;    // Interest percentage rate as double
    int term;   // How many months until bank account reaches maturity
};
// CDAccount is the "tag" of the structure variable
//      Note: the "tag" is the structure's "data type"
// Member names = "identifiers" (declared inside braces)


// Another structure example
struct Date {
    int month;
    int day;
    int year;
};

// Node struct
struct linkNode {
    string item;
    int value;
    linkNode *link;
}

int main() {
    // Another variable of type CDAccount
    CDAccount accountX, accountY;

    // Use . to specify a member variable in a structure
    accountX.full_name = "Joanne Doe";
    accountX.balance = 1000.50;
    accountX.interestRate = 5.1;
    accountX.term = 12;

    // Set all member variables in accountX to be stored in corresponding values in accountY
    accountY = accountX;

    // Date declaration AND initialization
    Date babey_bday = {4, 26, 2026}, 
        bday = {2, 10, 2007};

    // Structure printing
    cout << "accountX is under: " << accountX.full_name
        << ". She has " << accountX.balance
        << " saved. "
        << "After " << accountX.term << " months she will have "
        << accountX.balance * (1 + accountX.interestRate/100) << " saved." << endl;
    cout << endl;

    // Structure in structures & more printing
    cout << babey_bday.month << endl;
    cout << babey_bday.day << endl;
    cout << babey_bday.year << endl;
    cout << endl;

    // Node variables
    linkNode x, y, z;
    
    x.item = "apple";

    y.item = "banana";

    z.item = "grape";

    
    return 0;
}

// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
// Helper function: bubble sort (adapted)
//      Note: for sorting last names in alphabetical order
void bubbleSort(string *array, int size) {
  bool swapped = true;
  int j = 0;
  string temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < size - j; i++) {
      if (tolower(array[i][0]) > tolower(array[i + 1][0])) {
          temp = array[i];
          array[i] = array[i + 1];
          array[i + 1] = temp;
          swapped = true;
      }
    }
  }
}