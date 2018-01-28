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

//input the head and recursively go through everything
void print(Node* curr){
    if(curr != NULL){
        //print out the first node
        cout << (curr->getContent())->getFName()  << " " << (curr->getContent())->getLName() << ", "<< (curr->getContent())->getID() << ", " << (curr->getContent())->getGpa() << endl;
        //call it recursively 
        print(curr->getNext());
    }
}
void deleteStudent(Node* &head, int ID){
    //make a couple node pointers
    Node *current = head;
    Node *prev = NULL;
    //if current isn't null
    while(current != NULL){
        //check if id matches
        if((current->getContent())->getID == ID){
            //if this isn't head
            if(current!=head{
                if(current->getNext()!=NULL){
                    // set current->last->setnext to current -> next and current -> next _>setlast to current->last
                    current->getPrevious()->setNext() = current->getNext();
                    current->getNext()->setLast() = current->getLast();
                }else{
                    //dont set current->next to current prev
                    current->getPrevious()->setNext() = current->getNext();
                    current->getNext()->setLast() = NULL;
                }
                //delete 
                delete(*current);
            }else{
                //if the identified one is head then set the next node to head and delete the old head
                head = current->getNext();
                delete(*current);
            }
        }
               //iterate through all
        current = current->getNext();
    }
}
void average(Node* curr){
    //make variables
    float stuNum;
    float totalGpa;
    //iterate through everything and add up gpa and num of students
    while(curr != NULL){
        stuNum++;
        totalGpa = ((curr->getContent())->getGpa()) + totalGpa;
        curr = curr->getNext();
    }
    //print out average
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
                //set head to the new one. set next to the old head
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
