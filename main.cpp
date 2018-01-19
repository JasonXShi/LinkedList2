#include "Student.h"
#include "Node.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    Node *head, *tail;
    char input[40];
    cout<< "Type 'ADD' to add a student." << endl;
    cout << "Type 'PRINT' to print all stored students." << endl;
    cout<< "Type 'DELETE' to delete a student." << endl;
    cout << "Type 'QUIT' to exit" << endl;
    cout << "Type 'AVERAGE' to print the average GPA" << endl;
    while(1){
        cout << "Enter a command:"<<endl;
        cin.getline(input, 40);
        char fName[20];
        char lName[20];
        int studentID;
        float gpa;
        if(strcmp(input, "ADD")==0){
            cout << "Creating a student..." << endl;
            cout << "Enter the first name of the student" << endl;
            cout << "Enter the last name of the student" << endl;
            cout << "Enter the student's ID" << endl;
            cout << "Enter the student's GPA" << endl;

            if(head == NULL){
                Student* temp = new Student(fName, lName, gpa, studentID);
                head = new Node(temp);    
            } 
        }else if(strcmp(input, "PRINT")==0){
            
        }else if(strcmp(input, "DELETE")==0){
            
        }else if(strcmp(input, "QUIT")==0){
            break;
        }else if(strcmp(input, "AVERAGE")==0){
            
        }
    }
}
