#include "Student.h"
#include "Node.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    char input[40];
    cout<< "Type 'ADD' to add a student." << end;
    cout << "Type 'PRINT' to print all stored students." << endl;
    cout<< "Type 'DELETE' to delete a student." << endl;
    cout << "Type 'QUIT' to exit" << endl;
    cout << "Type 'AVERAGE' to print the average GPA" << endl;
    while(1){
    cout << "Enter a command:"<<endl;
    cin.getline(input, 40);
    
    }
}
