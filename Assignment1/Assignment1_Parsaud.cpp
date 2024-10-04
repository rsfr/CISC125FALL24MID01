#include <iostream>
#include <string>

using namespace std;

// We can first start with the base class: Person.
class Person {
protected:
    string name;
    int age;

public:
    // Now we can put the constructor for the Person class.
    Person(string n = "", int a = 0) : name(n), age(a) {}

    // Input functions now go in.
    void input() {
        cout << "Enter name: ";
        getline(cin, name);  // Then we can use 'getline' to handle spaces for this code.
        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // To ignore the leftover newline character, we use this in the input buffer.
    }

    // Method to print Person information.
    void printInfo() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived Class: Student (Inherits from the Person)
class Student : public Person {
private:
    string studentID;
    string major;

public:
    // Constructor for Student class
    Student(string n = "", int a = 0, string id = "", string mj = "") : Person(n, a), studentID(id), major(mj) {}

    // Input function for Student class
    void input() {
        // Call the base class input function
        Person::input();
        cout << "Enter student ID: ";
        getline(cin, studentID);  // Use getlines to handle the space
        cout << "Enter major: ";
        getline(cin, major);  
    }

    // Method to print Student information
    void printStudentInfo() const {
        printInfo();  // Call base class method to print name and age
        cout << "Student ID: " << studentID << "\nMajor: " << major << endl;
    }
};

// Aggregation Class: Instructor
class Instructor : public Person {
public:
    // Constructor for Instructor class
    Instructor(string n = "", int a = 0) : Person(n, a) {}

    // Input function for Instructor class
    void input() {
        // Use Person's input function
        Person::input();
    }

    // Method to print Instructor information
    void printInfo() const {
        Person::printInfo();  // Reuse base class method
    }
};

// Aggregation Class for Course, contains instructor.
class Course {
private:
    string courseName;
    Instructor instructor; 

public:
    // Constructor for the Course class.
    Course(string cname = "", Instructor instr = Instructor()) : courseName(cname), instructor(instr) {}

    // Input function for the Course class.
    void input() {
        cout << "Enter course name: ";
        getline(cin, courseName);  // Use getline to handle spaces
        instructor.input();
    }

    // Method to print Course details
    void printCourseDetails() const {
        cout << "\n--- Course Information ---\n";
        cout << "Course Name: " << courseName << endl;
        cout << "--- Instructor Information ---\n";
        instructor.printInfo();  // Print instructor details.
    }
};

int main() {
    // We now create a Student object.
    Student student;
    
    // Then create an Instructor object inside the Course object.
    Course course;

    // Course and Student inputs to write in.
    course.input();
    student.input();
    
    // Now we can have the output for the course, instructor, and student information.
    course.printCourseDetails();

    cout << "--- Student Information ---\n";
    student.printStudentInfo();

    return 0;
}