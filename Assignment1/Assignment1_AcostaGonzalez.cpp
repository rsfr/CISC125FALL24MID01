// Coding Assignment #1
// By: Jarel Acosta Gonzalez

#include <iostream>
using namespace std;

class Person {  // Base class shows the person's name and age
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}  // Constructor
    void printInfo() const {  
        cout << "Name: " << name << ", Age: " << age << endl;  // Prints person's name and age
    }
};

class Student : public Person {  // Class represents the student
private:
    string studentID;
    string major;

public:
    Student(const string& name, int age, const string& studentID, const string& major)  // Constructor
        : Person(name, age), studentID(studentID), major(major) {}

    void printStudentInfo() const {
        printInfo(); // Call base class method
        cout << "Student ID: " << studentID << ", Major: " << major << endl; // Prints student's ID and Major
    }
};


class Course {  // Class shows the course and the instructor
private:
    string courseName;
    Person instructor; 

public:
    Course(const string& courseName, const Person& instructor) // Constructor
        : courseName(courseName), instructor(instructor) {}

    void printCourseDetails() const {
        cout << "Course: " << courseName << endl;
        cout << "Instructor: ";   // Prints course's name and instructor
        instructor.printInfo(); // Call instructor's method
    }
};

int main() {
    string instructorName, courseName, studentName, studentID, major; // Variables
    int instructorAge, studentAge; // Variables

    cout << "Enter Instructor's Name: ";
    getline(cin, instructorName);
    cout << "Enter Instructor's Age: ";
    cin >> instructorAge;
    cin.ignore(); 
    cout << "Enter Course Name: ";
    getline(cin, courseName);
    cout << "Enter Student's Name: ";
    getline(cin, studentName);
    cout << "Enter Student's Age: ";
    cin >> studentAge;
    cin.ignore();
    cout << "Enter Student's ID: ";
    getline(cin, studentID);
    cout << "Enter Student's Major: ";
    getline(cin, major);

    // Create objects
    Person instructor(instructorName, instructorAge);
    Student student(studentName, studentAge, studentID, major);
    Course course(courseName, instructor);

    // Output the information
    cout << "\nStudent Information:\n";
    student.printStudentInfo();
    cout << "\nCourse Details:\n";
    course.printCourseDetails();

return 0;
}