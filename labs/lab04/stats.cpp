#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

int avr = 0;
int sum = 0;
// average of array
double average(int *array, int size) {
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  avr = sum / 2;
  cout << "Average = " << avr << endl;
  return 0;
}

int med = 0;
// median of array
double median(int* array, int size) {
  if (size % 2 == 0) {
    med = array[size / 2];
  } else {
    med = array[(size / 2) + 1];
  }
  cout << "Median = " << med << endl;
  return 0;
}

// standard deviation of array
double size_ratio = 0.0;
double stddev(int* array, int size) {
  size_ratio = 1.0/(size - 1.0);
  double sqr_dif_sums = 0.0;
  for (int i = 0; i < size; i++) {
      sqr_dif_sums += pow(array[i] - avr, 2);
  }
  double std_dev = size_ratio * sqr_dif_sums;

  // Trace size
  cout << "size = " << size - 1 << endl;

  // Trace sqr dif sums
  cout << "sqr_dif_sums = " << sqr_dif_sums << endl;

  // Trace size_ratio
  cout << "size_ratio = " << size_ratio << endl;

  cout << "Standard Deviation = " << std_dev << endl;
  return 0;
}

int main() {
  // Sets the printing of floating-point numbers
  // to show only 2 places after the decimal point
  cout << fixed << showpoint;
  cout << setprecision(2);

  // MISSING CODE HERE (you can remove these comments)
// Get the number of grades to be entered from user
  // Create a dynamic int array based on this information
  // Get the user to enter all the grades
  // Print results while calling the appropriate functions
cout << "Enter number of grades : ";
int grade_amount;
cin >> grade_amount;
cout << "Enter grades (each on a new line)" << endl;
int size = grade_amount;
for (int i = 0; i < size; i++) {
  int grade;
  cin >> grade;
  int grades[] =+ grade;
  cout << grades;
}

  // Test case: print grade_list array

  // Test case
  int numbers[] = {5, 9, 8, 11, 35, 22, 30, 19, 40};
  int nl_size = 10;

  //Trace avr var
  cout << "Avr var is equal to: " << avr << endl;
  // average of array
  average(numbers, nl_size);

  // median of array
  median(numbers, nl_size);

  // standard deviation of array
  stddev(numbers, nl_size);

  return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
