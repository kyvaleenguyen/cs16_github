/*
/ Skeleton File for FUNCTIONS.CPP for CS16, UCSB
/ Copyright © 2026 by Ziad Matni. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 5 LINES - DO NOT ADD TO THEM
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// INCLUDE HEADER FILE(S) HERE:
#include "headers.h"
#include "constants.h"

// The following function is defined for you. ***Do not change it AT ALL.***
//
// Pre-Condition: takes in an ifstream object for input file, 
//              a string for an input filename, an integer array and its size
// Post-Condition: the array will be populated with all the numbers from the input file
void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open("ArrayFile.txt");
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}

// Add your 8 functions definitions below:

// print_array function that prints every value separated by a space from ArrayFile.txt array
void print_array(int arr[], int asize) { 
    	for (int i = 0; i < asize; i++)
    	{
		cout << arr[i];
		if (i < asize - 1) {
			cout <<", ";
		}
	}
	cout << "\n";
}

int maxArray(int arr[], int asize) {
	// Setting the max value in the array to the first value so the value updates if each increasing index value is greater than the previous index value
	int max_val = arr[0];
        for (int i = 0; i < asize; i++)
        {
		if (arr[i] > max_val) {
			max_val = arr[i];
		}
        }
	cout << "Max = ";
	return max_val;
}

int minArray(int arr[], int asize) {
	// Setting the min value in the array to the first value so the value updates if each increasing index value is lesser than the previous index value
        int min_val = arr[0];
        for (int i = 0; i < asize; i++)
        {
                if (arr[i] < min_val) {
                        min_val = arr[i];
                }
        }
        cout << "Min = ";
	return min_val;
}


// sumArray function: I declared an int value sum to be 0, then added onto it with every iteration of arr[i] in the ArrayFile.txt array to get the proper sum of 10374
int sumArray(int arr[], int asize) {
	int sum = 0;
	for (int i = 0; i < asize; i++)
        {
		sum += arr[i];
        }
	cout << "Sum = ";
	return sum;
}

// evensArray function. I found it easiest to use modulo and check if the number had any remainder once divided by 2 since the rule for all even numbers is that they are divisible by 2. 
void evensArray(int arr[], int asize) {
        cout << "Evens: ";
	// I used a boolean value to check if the index in the array is not the first or last so a comma is printed before the next element
	bool evenIn = false;
	for (int i = 0; i < asize; i++) {
		if ((arr[i] % 2) == 0) {
			evenIn = true;
			break;
		}
	}
	
	if (evenIn) {
		bool first = true;
		for (int i = 0; i < asize; i++) {
			if ((arr[i] % 2) == 0) {
				if (!first) {
					cout << ", ";
				}
				cout << arr[i];
				first = false;
			}
		}
		cout << ", end\n";
	} else {
		cout << "\n";
	}
}

// the boolean function I built in to evaluate whether a number at index arr[i] is prime. If the function evaluates to true, the value returned is the index at arr[i] in the ArrayFile.txt array
bool prime(int i) {
	if (i <= 1) {
		return false;
	} 
	if (i == 2) {
		return true;
	}
	if (i % 2 == 0) {
		return false;
	}
	for (int p = 3; p * p <= i; p+= 2) {
		if (i % p == 0) {
			return false;
		}
	}
	return true;
}


// primesArray function using a built in prime function I built outside the void function which returns the number at index i in arr[i] if the number the functione evaluates to be prime is true. I found this easier since you can't return a value within a void function and it feels cleaner to me. 
void primesArray(int arr[], int asize) {
        cout << "Primes: ";
	bool primeIn = false;
	for (int i = 0; i < asize; i++) {	
		if (prime(arr[i]) == true) {
			primeIn = true;
			break;
		}
	}

	if (primeIn) {
		bool first = true;
		for (int i = 0; i < asize; i++) {
			if (prime(arr[i]) == true) {
				if (!first) {
					cout << ", ";
				}
				cout << arr[i];
				first = false;
			}
		}
		cout << ", end\n";
	} else {
		cout << "\n";
	}
}


// SeqSearch function
int SeqSearch(int arr[], int MAXSIZE, int target) {
        for (int i = 0; i < MAXSIZE; i++) {
		if (arr[i] == target) {
			cout << "Looking for " << target << ". Found at index: " << i << "\n";
			return i;
        	}
	}
	cout << "Looking for " << target << ". Not found!\n";
	return 0;
}

// AllSearches function calling from SeqSearch at proper indexing according to NSEARCHES: -5 to 4
void AllSearches(int arr[], int MAXSIZE) {
	cout << "Searches:\n";
	for (int i = -5; i <= 4; i++) {
		SeqSearch(arr, MAXSIZE, i);
	}
}
