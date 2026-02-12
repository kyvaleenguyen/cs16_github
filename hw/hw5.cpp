#include <iostream>
#include <string>
#include <vector>

using namespace std;

// #3
vector<int> swapFrontBack(vector<int> numbers) {
    // Swap 1st & last elements
    if (numbers.size() > 1) {
        int a = numbers.front();
        numbers.front() = numbers.back();
        numbers.back() = a;
    } else {
        cerr << "Empty vector!";
    }
    return numbers;
}

// #4
int countOddNumbers(vector<int> *ref) {
    vector<int> odd_nums;
    for (int i = 0; i < ref->size(); i++) {
        if ((*ref)[i] % 2 != 0) {
            odd_nums.push_back((*ref)[i]);
        }
    }
    return odd_nums.size();
}

int main () {
    // #1
    /*cout << "#1" << endl;
    // code version 1
    string name;
    cout << "Enter name: ";
    cin >> name;
    cout << name;
    cout << endl;
    cin.ignore(1000, '\n');*/
    /* Predicted output: prints out "Enter name: ", then prompts user to enter string name as input, and prints the name after
    The output should look like: 
    "Enter name: <name>. 
    <name>" 
    Note: This version CANNOT get a name with a surname, maiden name, and 1st if the user tries to enter multiple strings 
    separated by spaces, the string stored in name only is the 1st*/

    // code version 2 (can get a full name of a person because getline gets input until the user presses enter)
    /*string name2;
    cout << "Enter name: ";
    getline(cin, name2);
    cout << name2;*/

    // #2
    /* Write a program that asks the user to input an integer named numDoubles. Then create a dynamic array that can store 
    numDoubles values of type double and have a loop that allows the user to enter a double value into each array entry. 
    Then, your program should loop through the array, calculate the average of all the values in it, and then print out that 
    average. Delete the memory allocated to your dynamic array properly before exiting. It’s a good idea to implement this as 
    real code and see if it works correctly*/
    // Variable declaration
    int numDoubles;
    double sum = 0;
    // Get user input for number of values to be stored in array
    cout << "Enter array size: ";
    cin >> numDoubles;
    // Dynamic array
    double *num_list = new double[numDoubles];
    // Get input for grades
    cout << "Enter doubles (each on a new line):" << endl;
    for (int i = 0; i < numDoubles; i++) {
        cin >> num_list[i];
        sum += num_list[i];
    }
    // Calculate average
    double average = sum/numDoubles;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

      // Eliminate dynamic array
    delete[] num_list;
    num_list = nullptr;

    // #3
    /*Write (define) a function called swapFrontBack() that takes as input argument a vector of integers . The function 
    should swap the first element in the vector with the last element in the vector and return that new vector. The function 
    should check if the vector is empty to prevent errors. It’s a good idea to implement this as real code and see if it 
    works correctly*/
    // Variable declarations
    vector<int> numbers;
    int vector_size = 0;
    int num;
    // Get size of vector
    cout << "Enter size of vector: ";
    cin >> vector_size;
    cout << "Enter values for each space in vector: ";
    for (int i = 0; i < vector_size; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    numbers = swapFrontBack(numbers);

    // After swap print to confirm it was successful
    cout << "After swap: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // #4
    /*Write (define) a function named countOddNumbers() that takes a reference to a vector of integers as input. 
    The function should return the total number of odd numbers contained in the vector. Write (define) a test function that 
    calls this countOddNumbers() function in order to test it with 3 different vectors of different length: 
        1 vector must contain multiple elements whose values are only odd numbers, 
        1 vector must contain multiple elements whose values are  only even numbers, and 
        1 vector must be an empty vector. The tester should compare what the function actually returns versus what the 
        expected correct answer should be. Use this approach when writing this test function*/

    // First vector
    vector<int> list_a = {1, 3, 5, 7, 9};
    vector<int> *a = &list_a;
    if (countOddNumbers(a) == 5) {
        cout << "Passed the test." << endl;
    } else {
        cout << "Failed the test." << endl;
    }
    // Second vector
    vector<int> list_b = {1, 3, 5, 7, 9};
    vector<int> *b = &list_b;
    if (countOddNumbers(b) == 5) {
        cout << "Passed the test." << endl;
    } else {
        cout << "Failed the test." << endl;
    }
    // Third vector
    vector<int> list_c = {1, 3, 5, 7, 9};
    vector<int> *c = &list_c;
    if (countOddNumbers(c) == 5) {
        cout << "Passed the test." << endl;
    } else {
        cout << "Failed the test." << endl;
    }

    // #5
    // f

    return 0;
}