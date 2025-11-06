#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <atomic>

using namespace std;

class ThreadPool {
private:
    vector<thread> workers;                  // pool of worker threads
    queue<function<void()>> tasks;           // task queue
    mutex queue_mutex;                       // protects task queue
    condition_variable condition;            // used to notify workers
    atomic<bool> stop;                       // flag to stop pool safely

public:
    // Constructor: create threads
    ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    function<void()> task;

                    // Critical section: wait for tasks or stop
                    {
                        unique_lock<mutex> lock(queue_mutex);
                        condition.wait(lock, [this] {
                            return stop || !tasks.empty();
                        });

                        if (stop && tasks.empty())
                            return; // gracefully exit

                        task = move(tasks.front());
                        tasks.pop();
                    }

                    // Execute the task outside the lock
                    task();
                }
            });
        }
    }

    // Add new task to the pool
    void enqueue(function<void()> newTask) {
        {
            lock_guard<mutex> lock(queue_mutex);
            tasks.push(move(newTask));
        }
        condition.notify_one(); // wake up one worker
    }

    // Destructor: stop all threads
    ~ThreadPool() {
        {
            lock_guard<mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all(); // wake up all workers

        for (auto &t : workers)
            t.join(); // wait for all threads to finish
    }
};

int main() {
    cout << "Starting thread pool with 3 workers...\n";
    ThreadPool pool(3);

    // Enqueue some example tasks
    for (int i = 1; i <= 6; ++i) {
        pool.enqueue([i] {
            cout << "Task " << i << " is running on thread " 
                 << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        });
    }

    cout << "Main thread: all tasks enqueued.\n";
    this_thread::sleep_for(chrono::seconds(4));
    cout << "Main thread: exiting, pool will shut down.\n";
    return 0;
}
