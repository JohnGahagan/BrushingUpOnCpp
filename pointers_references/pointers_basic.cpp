#include <iostream>
using namespace std;

int main() {
    int x = 10;      // A normal integer variable
    int *p = &x;     // Pointer storing the address of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x (&x): " << &x << endl;
    cout << "Pointer p (stores address of x): " << p << endl;
    cout << "Value pointed to by p (*p): " << *p << endl;

    return 0;
}
