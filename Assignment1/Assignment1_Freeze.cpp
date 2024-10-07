/* include 
a base class
a derived class that inherits from the base class
a class that represents a part of another class (demonstrating composition)
demonstrate how inheritance and composition work together in object oriented programming
*/




#include <iostream>
#include <string>
using namespace std;


class Person {
    //base class

public:
    string Name ; 
    int Age ;
     
//student as Person student age

 void printinfo(){
cout << "Name: " << Name << ", Age: " << Age << endl;
 }
    
    
} ;

class Student : public Person {
// Derived Class (inheritance)

public:
Person Student;
int Student_Id ;
string Student_Major ;
 void SetStudentName(string Student_Name){ 
Student.Name = Student_Name;
 };
void SetStudentAge(int Student_Age){
    Student.Age = Student_Age;
};
void printStudentinfo(){
Student.printinfo();
cout << "Student Id: " << Student_Id << ", Student Major: " << Student_Major << endl;
}
};


class Course : public Person {
// composition/aggregation
public:
Person Instructor ;
string Course_Name ; 
 void SetInstructorName(string Instructor_Name){ 
Instructor.Name = Instructor_Name;
 };
 void SetInstructorAge(int Instructor_Age){ 
Instructor.Age = Instructor_Age;
 };
void printCourseinfo(){
cout << "Course Name: " << Course_Name << endl;
cout << "Instructor: " ;
Instructor.printinfo();



};
};

int main() {

Student student;
Course course; 
string Instructor_Name;
int Instructor_Age;
int Student_Age;
string Student_Name;

cout << "Enter Instructor's Name: ";
cin >> Instructor_Name ;
course.SetInstructorName(Instructor_Name);
cout << "Enter Instructor's Age: ";
cin >> Instructor_Age ;
course.SetInstructorAge(Instructor_Age);

cout << "Enter Course Name:" ;
cin >> course.Course_Name ;

cout << "Enter Student's Name: " ;
cin >> Student_Name ; 
student.SetStudentName(Student_Name);
cout << "Enter Student's Age: ";
cin >> Student_Age ;
student.SetStudentAge(Student_Age);

cout << "Enter Student's ID: ";
cin >> student.Student_Id ;

cout << "Enter Student's Major: ";
cin >> student.Student_Major;

course.printCourseinfo();
student.printStudentinfo();

return 0;

};