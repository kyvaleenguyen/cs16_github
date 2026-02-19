// Calculate.cpp
// By: Kyvalee Nguyen
// Created on: 01/19/2026

#include <iostream>
#include <cstdlib>
using namespace std;

int solution;

void calculate(int a, char operation, int b) {
    // Check for math operators and handle divide by zero
    if (operation == '+' || operation == '-' || operation == 'x' || operation == '%') {
        if ((operation == '%') && (b == 0)) {
            cerr << "Cannot divide by zero." << endl;
        } else if (operation == '+') {
            solution = a + b;
            cout << solution << endl;
        } else if (operation == '-') {
            solution = a - b;
            cout << solution << endl;
        } else if (operation == 'x') {
            solution = a * b;
            cout << solution << endl;
        } else if (operation == '%') {
            solution = a % b;
            cout << solution << endl;
        }
    } else {
        cerr << "Error: Invalid operator." << endl;
    }
}

int main() {
    int num1, num2;
    char symbol;

    // User input
    if (cin >> num1 >> symbol >> num2) {
        calculate(num1, symbol, num2);
    } else {
        cerr << "Error: Invalid input format." << endl;
    }

    return 0;
}
