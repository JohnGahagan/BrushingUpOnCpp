#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
//note endl is inefficent because it does more thant just end line it also clears the buffer "\n" is more efficient
    cout << "Hello World" << "\n";
//this works too
    cout << "Hello World\n";
    
    return 0;
}
