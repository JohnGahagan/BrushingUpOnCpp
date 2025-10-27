#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function: can be overridden in derived classes
    virtual void speak() {
        cout << "Animal makes a sound" << endl;
    }

    // Non-virtual function: cannot be overridden polymorphically
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void speak() override { // override keyword is optional but recommended
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Regular calls
    Dog d;
    Cat c;

    d.speak();  // Dog barks
    c.speak();  // Cat meows

    // --- POLYMORPHISM IN ACTION ---
    // Base class pointer pointing to derived objects
    Animal* a1 = &d;
    Animal* a2 = &c;

    cout << "\nPolymorphism Example:\n";
    a1->speak();  // Calls Dog::speak() because it's virtual
    a2->speak();  // Calls Cat::speak()

    cout << "\nWithout Virtual Function:\n";
    a1->eat();    // Always calls Animal::eat()
    a2->eat();    // Always calls Animal::eat()

    return 0;
}
