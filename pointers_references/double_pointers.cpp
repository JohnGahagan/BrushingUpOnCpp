#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* p = &x;
    int** pp = &p;

    cout << "x = " << x << endl;
    cout << "*p = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    **pp = 99; // changes x through double pointer
    cout << "After change: x = " << x << endl;

    return 0;
}
