#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Pointer points to the first element in the array
    int* p = arr;

    cout << "Pointer Arithmetic Demo\n\n";

    // Show initial value
    cout << "p points to value: " << *p << endl;

    // Move forward in memory (by sizeof(int) each time)
    p++;
    cout << "After p++: " << *p << endl;

    p++;
    cout << "After another p++: " << *p << endl;

    // Move backward
    p--;
    cout << "After p--: " << *p << endl;

    // Pointer difference
    int* start = arr;
    int* end = &arr[4];
    cout << "\nDifference between end and start: " << (end - start)
         << " elements apart.\n";

    // Iterate through entire array using a pointer
    cout << "\nIterating through array with pointer:\n";
    int* iter = arr;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *iter << endl;
        iter++;
    }

    return 0;
}
