#include <iostream>
using namespace std;

// Template with a default type of int
template <typename T = int>
class Calculator {
private:
    T a, b;

public:
    Calculator(T x, T y) : a(x), b(y) {}

    T add() const { return a + b; }
    T multiply() const { return a * b; }
};

int main() {
    // Uses default type (int)
    Calculator<> intCalc(10, 5);
    cout << "Default (int) Calculator:" << endl;
    cout << "Add: " << intCalc.add() << endl;
    cout << "Multiply: " << intCalc.multiply() << endl;

    // Explicitly specify double type
    Calculator<double> doubleCalc(3.5, 2.5);
    cout << "\nDouble Calculator:" << endl;
    cout << "Add: " << doubleCalc.add() << endl;
    cout << "Multiply: " << doubleCalc.multiply() << endl;

    return 0;
}
