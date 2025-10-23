#include <iostream>
using namespace std;

// this template supports two different types
template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    cout << "add(2, 3) = " << add(2, 3) << endl;           // int + int
    cout << "add(2.5, 3.7) = " << add(2.5, 3.7) << endl;   // double + double
    cout << "add('A', 1) = " << add('A', 1) << endl;       // char + int
    cout << "add(10, 4.5) = " << add(10, 4.5) << endl;     // int + double

    return 0;
}
