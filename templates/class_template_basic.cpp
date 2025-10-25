#include <iostream>
using namespace std;

// Template for a simple container class
template <typename T>
class Box {
private:
    T value; // Can be int, double, string, etc.

public:
    // Constructor
    Box(T v) : value(v) {}

    // Setter
    void setValue(T v) {
        value = v;
    }

    // Getter
    T getValue() const {
        return value;
    }

    // Display method
    void show() const {
        cout << "Box contains: " << value << endl;
    }
};

int main() {
    // Create Box objects with different types
    Box<int> intBox(42);
    Box<double> doubleBox(3.1415);
    Box<string> stringBox("Hello Templates!");

    intBox.show();
    doubleBox.show();
    stringBox.show();

    // Update the value
    intBox.setValue(99);
    cout << "Updated intBox value: " << intBox.getValue() << endl;

    return 0;
}
