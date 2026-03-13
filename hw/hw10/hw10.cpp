#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// #10
class Automobile {
    public: 
        void setPrice(double newPrice);
        void setProfit(double newProfit);
        double getPrice();
    private: 
        double price;
        double profit;
        double getProfit();
};

// #11
class TwoNumbers {
    public:
        TwoNumbers();    // Initializes num1, num2 to 0
        TwoNumbers(int n1, int n2);
        double sum();   // Returns sum of n1 & n2
        double difference();    // Returns difference of n1 & n2
        double max();   // Returns larger number of n1 & n2
        double num1, num2;
};

// #12 function declaration
template<typename T>
T findLargestElement(const vector<T>& vect);

int main () {
    // #10
    Automobile Hyundai, Jaguar;

    Hyundai.setPrice(4999.99);
    Jaguar.setPrice(30000.97);
    double aPrice, aProfit;
    aPrice = Jaguar.getPrice();
    aProfit = Jaguar.getPrice();
    if (Hyundai.getPrice() == Jaguar.getPrice()) {
        cout << "Want to swap cars?" << endl;
        Hyundai = Jaguar;
    } else {
        cout << "Too expensive!" << endl;
    }

    // #11
    TwoNumbers test1(4, 8);
    cout << "The sum of test1 is: " << test1.sum() << endl;
    cout << "The difference of test1 is: " << test1.difference() << endl;
    cout << "The larger number is: " << test1.max() << endl;

    // #12
    TwoNumbers ThisOne, ThatOne(5, 7);
    ThisOne.num1++;
    ThisOne.num2 -= 7;
    cout << ThisOne.num1 << " " << ThisOne.num2 << endl;

    ThatOne.num2 = ThatOne.sum() + ThisOne.difference();
    cout << ThatOne.num1 << " " << ThatOne.num2 << endl;

    cout << ThisOne.max() / ThatOne.max() << endl;

    // #12

    // Int test
    vector<int> integerVector = {10, 45, 23, 7, 89, 12};
    cout << "Largest int: " << findLargestElement(integerVector ) << endl;

    // Double test
    vector<double> doubleVector = {3.14, 1.59, 5.26, 9.11, 2.72};
    cout << "Largest double: " << findLargestElement(doubleVector ) << endl;

    // Character test (ASCII comparison)
    vector<char> charVector = {'a', 'G', 'z', 'M', 'q'};
    cout << "Largest char: " << findLargestElement(charVector ) << endl;

    return 0;
}

// #10
void Automobile::setPrice(double newPrice) {
    price = newPrice;
}
void Automobile::setProfit(double newProfit) {
    profit = newProfit;
}

double Automobile::getPrice() {
    return price;
}
double Automobile::getProfit() {
    return profit;
}

// #11
// Default constructor
TwoNumbers::TwoNumbers() {
    num1 = 0;
    num2 = 0;
}

// Non default constructor
TwoNumbers::TwoNumbers(int n1, int n2) {
    num1 = n1;
    num2 = n2;
}

// Returns sum of n1 & n2
double TwoNumbers::sum() {
    return num1 + num2;
}

// Returns difference of n1 & n2
double TwoNumbers::difference() {
    return num2 - num1;
}

// Returns larger number of n1 & n2
//      Note: if they are equal just return num2
double TwoNumbers::max() {
    if (num2 >= num1) {
        return num2;
    } else {
        return num1;
    }
}

// #12
template<typename T>
T findLargestElement(const vector<T>& vect) {
    T max = vect[0];
    // Iterate through all elements in the array of type T & check for the largest element. If a larger element is found after the previous, update the max value
    for (size_t i = 1; i < vect.size(); i++) {
        if (vect[i] > max) {
            max = vect[i];
        }
    }
    return max;
}