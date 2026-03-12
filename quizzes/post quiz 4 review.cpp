#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double scooby(double x);

void bubble(int array[], int size);

int main () {
    // recursive function test
    cout << scooby(2.5) << " snacks!\n";

    // bubble sort test
    int arr[5] = {3, 4, 1, 8, 10};
    int size = 5;

    bubble(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// recursive arithmetic function
double scooby(double x) {
    if (x <= 1.5) {
        return x;
    }
    return (2 * scooby(x - 0.5) + 3);
}

// bubble Sort function
void bubble(int array[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 1; j < i; j++) {
            if (array[j-1] < array[j]) {
                int temp;
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}