#include <iostream>
#include <string> /// Strings are classes!! (That's why we #include them)
#include <iomanip>

using namespace std;

class DayOfYear {
    public: 
        DayOfYear();    // Constructor
        void input();   // Member func
        void output();  // Member func
        void set(int new_m, int new_d); // Mutator(setter) member func
        int get_month();    // Acessor
        int get_day();  // Accessor

    private: 
        // These are all member variables to be used internally
        void check_date();
        int month;
        int day;
};

// Lecture 17: Classes! 
//      Note: classes are a data type whose variables are called objects
//      Definition of a class includes: descriptions of the kinds of values of the member variables

int main () {
    // Create 2 objects of DayOfYear
    DayOfYear today, birthday (12, 2);
    return 0;
}

DayOfYear::DayOfYear(): day(1), month(1) {}
DayOfYear::DayOfYear(int m, int d): month(m), day(d) {check_date()}

// Accessor ("getter") functoin to obtain values of member variables
void DayOfYear::output() {
    cout << "Month is: " << month << ", day is: " << day << endl;
}

void DayOfYear::set_month(int new_month) {
    month = new_month;
    check_date();
}

void DayOfYear::set_month(int new_day) {
    day = new_day;
    check_date();
}

int DayOfYear::get_month() {return month}
int DayOfYear::get_day() {return day}

void DayOfYear::check_date() {
    if ((month > 12) || (month < 1) || (day > 31) || (day < 1)) {
        cerr << "Bad date used." << endl;
        exit(1);
    }
}

// Mutator ("setter") functions allow member variable values to be changed
//      Note: set() in class DayOfYear
