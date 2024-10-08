#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

};

class Student : public Person {
public:
    int studentID;
    string major;

};

class Course {
public:
    string courseName;
    Person instructor;
};

void printInfo(Student stu, Course cour) {

    cout << "Course: " << cour.courseName << endl;
    cout << "Instructor: " << "Name: " << cour.instructor.name << ", Age: " << cour.instructor.age << endl;
    cout << "Name: " << stu.name << ", Age: " << stu.age << endl;
    cout << "Student ID: " << stu.studentID << ", Major: " << stu.major << endl;
}

int main()
{
    Student student;
    Course course;

    cout << "Enter Instructor's Name: ";
    cin >> course.instructor.name;
    cout << endl;

    cout << "Enter Instructor's Age: ";
    cin >> course.instructor.age;
    cout << endl;

    cout << "Enter Course Name: ";
    cin >> course.courseName;
    cout << endl;

    cout << "Enter Student's Name: ";
    cin >> student.name;
    cout << endl;

    cout << "Enter Student's Age: ";
    cin >> student.age;
    cout << endl,

    cout << "Enter Student's ID: ";
    cin >> student.studentID;
    cout << endl;

    cout << "Enter Student's Major: ";
    cin >> student.major;
    cout << endl;

    printInfo(student, course);

    return 0;
}
