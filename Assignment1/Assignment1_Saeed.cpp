#include <iostream>
#include <string>

using namespace std;

// Base Class: Person
class Person {
protected:
    string name;
    int age;
public:
    // Constructor for Person
    Person(const string &n, int a) : name(n), age(a) {}

    // Method to display person information
    void printInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived Class: Student (Inherits from Person)
class Student : public Person {
private:
    int studentID;
    string major;
public:
    // Constructor for Student
    Student(const string &n, int a, int id, const string &m) 
        : Person(n, a), studentID(id), major(m) {}

    // Method to display student information
    void printStudentInfo() const {
        printInfo(); // Inherited from Person
        cout << "Student ID: " << studentID << ", Major: " << major << endl;
    }
};

// Class with Composition: Course (Aggregates Instructor)
class Course {
private:
    string courseName;
    Person instructor; // Aggregating an object of Person (Instructor)

public:
    // Constructor for Course
    Course(const string &course, const Person &inst)
        : courseName(course), instructor(inst) {}

    // Method to display course and instructor details
    void printCourseDetails() const {
        cout << "Course: " << courseName << endl;
        cout << "Instructor ";
        instructor.printInfo();
    }
};

int main() {
    // Taking input for Instructor (Person)
    string instructorName;
    int instructorAge;

    cout << "Enter Instructor's Name: ";
    getline(cin, instructorName);
    cout << "Enter Instructor's Age: ";
    cin >> instructorAge;
    cin.ignore(); // Ignore newline character from input buffer

    // Taking input for Course
    string courseName;
    cout << "Enter Course Name: ";
    getline(cin, courseName);

    // Creating an Instructor (Person) object
    Person instructor(instructorName, instructorAge);

    // Creating a Course object that aggregates the Instructor object
    Course course(courseName, instructor);

    // Taking input for Student
    string studentName;
    int studentAge, studentID;
    string studentMajor;

    cout << "Enter Student's Name: ";
    getline(cin, studentName);
    cout << "Enter Student's Age: ";
    cin >> studentAge;
    cout << "Enter Student's ID: ";
    cin >> studentID;
    cin.ignore();
    cout << "Enter Student's Major: ";
    getline(cin, studentMajor);

    // Creating a Student object
    Student student(studentName, studentAge, studentID, studentMajor);

    // Output the Course, Instructor, and Student information
    cout << "\n--- Course Details ---" << endl;
    course.printCourseDetails();

    cout << "\n--- Student Details ---" << endl;
    student.printStudentInfo();

    return 0;
}