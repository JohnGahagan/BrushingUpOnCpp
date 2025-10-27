#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex &obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Overload << operator (for easy printing)
    friend ostream& operator << (ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    // Overload == operator
    bool operator == (const Complex &obj) const {
        return (real == obj.real && imag == obj.imag);
    }
};

int main() {
    Complex c1(3, 2), c2(1, 7);
    Complex c3 = c1 + c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3 = c1 + c2: " << c3 << endl;

    cout << "c1 == c2? " << (c1 == c2 ? "Yes" : "No") << endl;
    return 0;
}
