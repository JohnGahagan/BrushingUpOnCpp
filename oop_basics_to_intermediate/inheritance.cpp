#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void introduce() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class
class Student : public Person {
private:
    int studentID;

public:
    Student(string n, int a, int id) : Person(n, a), studentID(id) {}

    void displayStudent() {
        introduce(); // call base class function
        cout << "Student ID: " << studentID << endl;
    }
};

// Another derived class
class GraduateStudent : public Student {
private:
    string thesisTopic;
public:
    GraduateStudent(string n, int a, int id, string topic)
        : Student(n, a, id), thesisTopic(topic) {}

    void showThesis() {
        displayStudent();
        cout << "Thesis Topic: " << thesisTopic << endl;
    }
};

int main() {
    GraduateStudent g("Alice", 25, 101, "Machine Learning");
    g.showThesis();
    return 0;
}
