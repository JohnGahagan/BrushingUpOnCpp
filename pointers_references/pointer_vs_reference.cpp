#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 10;

    // Pointer example
    int* p = &x;
    cout << "Pointer p points to x. *p = " << *p << "\n";

    *p = 20; // modify x through pointer
    cout << "After *p = 20, x = " << x << "\n";

    p = &y; // repoint pointer to y
    cout << "Pointer p now points to y. *p = " << *p << "\n";

    // Reference example
    int& r = x;  // r is a reference to x
    cout << "Reference r refers to x. r = " << r << "\n";

    r = 50;  // modifies x through the reference
    cout << "After r = 50, x = " << x << "\n";

    // Demonstrate assignment to reference doesn't rebind
    r = y;
    cout << "After r = y (value assignment), x = " << x << "\n";
    cout << "y is still " << y << "\n";

    return 0;
}
