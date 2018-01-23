#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Student{
    private:
        char* firstName;
        char* lastName;
        float gpa;
        int studentID;
    public:
        Student(char* newFirstName, char* newLastName, float newGpa, int newStudentID);
        char* getLName();
        char* getFName();
        float getGpa();
        int getID();
        ~Student();
};
#endif
