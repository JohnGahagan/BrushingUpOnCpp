#include <iostream>
using namespace std;
//assignment 1
int SumOfTwo (int a, int b) {
    return a + b;
}
//assignment 2
void EvenOrOdd (int c) {
    if (c % 2 == 0) {
        cout << "Even" << endl;
    }
    else {
        cout << "Odd" << endl;
    }
}

main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Sum = " << SumOfTwo(num1,num2) << endl;
    cout << "Checking first number: ";
    EvenOrOdd(num1);

    return 0;
}