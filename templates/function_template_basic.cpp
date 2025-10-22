#include <iostream>
using namespace std;
//OVERVIEW Templates allow code reuse for different data types without rewriting the function
// Template definition
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "add(2, 3) = " << add(2, 3) << endl;             // int
    cout << "add(2.5, 3.7) = " << add(2.5, 3.7) << endl;     // double
    return 0;
}
