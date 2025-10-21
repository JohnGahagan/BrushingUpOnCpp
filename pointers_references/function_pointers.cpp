#include <iostream>
using namespace std;

// A simple function that takes two ints and returns an int
int add(int a, int b) {
    return a + b;
}

// Another example function
int multiply(int a, int b) {
    return a * b;
}

// Function that takes a function pointer as a parameter
void operate(int x, int y, int (*func)(int, int)) {
    cout << "Result: " << func(x, y) << endl;
}

int main() {
    // Declare a function pointer
    int (*operation)(int, int);

    // Assign pointer to add function
    operation = &add;
    cout << "Calling add using function pointer: " << operation(3, 4) << endl;

    // Reassign pointer to multiply function
    operation = &multiply;
    cout << "Calling multiply using function pointer: " << operation(3, 4) << endl;

    // Pass a function pointer as an argument
    cout << "Using function pointer as a parameter:" << endl;
    operate(10, 5, add);
    operate(10, 5, multiply);

    return 0;
}
