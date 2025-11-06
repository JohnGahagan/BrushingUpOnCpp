#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    cout << "Main thread ID: " << this_thread::get_id() << endl;

    // Create and start a thread using a lambda function
    thread worker([]() {
        cout << "Worker thread started (ID: " << this_thread::get_id() << ")" << endl;

        for (int i = 1; i <= 5; ++i) {
            cout << "Worker counting: " << i << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }

        cout << "Worker thread finished!" << endl;
    });

    cout << "Main thread is doing other work..." << endl;

    // Wait for the worker to finish
    worker.join();

    cout << "Main thread exiting." << endl;
    return 0;
}
