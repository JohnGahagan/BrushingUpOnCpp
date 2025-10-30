#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false; // shared flag between threads

// Worker thread function
void printWork(int id) {
    unique_lock<mutex> lock(mtx);

    // Wait until "ready" becomes true
    cv.wait(lock, [] { return ready; });

    // Once notified and ready == true
    cout << "Worker " << id << " is starting work!" << endl;
}

int main() {
    cout << "Starting worker threads..." << endl;

    thread t1(printWork, 1);
    thread t2(printWork, 2);
    thread t3(printWork, 3);

    // Give threads time to start and wait
    this_thread::sleep_for(chrono::seconds(1));

    {
        lock_guard<mutex> lock(mtx);
        cout << "Main thread: setting ready = true" << endl;
        ready = true;
    }

    // Notify all waiting threads
    cv.notify_all();

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    cout << "All worker threads finished!" << endl;
    return 0;
}
