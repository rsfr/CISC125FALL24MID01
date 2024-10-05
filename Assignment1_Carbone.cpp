#include <iostream>
#include <string>

using namespace std;

class Person { //Designates inherited base class
    protected:
        string Name; //Name attribute
        int Age;    //Age attribute
    public:
        Person(string n = "",int a = 0) : Name(n), Age(a){} //Constructor for Person
            void input(void){   //Input for Person
                cout << "Enter Name: " << endl;
                getline(cin, Name); //Get line used to handle spaces
                cout << "Enter Age: " << endl;
                cin >> Age;
                cin.ignore(); //Input buffer to ignore newline character
        }
        void printInfo() const { //Prints Person information
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
        }
};

class Student: public Person { //designates deriving class.
    private:
        string sID;    //Student ID attribute
        string Major; //Student Major attribute
    public:
    Student(string n = "", int a = 0, string sID = "", string Major = "") : Person(n, a), sID(sID), Major(Major){} //Constructor for Student
    void input(){
        Person::input(); //Input for Student
        cout << "Enter Student ID#: " << endl;;
        getline(cin, sID);
        cout << "Enter Major: " << endl;
        getline(cin, Major);
    }
    void printStudentInfo() const {  // Prints student information
        printInfo();
        cout << "Student ID: " << sID << endl;
        cout << "Major: " << Major << endl; 
    }
};

class Instructor : public Person { //Instructor class
    public:
        Instructor(string n = "", int a = 0) : Person(n, a){} //constructor for Instructor
        void input() { //Input uses the same input from Person.
            Person::input();
        }
        void printInfo() const{ //Uses same printinfo as Person
            Person::printInfo();
    }
};

class Course {    //Designates Course Aggregation class
    private:
    string cID;
    Instructor instructor;
    public:  //Didn't need a constructor. I forgot to build it, and it worked without it.
        void input() {
            cout << "Enter Course name: " << endl;
            getline(cin, cID);
            instructor.input();
        }
        void printCourseInfo(void){ // prints course information
        cout << "/n Course Information: " << endl;
        cout << "-------------------------" << endl;
        cout << "Course ID: " << cID << endl;
        cout << "Instructor Information: " << endl;;
        instructor.printInfo();
        }
};

int main(){
    Student s; //student object, used shorthand.
    Course c; //course object, used shorthand.
    
    //Course and student inputs below
    c.input();
    s.input();
    
    //Outputs.
    c.printCourseInfo();
    cout << "\nStudent Information: " << endl;
    s.printStudentInfo();

    return 0;
};