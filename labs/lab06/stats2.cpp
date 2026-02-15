#include <fstream>
#include <iostream>
#include <iomanip> //required for set precision
#include <cmath> // required for pow() (pow is the only function usable from cmath)

using namespace std;

// Function declarations
// NOTE: these function declarations are exactly the same as from lab04
void bubbleSort(int *, int);
double findAverage(int *, int);
double findMedian(int *, int);
double findStdDev(int *, int, double);

int main () {
    // Set precision
    cout << fixed << showpoint;
    cout << setprecision(2);

    // Input & output streams
    ifstream in_stream;
    ofstream out_stream;

    // Get file name from user and open file
    in_stream << getline(cin, file_name);
    in_stream.open(file_name);

    // If opening file fails
    if (in.fail()) {
        cerr << "Cannot open " << file_name << endl; 
        exit(1); 
    }


    return 0;
}

// Function Definitions
// NOTE: these function declarations are exactly the same as my function declarations from lab04. (Except for bubbleSort which was given to us in lab04)
// :)

// bubbleSort function declaration
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

// findAverage function declaration
double findAverage(int *array, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum / size;
}

// findMedian function declaration
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

// findStdDev functiond declaration
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