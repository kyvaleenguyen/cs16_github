// Demonstrates basic structures in C++
//  by Z.Matni (c) 2026 for CS 16
//
#include <iostream>
#include <string>
using namespace std;

struct CDAccount {
    string full_name;       // a name
    double balance;		    // a dollar amount
    double interest_rate;	// a percentage	 		
    int    term; 		    // a term amount in months
} ;

int main() {

    CDAccount my_account;

    my_account.full_name = "Carmen Sandiego";
    my_account.balance = 1000.50;
    my_account.interest_rate = 7.5;
    my_account.term = 12;

    cout << "At the end of "
        << my_account.term << " months, "
        << my_account.full_name << " will have "
        << my_account.balance * (1 + my_account.interest_rate/100)
        << " dollars! \nShe started off with just "
        << my_account.balance << " dollars.\n";
    
    return 0;
}
