#include "Student.h"

Student::Student(char* newFirstName, char* newLastName, float newGpa, int newStudentID){
    firstName = newFirstName;
    lastName = newLastName;
    gpa = newGpa;
    studentID = newStudentID;
}

Student::~Student(){
    delete[] firstName;
    delete[] lastName;
}
