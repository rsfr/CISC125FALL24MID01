#include <iostream>
#include <string>
using namespace std;

class Person{  // The base class
    protected:
        string name;
        int age;
    
    public: //Constructor for person
        Person(string n, int a) : name(n), age(a){}

        void input(){ //Input for person
            cout << "Enter name: " << endl;
            getline(cin, name); // Get line used to handle spaces
            cout << "Enter Age: " << endl;
            cin >> age;
            cin.ignore();
        }

        void printInfo() const { // Prints Person information
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

class Student: public Person{ // Derive class
    private:
        string student_ID;
        string major;
    public:
    Student(string n="", int a=0, string student_ID = "", string major = "") : Person(n,a), student_ID(student_ID), major(major){}
    void input(){
        cout << "\nEnter Student's Information" << endl;
        Person::input();
        cout << "Enter Student ID: " << endl;
        getline(cin,student_ID);
        cout << "Enter Major: " << endl;
        getline(cin,major);
    }
    void printStudentInfo() const{
        printInfo();
        cout << "Student ID: " << student_ID << ", Major: " << major << endl;
    }
};

class Instructor : public Person { //Instructor class
    public:
        Instructor(string n = "", int a = 0) : Person(n,a){} //constructor for instructor class
        void input(){ //Input function for Instructor class
            Person:: input(); //Use Person class's input function
        }
        void printInfo() const{ //Print function for instructor information
            Person::printInfo();//Use base class method
        }
};

class Course{ //Course aggregation class
    private:
    string courseName;
    Instructor instructor;
    public:
    Course(string c_name="", Instructor instructor=Instructor()) : courseName(c_name), instructor(instructor){}
    void input(){
        cout << "Enter course name: " << endl;
        getline(cin, courseName);
        cout << "Enter instructor's information" << endl;
        instructor.input();
    }

    void printCourseDetails() const{
        cout << "\nCourse Information" << endl;
        cout << "Course: " << courseName << endl;
        cout << "\nInstructor Information: " << endl;
        instructor.printInfo();
    }
};

int main(){
    Student stud;
    Course cour;

    cour.input();
    stud.input();

    cour.printCourseDetails();
    cout << "\nStudent Information" << endl;
    stud.printStudentInfo();

    return 0;
};
