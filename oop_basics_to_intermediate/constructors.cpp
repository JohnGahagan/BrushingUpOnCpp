#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    // Default constructor
    Car() {
        brand = "Unknown";
        year = 0;
        cout << "Default constructor called.\n";
    }

    // Parameterized constructor
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Parameterized constructor called.\n";
    }

    // Copy constructor
    Car(const Car &obj) {
        brand = obj.brand;
        year = obj.year;
        cout << "Copy constructor called.\n";
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car c1;              // default
    Car c2("Toyota", 2020); // parameterized
    Car c3 = c2;         // copy constructor
    cout << "\nDisplaying cars:\n";
    c1.display();
    c2.display();
    c3.display();
    return 0;
}
