#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor: Object created\n";
    }

    ~Demo() {
        cout << "Destructor: Object destroyed\n";
    }

    void showMessage() {
        cout << "Hello from Demo\n";
    }
};

int main() {
    cout << "Entering main...\n";
    {
        Demo d1;
        d1.showMessage();
    } // d1 goes out of scope here, destructor called
    cout << "Exiting main...\n";
    return 0;
}
