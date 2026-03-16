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
string d2b (string decimalStr) {
    // check if string input has only digit values
    for (int i = 0; i < decimalStr.size(); i++) {
        if (!(isdigit(decimalStr[i]))) {
            cerr << "invalid input, string must be digits only" << endl;
            exit(1);
        }
    }
    // convert decimalStr to int
    int dec = 0;
    for (int i = 0; i < decimalStr.size(); i++) {
        int digit = decimalStr[i] - '0';
        dec = (dec * 10) + digit;
    }
    if (dec == 0) {
        return "0";
    }
    string newVal = "";
    string digits = "0123456789";
    while (dec > 0) {
        newVal = digits[dec % 2] + newVal;
        dec /= 2;
    }
    cout << "binary value is: ";
    return newVal;
}
int b2d (string binString) {
    for (int i = 0; i < binString.size(); i++) {
        if ((binString[i] != '0') && (binString[i] != '1')) {
            cerr << "bad input. Must only contain 1s & 0s" << endl;
            exit(1);
        }
    }
    int dec = 0;
    int n = binString.size();
    int index = 0;
    // iterate backwards
    for (int i = n - 1; i >= 0; i--) {
        if (binString[i] == '1') {
            dec += pow(2, index);
        }
        index++;
    }
    cout << "decimal value is: ";
    return dec;
}
int seqSearch(int arr[], int size, int target) {
    int index(0);
    while (index < size) {
        if (arr[index] == target) {
            return index;
        } else {
            index++;
        }
    }
    return -1;
}
void bubbleSort(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (arr[j-1] > arr[j]) {
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void selectionSort(int arr[], int size) {
    int largestNum;
    int largestIndex;
    int tmp;
    for (int i = size -1; i >= 0; i--) {
        largestNum = arr[0];
        largestIndex = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] > largestNum) {
                largestNum = arr[j];
                largestIndex = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[largestIndex];
        arr[largestIndex] = tmp;
    }
}
// recursion
int factorial(int n) {
    // base case
    if (n == 1) {
        return n;
    }
    return n * factorial(n - 1);
}
void writeVert(int n) {
    // base case
    if (n < 10) {
        cout << n << endl;
    } else {
        writeVert(n / 10);
        cout << (n % 10) << endl;
    }
}
int formula(int n) {
    // base case
    if (n <= 1) {
        return 3;
    } else {
        return 2 * formula(n -1) + 5;
    }
}

// structs
    // linked lists
        struct listNode {
            string item;
            int count;
            listNode *link;
        };
        typedef listNode* listNodePtr;
        listNodePtr head;

// class declarations: 


    // member func declarations & definitions below: 

// class type templates
template<class T>
void swapVal(T& var1, T& var2) {
    T tmp;
    tmp = var1;
    var1 = var2;
    var2 = tmp;
}

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
    // vectors
        // vector declaration & initialization, .push_back()
            vector<int> count;
            int start = 5;
            for (int i = 0; i < 10; i++) {
                count.push_back(start);
                cout << count[i] << " ";
                start++;
            }
            cout << endl;
        // alternate initialization for vectors & size built in func
            vector<int> v(10);  // intializes first 10 elements to 0
            cout << "the size of vector v is: " << v.size() << endl;   // prints the total number of values in the vector
        // note: .reserve() is a built in mem func for vectors that reserves an int number for the capacity of a vector
    // b2d, d2h, d2b
        cout << "enter a decimal to be converted to binary: ";
        string dec;
        cin >> dec;
        cout << d2b(dec) << endl;
        
        cout << "enter a binary to be converted to decimal: ";
        string bin;
        cin >> bin;
        cout << b2d(bin) << endl;
    // ifstream & ofstream
        // ifstream
            ifstream inStream;
            inStream.open("input1.txt");
            char c1, c2, c3;
            inStream.get(c1);
            inStream.get(c2);
            inStream.get(c3);
            cout << c2 << endl;
        // ofstream
            ofstream outStream;
            inStream.close();
    // search algorithms
            int nums[5] = {1, 2, 3, 4, 5};
            int numsSize = 5;
            cout << seqSearch(nums, numsSize, 3) << endl;
        // bubbleSort
            int listing[5] = {20, 4, 8, 2, 5};
            int listingSize = 5;
            cout << "before bubbleSort: ";
            for (int i = 0; i < listingSize; i++) {
                cout << listing[i] << " ";
            }
            cout << endl;
            bubbleSort(listing, listingSize);
            cout << "after bubbleSort: ";
            for (int i = 0; i < listingSize; i++) {
                cout << listing[i] << " ";
            }
            cout << endl;
        // selectionSort
            int sort1[10] = {34, 21, 10, 32, 50, 3, 1, 30, 18, 25};
            int sort1Size = 10;
            cout << "before selection sort: ";
            for (int i = 0; i < sort1Size; i++) {
                cout << sort1[i] << " ";
            }
            cout << endl;
            selectionSort(sort1, sort1Size);
            cout << "after selectionSort: ";
            for (int i = 0; i < sort1Size; i++) {
                cout << sort1[i] << " ";
            }
            cout << endl;
    // recursion:
        // factorial recursive func
            int lol = 4;
            int fact = factorial(lol);
            cout << "the factorial of: " << lol << " is: " << fact << endl;
        // writeVertical
            int random = 54321;
            cout << random << " vertical is: " << endl;
            writeVert(random);
            cout << endl;
        // formula
            int four = 4;
            cout << "Element: " << four << " in the sequence is: " << formula(4) << endl;
    // linked lists
        listNode node1, node2, node3, node4;
        node1.item = "thing1"; node1.count = 1;
        node2.item = "thing2"; node2.count = 2;
        node3.item = "thing3"; node3.count = 3;
        node4.item = "thing4"; node4.count = 4;

        // link head to link of first node
        head = &node1;
        // link nodes to each other
        head->link = &node2;
        head->link->count = 5;
        head->link->link = &node3;
        head->link->link->link = &node4;
        // to end linked list, make last node link point to NULL or nullptr
        node4.link = nullptr;
        // print items & counts in linked list:
            listNodePtr tmp = head;
            cout << "printing the linked list: " << endl;
            while (tmp != NULL) {
                cout << tmp->item << " " << tmp->count << endl;
                tmp = tmp->link;
            }
    // type templates

    return 0;
}