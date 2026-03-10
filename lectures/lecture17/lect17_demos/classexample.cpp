/*
 * classexample.cpp for CS16, (c) 2024, Matni
 *
 * Demonstrates simple ADT style class
 * with Constructors, Setters, Getters
 *
 */
#include <iostream>
#include <string>
using namespace std;

class DayOfYear { 
	public: 
		DayOfYear();			    // constructor
		DayOfYear(int m, int d);	// constructor
		void output( ); 		    // member function
		void set_month(int new_month); // mutator(setter) member function 
		void set_day(int new_day);  // mutator(setter) member function 
		int get_month( );	        // accessor (getter) member function
		int get_day( ); 		    // accessor (getter) member function
	private: 
		void check_date( );		    // member function – to be used internally	
		int month; 		            // member variable
		int day; 			        // member variable
};

DayOfYear::DayOfYear( ): day(1), month(1) { }
DayOfYear::DayOfYear( int m, int d ): month(m), day(d) { check_date(); }

void DayOfYear::output() {
    cout << "Month is: " << month
        << " and Day is: " << day << endl;
}

void DayOfYear::set_month( int new_month ) {
    month = new_month;
    check_date();
}

void DayOfYear::set_day( int new_day ) {
    day = new_day;
    check_date();
}

int DayOfYear::get_month() { return month; }
int DayOfYear::get_day() { return day; }

void DayOfYear::check_date() {
    if ( (month > 12) || (month < 1) || (day > 31) || (day < 1) ) {
        cerr << "Bad date used.\n";
        exit(1);
    }
}

int main() {
    // Create 2 objects of DayOfYear
    DayOfYear today, birthday(12, 25);

    // Use the output() member function
    cout << "Using output():\n";
    today.output();
    birthday.output();

    // Use the setter functions
    cout << "\nUsing setters & output():\n";
    today.set_month(11);
    today.set_day(26);
    today.output();
    
    // Use the getter functions
    cout << "\nUsing getter functions: birthday month = " << birthday.get_month() 
        << " & birthday day = " << birthday.get_day() << endl;

    // Should trigger check_date() and quit the program b/c of bad date
    //DayOfYear tomorrow(13, 13);

    cout << "The END - this won't get printed!!\n";
    
    return 0;
}
