#include <iostream>
#include <string>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void printInfo() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived class: Student (Inheritance)
class Student : public Person {
private:
    int studentID;
    string major;

public:
    Student(string n, int a, int id, string m) : Person(n, a), studentID(id), major(m) {}

    void printStudentInfo() {
        printInfo();
        cout << "Student ID: " << studentID << "\nMajor: " << major << endl;
    }
};

// Class using Composition: Course
class Course {
private:
    string courseName;
    Person instructor; // Composition (Instructor is a Person)

public:
    Course(string cname, Person instr) : courseName(cname), instructor(instr) {}

    void printCourseDetails() {
        cout << "Course Name: " << courseName << endl;
        cout << "Instructor Details:" << endl;
        instructor.printInfo();
    }
};

int main() {
    // Create a Student object
    Student student1("John Doe", 20, 12345, "Computer Science");

    // Create an Instructor (Person object)
    Person instructor("Dr. Smith", 45);

    // Create a Course object with composition
    Course course1("C++ Programming", instructor);

    // Print Student Info
    cout << "Student Information:" << endl;
    student1.printStudentInfo();

    // Print Course Info
    cout << "\nCourse Information:" << endl;
    course1.printCourseDetails();

    return 0;
}