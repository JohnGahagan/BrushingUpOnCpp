#include <iostream>
using namespace std;

// Old-style C macro
#define ADD_MACRO(a, b) ((a) + (b))

// Modern C++ template
template <typename T>
T addTemplate(T a, T b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    double m = 2.5, n = 4.2;

    cout << "Using macro:" << endl;
    cout << "ADD_MACRO(x, y) = " << ADD_MACRO(x, y) << endl;
    cout << "ADD_MACRO(m, n) = " << ADD_MACRO(m, n) << endl;

    // Dangerous macro side effect
    cout << "\nMacro side effect example:" << endl;
    cout << "ADD_MACRO(x++, y++) = " << ADD_MACRO(x++, y++) << endl;
    cout << "After macro call: x = " << x << ", y = " << y << endl;

    // Using template (safe)
    x = 5; y = 10;
    cout << "\nUsing template (type-safe and side-effect free):" << endl;
    cout << "addTemplate(x++, y++) = " << addTemplate(x++, y++) << endl;
    cout << "After template call: x = " << x << ", y = " << y << endl;

    return 0;
}
