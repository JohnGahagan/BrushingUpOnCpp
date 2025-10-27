#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    virtual void work() {
        cout << "Employee is working..." << endl;
    }

    virtual ~Employee() {} // virtual destructor for safety
};

// Derived classes
class Engineer : public Employee {
public:
    void work() override {
        cout << "Engineer designs systems." << endl;
    }
};

class Manager : public Employee {
public:
    void work() override {
        cout << "Manager oversees the team." << endl;
    }
};

int main() {
    Employee* emp1 = new Engineer();
    Employee* emp2 = new Manager();

    emp1->work();  // Calls Engineer::work()
    emp2->work();  // Calls Manager::work()

    delete emp1;   // Calls virtual destructor chain
    delete emp2;

    return 0;
}
