#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    // Constructor (initializer list)
    Car(const string& b, int y) : brand(b), year(y) {}

    // Accessors
    string getBrand() const { return brand; }
    int getYear() const { return year; }

    // Behavior
    void startEngine() const {
        cout << "The " << brand << " engine started!" << endl;
    }

    void displayInfo() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car myCar("Toyota", 2020);   // prefer initialized object
    myCar.startEngine();
    myCar.displayInfo();
    return 0;
}
