#include <iostream>
using namespace std;

// Abstract base class: cannot be instantiated directly
class Shape {
public:
    // Pure virtual function — must be implemented by derived classes
    virtual double area() const = 0;

    // Another pure virtual function
    virtual void draw() const = 0;

    // Regular function (can have normal implementation)
    void info() const {
        cout << "This is a shape." << endl;
    }

    // Virtual destructor (good practice for base classes)
    virtual ~Shape() {
        cout << "Shape destroyed." << endl;
    }
};

// Derived class implementing the abstract methods
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }

    ~Circle() {
        cout << "Circle destroyed." << endl;
    }
};

// Another derived class
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing a Rectangle of " << width << "x" << height << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destroyed." << endl;
    }
};

int main() {
    // Shape s; // THIS is an Error: cannot instantiate abstract class

    // You can only create objects of derived (concrete) classes
    Circle c(5.0);
    Rectangle r(4.0, 6.0);

    // Polymorphism with abstract base pointer
    Shape* shapes[2] = { &c, &r };

    for (int i = 0; i < 2; ++i) {
        shapes[i]->info();   // Calls base function
        shapes[i]->draw();   // Calls derived implementation
        cout << "Area: " << shapes[i]->area() << "\n\n";
    }

    return 0;
}
