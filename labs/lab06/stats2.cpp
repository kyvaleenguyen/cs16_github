#include <fstream>
#include <iostream>
#include <string>
#include <iomanip> //required for set precision
#include <cmath> // for calculations

using namespace std;

// Function declarations
// NOTE: the 1st 4 function declarations are exactly the same as from lab04
// Functions from lab4
void bubbleSort(int *, int);
double findAverage(int *, int);
double findMedian(int *, int);
double findStdDev(int *, int, double);

// New functions
// Function to add multiple int values read from file
int arrayCount(const string& file_name) {
    // Create ifstream to read from file
    ifstream in_stream(file_name);
    if (!in_stream.is_open()) {
        return -1;
    }
    int count = 0;
    int int_val;
    while (in_stream >> int_val) {
        count++;
    }
    return count;
}

int main () {
    // Input & output streams, file name string declaration
    ifstream in_stream;
    string file_name;

    // Get file name from user and open ifstream
    cout << "Enter filename: ";
    getline(cin, file_name);
    in_stream.open(file_name);

    // If opening file fails
    if (!in_stream.is_open()) {
        cerr << "Cannot open " << file_name;
        exit(1);
    }

    // Organize data
    // Get total number of integers in file
    int total_ints = arrayCount(file_name);
    // Check if total_ints = 0 & file actually has integer values
    if (total_ints <= 0) {
        cerr << "Cannot open " << file_name;
        exit(1);
    }

    // Create dynamic array of size total_ints using new()
    int* newArray = new int[total_ints];

    // Creating appropriate variables for file
    // Populate dynaymic array by reading inputs from txt file
    for (int i = 0; i < total_ints; i++) {
        in_stream >> newArray[i];
    }
    // Close input file
    in_stream.close();
    
    // Set precision
    cout << fixed << showpoint;
    cout << setprecision(2);

    // Sort found data
    bubbleSort(newArray, total_ints);
    // Function calls to find average, median, & std_dev
    cout << "Here are some statistics:" << endl;
    // # of values in array
    cout << "      N: " << total_ints << endl;
    // average
    double avg = findAverage(newArray, total_ints);
    cout << "Average: " << avg << endl;
    // median
    double median = findMedian(newArray, total_ints);
    cout << " Median: " << median << endl;
    // std_dev
    double std_dev = findStdDev(newArray, total_ints, avg);
    cout << " StdDev: " << std_dev;

    // Delete dynamic array
    delete[] newArray;
    newArray = nullptr;

    return 0;
}

// Function Definitions
// NOTE: these function declarations are exactly the same as my function declarations from lab04. (bubbleSort which was given in lab04)
// :)

// BubbleSort function declaration
void bubbleSort(int *array, int size) {
  bool swapped = true;
  int j = 0;
  int temp;

  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < size - j; i++) {
      if (array[i] > array[i + 1]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
  }
}

// FindAverage function declaration
double findAverage(int *array, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum / size;
}

// FindMedian function declaration
double findMedian(int *array, int size) {
    if (size % 2 == 0) {
      // Average of middle two is average
      int mid1_index = size / 2 - 1;
      int mid2_index = size / 2;
      return (array[mid1_index] + array[mid2_index]) / 2.0;
    } else {
      // Middle one is average
      return static_cast<double>(array[size / 2]);
    }
}

// FindStdDev functiond declaration
double findStdDev(int *array, int size, double average) {
    double sum_of_squares = 0.0;
    for (int i = 0; i < size; i++) {
      // Pow() function from <cmath>
      sum_of_squares += pow(array[i] - average, 2);        
    }

    // Final standard deviation
    if (size == 1) {
      double std_dev = 0.0;
      return std_dev;
    }
    double std_dev = sqrt((1.0/(size - 1)) * sum_of_squares);
    return std_dev;
}