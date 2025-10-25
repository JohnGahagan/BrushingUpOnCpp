#include <iostream>
#include <string>
using namespace std;

/*
 * 1) Function template + full specialization
 *
 *    We define a generic printValue<T>, then a specialized version
 *    for std::string so we can do something different for strings.
 */

// Primary (generic) function template
template <typename T>
void printValue(const T& v) {
    cout << "Generic value: " << v << endl;
}

// Full specialization for std::string
template <>
void printValue<std::string>(const std::string& v) {
    cout << "String (specialized): \"" << v << "\" (length = " << v.size() << ")" << endl;
}

/*
 * 2) Class template + partial specialization
 *
 *    We define a Box<T> that holds a value. Then we partially specialize
 *    Box<T*> for pointer types to demonstrate different behavior
 *    when the stored type is a pointer.
 */

// Primary (generic) class template
template <typename T>
class Box {
public:
    explicit Box(T val) : value(val) {}
    void show() const {
        cout << "Box holding value: " << value << endl;
    }
private:
    T value;
};

// Partial specialization for pointer types T*
template <typename T>
class Box<T*> {
public:
    explicit Box(T* ptr) : valuePtr(ptr) {}
    void show() const {
        if (valuePtr) {
            cout << "Box holding pointer to value: " << *valuePtr << " (address: " << valuePtr << ")" << endl;
        } else {
            cout << "Box holding null pointer" << endl;
        }
    }
private:
    T* valuePtr;
};

int main() {
    // --- function template demonstration ---
    printValue(10);                       // uses generic template
    printValue(3.14);                     // generic template
    printValue<string>("hello world");    // explicit type or auto-deduce
    printValue(std::string("C++ rules")); // uses specialized version for std::string

    cout << "\n--- class template demonstration ---\n";

    // Generic Box for int
    Box<int> intBox(42);
    intBox.show();

    // Specialized Box for pointer type
    int n = 7;
    Box<int*> ptrBox(&n);
    ptrBox.show();

    // Null pointer example
    int* nullPtr = nullptr;
    Box<int*> nullBox(nullPtr);
    nullBox.show();

    return 0;
}
