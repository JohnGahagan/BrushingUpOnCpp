#include <iostream>
using namespace std;

int main() {
    int x = 5;      // normal int variable
    int *p = &x;    // pointer storing the address of x

    cout << "Before change:" << endl;
    cout << "x: " << x << endl;
    cout << "*p: " << *p << endl;   // dereference to get value

    // Change the value using the pointer
    *p = 20;   // this modifies x through the pointer

    cout << "After change:" << endl;
    cout << "x: " << x << endl;
    cout << "*p: " << *p << endl;

    return 0;
}
