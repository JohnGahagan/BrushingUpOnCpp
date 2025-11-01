#include <iostream>
#include <future>    // for std::async, std::future
#include <chrono>    // for simulating work with sleep

using namespace std;

// Function that simulates heavy computation
int computeSquare(int x) {
    cout << "Computing square of " << x << " on thread..." << endl;
    this_thread::sleep_for(chrono::seconds(2)); // simulate heavy work
    return x * x;
}

int main() {
    cout << "Main thread starts async task..." << endl;

    // Launch computeSquare asynchronously
    future<int> result = async(launch::async, computeSquare, 10);

    cout << "Main thread continues doing other work..." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "Waiting for async result..." << endl;

    // get() blocks until the async task finishes
    int value = result.get();

    cout << "Result: " << value << endl;
    cout << "Main thread ends." << endl;

    return 0;
}
