#include <iostream>
using namespace std;

class Person {
private:
    // PRIVATE: Accessible only inside this class
    string name;
    int age;

protected:
    // PROTECTED: Accessible inside this class AND derived classes
    string nationality;

public:
    // PUBLIC: Accessible anywhere
    void setData(string n, int a, string nat) {
        name = n;
        age = a;
        nationality = nat;
    }

    void showData() {
        cout << "Name: " << name << ", Age: " << age << ", Nationality: " << nationality << endl;
    }
};

// Derived class
class Student : public Person {
private:
    int studentID;

public:
    void setStudentInfo(string n, int a, string nat, int id) {
        // Can access protected 'nationality' but not private 'name' or 'age'
        setData(n, a, nat);  // must use public function from base class
        studentID = id;
    }

    void showStudentInfo() {
        // Can access 'nationality' directly (protected)
        cout << "Nationality (from derived): " << nationality << endl;
        showData(); // public function from base class
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Person p;
    p.setData("Alice", 30, "USA");
    p.showData();

    cout << "\n--- Derived Class Example ---\n";
    Student s;
    s.setStudentInfo("Bob", 20, "Canada", 1234);
    s.showStudentInfo();

    // The following lines would cause errors:
    // p.name = "Charlie";     // private: not accessible
    // s.nationality = "UK";   // protected: not accessible outside class
    // s.age = 25;             // private: not accessible

    return 0;
}
