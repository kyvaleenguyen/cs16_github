/*
/ Skeleton File for ARRAYS.CPP for CS16, UCSB
/ Copyright © 2026 by Ziad Matni. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);


    
    // printArray function call
    print_array(array, MAXSIZE);
    
    // maxArray function call
    int max = maxArray(array, MAXSIZE);
    cout << max << endl;

    // minArray function call
    int min = minArray(array, MAXSIZE);
    cout << min << endl;

    // sumArray function call
    int sum = sumArray(array, MAXSIZE);
    cout << sum << endl;

    // evensArray function call
    evensArray(array, MAXSIZE);

    // primesArray function call
    primesArray(array, MAXSIZE);

    // AllSearches & SeqSearch function call
    AllSearches(array, MAXSIZE);

    return 0;


    // For each function call, I created an int value to be printed for non void functions after the intial function ran. For void functions, all I had to do in this file was call on them since the function definition in functions.cpp did all the work for me. 
}


