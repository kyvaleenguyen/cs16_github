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
void swap (int &num1, int &num2) {
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
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
        // bunga
    // built in string member funcs
        string aSentence = "Today is a good day!";
        cout << aSentence << endl;
        cout << "The second letter 'a' in the sentence is at index: " << aSentence.find_first_of("a", 5) << endl;
    // chars & ASCII
        char aLetter = 97;
        cout << "The ASCII index 97 is: " << aLetter << endl;
    // mult-d arrays
        // mda test 1
            const int max1 = 10, max2 = 20;
            int arr[max1][max2] = {};
            cout << "a 10 * 20 array below:" << endl;
            // use nested for loops to go through mda's
                for (int i = 0; i < max1; i++) {
                    for (int j = 0; j < max2; j++) {
                        cout << "\t" << arr[i][j];
                    }
                    cout << endl;
            }
        // mda test 2
            double numbers[2][3] = { {6,7}, {8,9} };
            cout << "a 2 * 3 array below" << endl;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << "\t" << numbers[i][j];
                }
                cout << endl;
            }
    // pass by ref & pointers
        // void swap func call
            int first = 5;
            int second = 10;
            cout << "before swap: " << first << " " << second << endl;
            swap(first, second);
            cout << "after swap: " << first << " " << second << endl;
        // memory address * pointer
            int number = 42;
            int *numberPtr = &number;
            cout << "int pointer pointing to memory address of number is: " << numberPtr << endl;
            cout << "int pointer pointing to the value of number equals number: " << *numberPtr << endl;
        // new operator (new variables are stored in heap memory)
            int *p1 = new int;
            cin >> *p1;
            *p1 = *p1 + 7;
            cout << "p1 points to the value stored in a new int variable: " << *p1 << endl;
            // delete the dynamic variable
                delete p1;
        // pointer to a pointer example
            int day = 1;
            int *ptr = &day;
            int **pptr = &ptr;
            cout << "pointer to a pointer for var day (1): " << pptr << endl;
    // range based for loops
        int evens[4] = {2, 4, 6, 8};
        cout << "Iterating through an array using a range based for loop:" << endl;
        for (int item : evens) {
            cout << item << " ";
        }
        cout << endl;
    // 
    return 0;
}