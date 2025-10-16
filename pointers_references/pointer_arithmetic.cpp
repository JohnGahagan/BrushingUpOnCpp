#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;  // this is the same as &arr[0]

    cout << *p << endl;  // 10
    p++;
    cout << *p << endl;  // 20
    p++;
    cout << *p << endl;  // 30

    return 0;
}
