#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() : name("Unknown"), age(0) {}

    void setPersonInfo() {
        cout << "Enter Student's name: ";
        cin >> name;
        cout << "Enter Students age: ";
        cin >> age;

    }

    void printPersonInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Instructor {
protected:
    string Instructorname;
    int Instructorage;

public:
    Instructor() : Instructorname("Unknown"), Instructorage(0) {}

    void setInstructorInfo() {
        cout << "Enter Istructor's name: ";
        cin >> Instructorname;
        cout << "Enter Instructor's age: ";
        cin >> Instructorage;

    }

    void printInstructorInfo() {
        cout << "Name: " << Instructorname << ", Age: " << Instructorage << endl;
    }
};

class Student : public Person {
private:
    string studentID;
    string major;

public:
    Student() : studentID("Unknown"), major("Undeclared") {}

    void setStudentInfo() {
        setPersonInfo();
        cout << "Enter student's ID: ";
        cin >> studentID;
        cout << "Enter Student's major: ";
        cin >> major;
    }

    void printStudentInfo() {
        printPersonInfo();
        cout << "Student ID: " << studentID << ", Major: " << major << endl;
    }
};

class Course {
private:
    string courseName;
    Instructor instructor;

public:
    Course() : courseName("Unknown") {}

    void setCourseInfo() {
        instructor.setInstructorInfo();
        cout << "Enter course name: ";
        cin >> courseName;
    }

    void printCourseDetails() {
        cout << "\nCourse: " << courseName << endl;
        cout << "Instructor: ";
        instructor.printInstructorInfo();
    }
};

int main() {

    Course course;
    course.setCourseInfo();

    Student student;
    student.setStudentInfo();

    course.printCourseDetails();
    student.printStudentInfo();

    return 0;
}
