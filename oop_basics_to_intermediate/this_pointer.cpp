#include <iostream>
using namespace std;

class Car {
    string brand;
public:
    Car(string brand) { this->brand = brand; }

    void showBrand() {
        cout << "Brand: " << this->brand << endl;
    }
};

int main() {
    Car car1("Toyota");
    Car car2("Honda");

    car1.showBrand(); // 'this' inside showBrand() points to car1
    car2.showBrand(); // 'this' inside showBrand() points to car2

    return 0;
}
