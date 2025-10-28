#include <iostream>
using namespace std;

// assignment 1
int SumOfTwo(int a, int b) {
    return a + b;
}

// assignment 2
void EvenOrOdd(int c) {
    if (c % 2 == 0)
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;
}

// Calculator functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

double divide(double a, double b) {
    if (b == 0) {
        cout << "Can't divide by 0" << endl;
        return 0;
    } else {
        return a / b;
    }
}

int main() {
    int num1, num2;
    char op;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> op;

    if (op == '+')
        cout << "Result: " << add(num1, num2) << endl;
    else if (op == '-')
        cout << "Result: " << subtract(num1, num2) << endl;
    else if (op == '*')
        cout << "Result: " << multiply(num1, num2) << endl;
    else if (op == '/')
        cout << "Result: " << divide(num1, num2) << endl;
    else
        cout << "Invalid operator" << endl;

    return 0;
}
