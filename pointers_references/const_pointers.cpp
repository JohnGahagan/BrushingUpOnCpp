#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 20;

    const int* ptr1 = &x;     // pointer to const value
    int* const ptr2 = &x;     // const pointer (can't point elsewhere)
    const int* const ptr3 = &x; // const pointer to const value

    cout << *ptr1 << endl;
    // *ptr1 = 30; // NOT allowed (value is const)
    ptr1 = &y;    // allowed (can change pointer target)

    *ptr2 = 40;   // allowed (can change value)
    // ptr2 = &y; // NOT allowed (pointer itself is const)

    cout << *ptr2 << endl;

    return 0;
}
