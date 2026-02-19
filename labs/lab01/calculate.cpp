#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter 3 numbers: " << endl;
    //declare variables
    int var1, var2, var3;
    int calculation;
    //take inputs
    cin >> var1;
    cin >> var2;
    cin >> var3;
    //calculate variables
    calculation = 2*(var1 - 4*var2) + 3*var3;
    //output
    cout << "The result of the formula is: " << calculation << endl;
    return 0;
}
