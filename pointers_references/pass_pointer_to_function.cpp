#include <iostream>
using namespace std;

void changeValue(int *p) {
    *p = 50;
}

int main () {
    int x = 10;
    cout << "Before function call: " << x << endl;

    changeValue(&x);

    cout << "After function call: " << x << endl;
    
    return 0;
}