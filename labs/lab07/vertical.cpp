// Do not add any other #include statement!
#include <iostream>

using namespace std;

// Declare printV() here
void printV(int n);

int main() {
    // 1. Get user input
    cout << "Enter integer: ";
    int intInput;
    cin >> intInput;

    // 2. Check input and pass it on to printV()
    //  Input MUST be positive (greater than 0). If input is less than 1, print error message & quit program
    if (intInput < 1) {
        cerr << "Input must be a positive integer.";
        exit(1);
    }

    // 3. printV() function call
    printV(intInput);

    return 0;
}

// Define printV() here
void  printV(int n) {
    // Use modulo statements to sort out digits within the function since I can't use arrays vectors OR strings
    // Check if n < 10 first. (If n < 10, only print out n once & end program)
    if (n < 10) {
        cout << n << endl;
    } else {
        printV(n / 10);
        cout << (n % 10) << endl;
    }
}

// Digit sorting function from AutoDesk TinkerCAD
//
/*int getThousands(int n) {
  int Thousands = n/1000;
  return Thousands;
}

int getHundreds(int n) {
    int Hundreds = n/100 % 10;
    return Hundreds;
}

int getTens(int n) {
    int Tens = (n/10 % 100) % 10;
    return Tens;
}

int getOnes(int n) {
    int Ones = ((n/1 % 1000) % 100) % 10;
    return Ones;
}

void setup() {
  int n = 6789;
  int m = 2345;

  Serial.begin(9600);

  Serial.print("thousands: ");
  Serial.println(getThousands(n));
  Serial.print("hundreds: ");
  Serial.println(getHundreds(n));
  Serial.print("tens: ");
  Serial.println(getTens(n));
  Serial.print("ones: ");
  Serial.println(getOnes(n));
  Serial.print("\n");
  
  Serial.print("thousands: ");
  Serial.println(getThousands(m));
  Serial.print("hundreds: ");
  Serial.println(getHundreds(m));
  Serial.print("tens: ");
  Serial.println(getTens(m));
  Serial.print("ones: ");
  Serial.println(getOnes(m));
}

void loop() {
}*/