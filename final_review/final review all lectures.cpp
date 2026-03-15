#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <iomanip>

using namespace std;

// func declarations & definitions below: 
void evenOrOdd(int num) {
    if (num % 2 == 0) {
        cout << num << " is even!" << endl;
    } else {
        cout << num << " is odd!" << endl;
    }
}

// class declarations: 


// member func declarations & definitions below: 



int main() {
    // for loops:
        int anArray[5] = {1, 2, 3, 4, 5};
        int size = 5;
        // forward iteration setup
            cout << "forwards for loop iteration: ";
            for (int i = 0; i < size; i++) {
                cout << anArray[i] << " ";
            }
            cout << endl;
        // backward iteration setup
            cout << "backwards for loop iteration: ";
            for (int i = size - 1; i >= 0; i--) {
                cout << anArray[i] << " ";
            }
            cout << endl;
    // while & do while loops:
        // while loop:
            int aNumber = 10;
            cout << "while loop countdown: ";
            while (aNumber > 0) {
                cout << aNumber << " ";
                aNumber--;
            }
            cout << endl;
        // do while loop:
            int number2 = 5;
            cout << "do while loop countdown: ";
            do {
                cout << number2 << " ";
                number2--;
            } while (number2 > 0);
            cout << endl;
    // nested loop (loop in a loop :0)
        int bees = 10;
        cout << "bee count:" << endl;
        if (bees >= 10) {
            for (bees; bees > 0; bees--) {
                if (bees % 2 == 0) {
                    cout << "\teven: " << bees << endl;
                } else {
                    cout << "\todd: " << bees << endl;
                }
            }
        } else {
            cout << "total number of bees must be greater than 10" << endl;
        }
        cout << endl;
    // switch statement:
        // note: all cases in a switch have to have break at the end EXCEPT the default
        // the switch's parameters must be either:
            // int
            // char
            // bool
            
            // strings & float types WILL NOT work in the parameters for switches
        cout << "switch time! enter a # (1-3): ";
        int inputNum;
        cin >> inputNum;
        switch (inputNum) {
            case 1:
                cout << "You entered: " << inputNum << ". Small!" << endl;
                break;
            case 2: 
                cout << "You entered: " << inputNum << ". Medium!" << endl;
                break;
            case 3: 
                cout << "You entered: " << inputNum << ". Large!" << endl;
                break;
            default:
                cout << "Sorry, that size is invalid!" << endl;
        }
    // funcs:
        // void evenOrOdd:
            evenOrOdd(5);
        // 


    return 0;
}