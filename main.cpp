#include "Student.h"
#include "Node.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;


void print(Node* curr){
    if(curr != NULL){
        cout << (curr->getContent())->getFName()  << " " << (curr->getContent())->getLName() << ", "<< (curr->getContent())->getID() << ", " << (curr->getContent())->getGpa() << endl;
        print(curr->getNext());
    }
}
void deleteStudent(Node* ){
    
}
void average(Node* curr){
    float stuNum;
    float totalGpa;
    while(curr != NULL){
        stuNum++;
        totalGpa = ((curr->getContent())->getGpa()) + totalGpa;
        curr = curr->getNext();
    }
    cout << totalGpa/stuNum;
}
void add(Student* temp, Node* &curr){
    if(curr!=NULL){
        Node* nextNode = curr->getNext();
        if(curr->getNext()!=NULL){
            if(curr->getContent()->getID() < temp->getID() && curr->getNext()->getContent()->getID() > temp->getID()){
                Node* tempNode = curr->getNext();
                curr->setNext(new Node(temp));
                nextNode = curr->getNext();
                nextNode->setNext(tempNode);
                return;
            }else if(curr->getContent()->getID() > temp->getID()){
                //set head to the thing and move everything
                return;   
            }
        }else{
            curr->setNext(new Node(temp));
            return;
        }
    }else{
        curr = new Node(temp);
        return;
    }
    Node* nextNode = curr->getNext();
    add(temp, nextNode);    
}

int main(){
    Node *head, *tail;
    head = NULL;
    tail = NULL;
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
            cin.getline(fName, 20);
            cout << "Enter the last name of the student" << endl;
            cin.getline(lName, 20);
            cout << "Enter the student's ID" << endl;
            cin >> studentID;
            cin.get();
            cout << "Enter the student's GPA" << endl;
            cin >> gpa;
            cin.get();
            cout << fName << " " << lName;

            Student* temp = new Student(fName, lName, gpa, studentID);
            cout << "made temp";
            add(temp, head);/*
            if(head == NULL){
                head = new Node(temp);    
            }else{
                
            }
            */

        }else if(strcmp(input, "PRINT")==0){
            print(head);
            //cout << (head->getContent())->getGpa();
            /*
            cout << (head->getContent())->getFName()  << " " << (head->getContent())->getLName() << ", "<< (head->getContent())->getID() << ", " << (head->getContent())->getGpa() << endl;
            */
            /*while(){
                
            }
            */
        }else if(strcmp(input, "DELETE")==0){
            
        }else if(strcmp(input, "QUIT")==0){
            break;
        }else if(strcmp(input, "AVERAGE")==0){
            average(head);  
        }
    }
}
