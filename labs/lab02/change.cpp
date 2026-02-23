// Change.cpp
// By: Kyvalee Nguyen
// Created on: 01/19/2026

#include <iostream>
#include <string>

using namespace std;

// Precondition: 0 < amount < 100
// Postcondition: The function prints out the number of quarters, dimes and pennies
void compute_coins(int amount) {
	int quarters = amount / 25;
	int remaining_amount = amount % 25;
	int dimes = remaining_amount / 10;
    	remaining_amount %= 10;
	int pennies = remaining_amount / 1;

	// Handle singular vs. plural words
	string quarter;
	if (quarters == 1) {
		quarter = "quarter";
	} else if (quarters == 0) {
		quarter = "";
	} else {
		quarter = "quarters";
	}
	string dime;
	if (dimes == 1) {
		dime = "dime";
    	} else if (dimes == 0) {
		dime = "";
    	} else {
        	dime = "dimes";
	}
    	string penny;
        if (pennies == 1) {
        	penny = "penny";
	} else if (pennies == 0) {
        	penny = "";
    	} else {
        	penny = "pennies";
	}
	cout << amount << " cents can be given in ";
    
    	// Output message
	if (quarters > 0 && dimes == 0 && pennies == 0) {
		cout << quarters << " " << quarter << "." << endl;
	} else if (quarters == 0 && dimes > 0 && pennies == 0) {
		cout << dimes << " " << dime << "." << endl;
	} else if (quarters == 0 && dimes == 0 && pennies > 0) {
		cout << pennies << " " << penny << "." << endl;
	} else if (quarters != 0 && dimes !=0 && pennies !=0) {
		cout << quarters << " " << quarter << ", ";
		cout << dimes << " " << dime << ", ";
		cout << pennies << " " << penny << "." << endl;
	}

	if (quarters != 0 && dimes != 0 && pennies == 0) {
		cout << quarters << " " << quarter << ", ";
		cout << dimes << " " << dime << "." << endl;
	} else if (quarters == 0 && dimes != 0 && pennies != 0) {
    		cout << dimes << " " << dime << ", ";
    		cout << pennies << " " << penny << "." << endl;
    	} else if (quarters != 0 && dimes == 0 && pennies != 0) {
		cout << quarters << " " << quarter << ", ";
		cout << pennies << " " << penny << "." << endl;
    	} else if (quarters != 0 && dimes != 0 && pennies == 0) {
		cout << quarters << " " << quarter << ", ";
		cout << dimes << " " << penny << "." << endl;
	}
}

int main() {
    int input_amount;

    // Loop until 0 is entered
    while (true) {
        cout << "Enter number of cents (or zero to quit):" << endl;
        
        if (!(cin >> input_amount)) {
            // Invalid inputs
            cerr << "Error. Invalid input." << endl;
            continue; // Go back to the start of the loop
        }

        if (input_amount == 0) {
            break; // Exit loop if zero is entered
        }

        // Ensure the range of cents input is correct
        if (input_amount < 2 || input_amount > 98) {
            cerr << "Amount is out of bounds. Must be between 1 and 99" << endl;
            continue; // Go back to the start of the loop
        }

        // Valid input, call the function
        compute_coins(input_amount);
    }

    return 0;
}

