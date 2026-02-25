// Demonstrates basic structures in C++
//  with functions to print them 
//  and to populate them in different ways
//
//  by Z.Matni (c) 2026 for CS 16
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct CDAccount {
    string full_name;       // a name
    double principal;		    // a dollar amount
    double interest_rate;	// a percentage	 		
    int    term; 		    // a term amount in months
};

// Function that puts in values in a struct
void GetData(CDAccount &cda) {
    string name;
    double b, ir;
    int t;
    cout << "Enter name:::::::::: ";
    getline(cin, name);
    cout << "Enter principal::::::: ";
    cin >> b;
    cout << "Enter interest rate: ";
    cin >> ir;
    cout << "Enter term:::::::::: ";
    cin >> t;

    cda.full_name = name;
    cda.principal = b;
    cda.interest_rate = ir;
    cda.term = t;
    return;
}

// Function that creates CDAccounts from given values
CDAccount CopyMe(string name, double thisprincipal, 
                    double thisir, int thisterm) {
    CDAccount temp;
    temp.full_name = name;
    temp.principal = thisprincipal;
    temp.interest_rate = thisir;
    temp.term = thisterm;

    return temp;
}

void PrintSummary(CDAccount cda) {
    // formula for compound monthly interest
    double mir = (cda.interest_rate/12)/100;
    double final_balance = cda.principal * pow(1 + mir, cda.term);
    double gain = 100*(final_balance - cda.principal)/cda.principal; 

    cout << "With a yearly interest rate of " << cda.interest_rate
        << "%, at the end of " << cda.term << " months,\n"
        << cda.full_name << " will have " << final_balance
        << " dollars! \nThey started off with "
        << cda.principal << " dollars, which represents a " 
        << gain << "% gain.\n"
        << "-----------------------------------\n";
}

int main() {
// Example 1: Get all the data from user
    CDAccount account;
    GetData(account);

    cout<< "Here's a summary on this account:\n";
    PrintSummary(account);
    cin.ignore();
    cin.get();


// Example 2: Copy same data using assignment operation (=)
    CDAccount new_account = account;

    cout<< "As for the new account (a copy of the old account):\n";
    PrintSummary(new_account);
    cin.get();

// Example 3: Copy some of the same data, and change others, using CopyMe() function
    CDAccount newest_account = CopyMe("Elmo Mask",
                                account.principal - 100.00, 
                                account.interest_rate + 5, 
                                15);
    cout << "As for the NEWEST account...\n";
    PrintSummary(newest_account);
    cin.get();

// Example 4: Use initialization for the data
    CDAccount accountX = {"Lucky Lou", 100.5, 100, 24};
    cout << "Finally, AccountX:\n";
    PrintSummary(accountX);

    return 0;
}
