#include <iostream>
using namespace std;

void check_it(int a, int b, int c) {
    if (a > b && b > c) {
        cout << 1;
    } else {
        cout << 0;
    }
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;   // read three integers
    check_it(x, y, z);
    return 0;
}
