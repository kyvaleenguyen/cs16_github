#include <iostream>
#include <iomanip> // Required for setw, setprecision
#include <cmath>   // Required for pow

using namespace std;

// Function declarations
void bubbleSort(int *, int);
double findAverage(int *, int);
double findMedian(int *, int);
double findStdDev(int *, int, double);

int main() {
  // Set precision
  cout << fixed << showpoint;
  cout << setprecision(2);

  // Get user input for grade amount
  cout << "Enter number of grades: ";
  int grade_amount;
  cin >> grade_amount;
  if (grade_amount < 1) {
    cerr << "Error!" << endl;
    exit(1);
  }
  
  // Dynamic array
  int *grades_list = new int[grade_amount];

  // Get input for grades
  cout << "Enter grades (each on a new line):" << endl;
  for (int i = 0; i < grade_amount; i++) {
    cin >> grades_list[i];
  }

  // Sort array
  bubbleSort(grades_list, grade_amount);

  // Function calls
  double average = findAverage(grades_list, grade_amount);
  double median = findMedian(grades_list, grade_amount);
  double stddev = findStdDev(grades_list, grade_amount, average);

  // Print statistics (formatted)
  cout << "Here are some statistics:" << endl;
  cout << setw(9) << "Average: " << average << endl;
  cout << setw(9) << "Median: " << median << endl;
  cout << setw(9) << "StdDev: " << stddev << endl;

  // Eliminate dynamic array
  delete[] grades_list;
  grades_list = nullptr;

  return 0;
}

// Function Definitions
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

// Add all values in array and divide by number of values in array
double findAverage(int *array, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum / size;
}

// Find middle value in sorted array
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

// Find standard deviation using provided stddev formula
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
