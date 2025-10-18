#include <iostream>
#include <memory>  // For unique_ptr, shared_ptr, weak_ptr
using namespace std;

// This is a regular pointer
// It can point to anything, anytime
void RawPointer() {
    int* p = new int(5);
    cout << "RawPointer value: " << *p << endl;
    delete p;  // You MUST delete or you risk memory leaks, dangling pointers, crashes
}

// This is a unique pointer
// It OWNS the object exclusively (only ONE owner)
// Automatically frees memory when out of scope
// CANNOT be copied, only moved
void UniquePointer() {
    unique_ptr<int> p = make_unique<int>(5);
    cout << "UniquePointer value: " << *p << endl;
}

// This is a shared pointer
// It uses reference counting
// Object is deleted when ALL owners go away
// Multiple variables can share the same data
void SharedPointer() {
    shared_ptr<int> p1 = make_shared<int>(10);
    shared_ptr<int> p2 = p1;  // Both own it now
    cout << "SharedPointer value: " << *p1 << endl;
    cout << "Use count: " << p1.use_count() << endl;
}

// This is a weak pointer
// We use this with shared_ptr to avoid circular references
void WeakPointer() {
    shared_ptr<int> p1 = make_shared<int>(20);
    weak_ptr<int> wp = p1;  // Does NOT increase reference count

    cout << "Use count before lock: " << p1.use_count() << endl;

    if (auto sp = wp.lock()) {  // lock() tries to get a shared_ptr
        cout << "WeakPointer locked value: " << *sp << endl;
        cout << "Use count after lock: " << sp.use_count() << endl;
    } else {
        cout << "Object expired." << endl;
    }
}

int main() {
    RawPointer();
    UniquePointer();
    SharedPointer();
    WeakPointer();
    return 0;
}
