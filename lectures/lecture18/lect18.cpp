#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

// REMEMBER: to use member functions within a class on objects of a class, you need to use the dot operator to call those member functions & actually use them
// Lect18 review: inhertiance

// iClicker 1: 
class MarketItem {
    public: 
        MarketItem();
        MarketItem(float p);
        void setPrice(float p);
        float getPrice();
    private:
        float price;
};

// iClicker 2: 
class Dawg {
    public: 
        // Note: member functions can have the same number of parameters without overloading the program when the class is compiled so long as the variable types within each member func are distinct from
        // each other. (Cannot be the same type between more than 1 member func or else overload will occur)
        Dawg();     // Constructor
        Dawg(int age);  // Constructor
        Dawg(string name);  // Constructor
        void setAge(int age);   // Mutator member function
        void setName(string name);  // Mutator member function
        int getAge();   // Accessor member function
        string getName();   // Accessor member function
    private:
        // Private member variables to be used internally within the class
        int dawg_age;
        string dawg_name;
};


// Memory Slicing Example
class Animal {
    public:
        virtual void speak() const {cout << "Generic animal sound" << endl;}
};

class Cat : public Animal {
    public:
        void speak() const {cout << "Meow" << endl;}
};

void describeByRef(const Animal& a) {
    cout << "By reference: ";
    a.speak();
}

int main () {
    // iClicker 1: 
    // Using class MarketItem
    MarketItem gouda, ham_slices(5.99);
    cout << "The price of ham is: " << ham_slices.getPrice() << endl;

    // Set price of gouda cheez
    gouda.setPrice(7.99);
    cout << "The price of gouda is: " << gouda.getPrice() << endl;

    // iClicker 2: 
    // Using class Dawg
    Dawg dawg1, dawg2;
    dawg1.setAge(3);
    dawg2.setAge(5);

    dawg1.setName("CupcakeTheDestroyer");
    dawg2.setName("Sausage");

    cout << "My first dog's name is: " << dawg1.getName() << endl;
    cout << "My second dog's name is: " << dawg2.getName() << endl;

    // Are dey old enough?
    // Construct if statements to check in non-default constructor w/ parameters


    // Memory slicing
    Cat Scoobert;
    Scoobert.speak(); // Outputs: "Meow"

    describeByRef(Scoobert);

    return 0;
}

// Member function definitions for class MarketItem
// Constructors
MarketItem::MarketItem() {price: 0;}
MarketItem::MarketItem(float p) {price = p;}

// Accessors/Mutators
void MarketItem::setPrice(float p) {price = p;}
float MarketItem::getPrice() {return price;}


// Member function definitions for class Dawg
// Constructors
Dawg::Dawg() {dawg_age: 0; dawg_name: "";}
Dawg::Dawg(int age): dawg_age(age) {
    // Check for valid input
    if (age < 5) {
        cout << "Aww still a baby!";
    } else {
        cout << "They're an adult now!";
    }
}
Dawg::Dawg(string name) {dawg_name = name;}

// Accessors/Mutators
void Dawg::setAge(int age) {dawg_age = age;}
void Dawg::setName(string name) {dawg_name = name;}
// Note: for accessor member functions, they have no arguments but require you to return a value of appropriate type from the private elements in the same class with the same name as the private element
int Dawg::getAge() {return dawg_age;}
string Dawg::getName() {return dawg_name;}
