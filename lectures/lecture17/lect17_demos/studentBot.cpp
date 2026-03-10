#include <iostream>
#include <string>
using namespace std;

class StudentBot {
    public:
        // Constructors!!!
        StudentBot();
        StudentBot(int a, string n);
        // public mem function
        void info();
        // set the values of the mem vars
        void set_name(string n);
        void set_age(int a);
        // get the values of the mem vars
        string get_name();
        int get_age();

        private:
        string real_name;
        int age;
};

// Define: Constructor
StudentBot::StudentBot() {
    real_name = "NoName";
    age = 0;
}

StudentBot::StudentBot(int a, string n) {
    real_name = n;
    age = a;
}

// Define: Member function info
void StudentBot::info() {
    cout << "This StudentBot's name is "
        << real_name << ", and their age is "
        << age << endl;
}

// Define setters and getters:
void StudentBot::set_name(string n) { real_name = n; }
void StudentBot::set_age(int a) { age = a; }
string StudentBot::get_name() { return real_name; }
int StudentBot::get_age() { return age; }

int main() {
    StudentBot Hailey, Thomas, Naz(100, "NAZ");

    Hailey.info();
    Thomas.info();
    Naz.info();

    Thomas.set_name("Thom");
    Thomas.set_age(19);

    Naz.set_name("Nazo");

    Hailey.info();
    Thomas.info();
    Naz.info();


    return 0;
}
