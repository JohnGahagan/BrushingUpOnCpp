#include <iostream>
#include <thread>    // Required for std::thread
#include <chrono>    // For sleep (simulating work)

using namespace std;

// Function that runs on a separate thread
void printNumbers() {
    for (int i = 1; i <= 5; ++i) {
        cout << "[Worker Thread] Number: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate work
    }
}

int main() {
    cout << "[Main Thread] Starting program..." << endl;

    // Create and start a thread that runs printNumbers()
    thread t1(printNumbers);

    cout << "[Main Thread] Doing something else while t1 runs..." << endl;

    // Wait for thread t1 to finish before continuing
    t1.join();

    cout << "[Main Thread] Thread finished. Exiting program." << endl;

    return 0;
}
