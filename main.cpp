/*Second part of Linked List
 *Allows user to edit a list of students
 *Written by Jason Shi and the Node Class by Connor Shu
 */
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
void deleteStudent(Node* &head, int ID){
    node *current = head;
    node *prev = NULL;
    while(current != NULL){
        
        current = current->getNext();
        delete(current);
        return;
        previous = current;
        current = current->getNext(); 
    }
}
void average(Node* curr){
    float stuNum;
    float totalGpa;
    while(curr != NULL){
        stuNum++;
        totalGpa = ((curr->getContent())->getGpa()) + totalGpa;
        curr = curr->getNext();
    }
    cout << "The average GPA is: "<<totalGpa/stuNum<< endl;
}
void add(Student* temp, Node* &curr){
    //if the current node isn't null
    if(curr!=NULL){
        //next node = the next one from curr
        if(curr->getNext()!=NULL){
            //if the next one isn't null, and it is between the next and current
            if(curr->getContent()->getID() < temp->getID() && curr->getNext()->getContent()->getID() > temp->getID()){
                Node* nextNode = curr->getNext();
                Node* tempNode = new Node(temp);
                //set the new node to next of curr
                curr->setNext(tempNode);
                nextNode->setPrevious(tempNode);
                //set the next node to the curr
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
        char *fName = new char[20];
        char *lName = new char[20];
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
            add(temp, head);
        }else if(strcmp(input, "PRINT")==0){
            print(head);
        }else if(strcmp(input, "DELETE")==0){
            cout << "Enter the student ID you want to delete: ";
            cin >> studentID;
            cin.get();
            delete(head, studentID);
        }else if(strcmp(input, "QUIT")==0){
            break;
        }else if(strcmp(input, "AVERAGE")==0){
            average(head);  
        }
    }
}
