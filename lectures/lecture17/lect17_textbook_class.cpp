#include <iostream>
#include <string> /// Strings are classes!! (That's why we #include them)
#include <iomanip>

using namespace std;

class DayOfYear {
    public: 
        void output();
        int month;
        int day;
};

// Lecture 17: Classes! 
//      Note: classes are a data type whose variables are called objects
//      Definition of a class includes: descriptions of the kinds of values of the member variables

int main () {
    DayOfYear today, birthday;

    cout << "Enter today's date" << endl;
    cout << "Enter month as a numbeer: ";
    cin >> today.month;

    cout << "Enter the day of the month: ";
    cin >> today.day;

    cout << "Enter your birthday: " << endl;
    cout << "Enter month as a number: ";
    cin >> birthday.month;

    cout << "Enter the day of the month: ";
    cin >> birthday.day;

    // output member function from DayOfYear class: 
    cout << "Today's date is: ";
    today.output();

    cout << "Your birthday is: ";
    birthday.output();

    // Birthday? 
    if ((today.month == birthday.month) && (today.day == birthday.day)) {
        cout << "Happy birthday!" << endl;
    } else {
        cout << "Happy un-birthday!" << endl;
    }


    return 0;
}

// Accessor ("getter") functoin to obtain values of member variables
void DayOfYear::output() {
    cout << "month = " << month << ", day = " << day << endl;
}

// Mutator ("setter") functions allow member variable values to be changed
//      Note: set() in class DayOfYear