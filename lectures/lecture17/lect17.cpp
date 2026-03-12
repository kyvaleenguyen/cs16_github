#include <iostream>
#include <string> /// Strings are classes!! (That's why we #include them)
#include <iomanip>

using namespace std;

// Note that all the member functions below still need to be defined
//      In this cpp file, they are defined outside of the class (but they can be defined inside the class!)
class DayOfYear {
    public: 
        DayOfYear();    // Constructor
        DayOfYear(int m, int d); // Non-default constructor
        void input();   // Member func
        void output();  // Member func
        void setMonth(int new_m);   // Mutator
        void setDay(int new_d);     // Mutator
        void setDate(int new_m, int new_d); // Mutator(setter) member func
        int getMonth();    // Acessor
        int getDay();  // Accessor

    private: 
        // Member function to be used internally
        void check_date();
        // Member variables
        int month;
        int day;
};

// Lecture 17: Classes! 
//      Note: classes are a data type whose variables are called objects
//      Definition of a class includes: descriptions of the kinds of values of the member variables

int main () {
    // Create 2 objects of DayOfYear
    DayOfYear today, birthday;

    // Mutator function call
    today.setDay(10);
    today.setMonth(2);

    birthday.setDay(10);
    birthday.setMonth(2);

    // Output accessor function call
    today.output();

    if ((today.getDay()) == (birthday.getDay()) && (today.getMonth()) == (birthday.getMonth())) {
        cout << "Happy birthday!" << endl;
    } else {
        cout << "Happy unbirthday!" << endl;
    }

    return 0;
}

// Constructors can invoke another constructor in their initialization
// Below is an example of a default constructor that calls a second constructor
//coordinate::coordinate(int a, int b): x(a), y(b) {}
//coordinte:coordinate(): coordinate(99,99) {}

// Constructor declaration examples inside class person that has private variables name & age (that are string & int type respectively)
//person();
//person(string name, int age);

// Constructor definition(s)
//      Note: constructors dont have types & dont return anything
// Default constructor definition: 
DayOfYear::DayOfYear(): day(1), month(1) {}

// Non-default constructor definition (w/ parameters/arguments): 
DayOfYear::DayOfYear(int m, int d): day(d), month(m) {
    if ((d < 1) || (d > 31) || (m < 1) || (m > 12)) {
        cerr << "Bade date given." << endl;
        exit(1);
    } else {
        day = d;
        month = m;
    }
}

// Mutator ("setter") functions allow member variable values to be changed
//      Note: set() in class DayOfYear
// Mutator function definitions
void DayOfYear::setMonth(int new_month) {
    month = new_month;
    check_date();
}
void DayOfYear::setDay(int new_day) {
    day = new_day;
    check_date();
}

// Accessor function definitions
int DayOfYear::getMonth() {return month;}
int DayOfYear::getDay() {return day;}
void DayOfYear::check_date() {
    if ((month > 12) || (month < 1) || (day > 31) || (day < 1)) {
        cerr << "Bad date used." << endl;
        exit(1);
    }
}
// Accessor ("getter") function to obtain values of member variables
void DayOfYear::output() {
    cout << "Month is: " << month << ", day is: " << day << endl;
}

// Data types in which programmers using it do not have access to the details of how values operate & are implemented are called abstract data types (ADT)
//      Note: abstract to programmer
//      Note: ADTs are concepts, classes are code implementations. Separate the specification of hyow the data type is used by a programmer from the details of how the type is implemented

// Classes to produce ADTs
/*class string {
    public: 

}*/

// To preserve the interface of an ADT so that programs using it dont need to be changed: 
//      Public member declarations cant be changed
//      Public member definitions can be changed
//      Private member functions can be added, deleted, or changed