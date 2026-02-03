#include <iostream>
#include <string>
using namespace std;

// #5 function
void reverse_print(int array[], int array_size) {
    for (int i = array_size - 1; i >= 0; i--) {
        int *a = &array[i];
        cout << *a << " " << endl;
    }
}

// #6 function
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;       
}

int main () {
    // #4
    int num1 = 2, num2 = 8, *p = &num1, *q = &num2;
    // print address and value of num1
    cout << "Address of num1 (&num1): " << &num1 << endl; 
    cout << "Value of num1 (num1): " << num1 << endl;
    // print value of p and value of pointer p
    cout << "Value of p (p): " << p << endl; 
    cout << "Value of pointer *p (*p): " << *p << endl;
    // print address and value of num2
    cout << "Address of num2 (&num2): " << &num2 << endl; 
    cout << "Value of num2 (num2): " << num2 << endl;
    // print value of q and value of pointer q
    cout << "Value of q (q): " << q << endl; 
    cout << "Value of pointer *q (*q): " << *q << endl;
    // print address of p and address of q
    cout << "Address of p (&p): " << &p << endl; 
    cout << "Address of q (&q): " << &q << endl; 

    // #5
    int Array[] = {1, 2, 3, 4, 5};
    int size = 5; 
    reverse_print(Array, size);

    // #6
    int a=2, b=4;
    swap(&a, &b);
    cout << a << " " << b << endl;

    // #7
    const int SIZE = 5;
    int Gaucho[SIZE] = {10, 20, 30, 40, 50};
    int *ucsb = Gaucho;
    for (int *p=Gaucho; p < Gaucho + SIZE; p++) {
        cout << *p << ",";
    }
    cout << endl;

    return 0;
}