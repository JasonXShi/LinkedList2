#include "Student.h"

Student::Student(char* newFirstName, char* newLastName, float newGpa, int newStudentID){
    firstName = newFirstName;
    lastName = newLastName;
    gpa = newGpa;
    studentID = newStudentID;
}
char* Student::getFName(){
    return firstName;
}
char* Student::getLName(){
    return lastName;
}
float Student::getGpa(){
    return gpa;
}
int Student::getID(){
    return studentID;
}
Student::~Student(){
    delete[] firstName;
    delete[] lastName;
}
