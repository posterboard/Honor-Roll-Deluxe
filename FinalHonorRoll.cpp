/*
Name: Brian Huang and Kush Soni
Program Name: Final Honor Roll
Date: 5/27/21
*/
#include <iostream>
#include "Functions.h"
#include <string>
#include <list>
#include <sstream>
#include <stdlib.h> 

using namespace std;

int main()
{
    
    string answer = "y";
    Student student;
    list<Student> studentList = {};
    while (true) {
        string mainMenuChoice = mainMenu();
        if (mainMenuChoice == "A" || mainMenuChoice == "A") {
            while (answer == "y") {
                //Creating a Student Object
                //Asking user for the Name and # of Course taken
                student.setName();
                student.setCourses();
                //Calculating the Average
                student.getCourseList();
                student.getAverage();
                //Retrieving information for honor roll
                student.getHonorRoll();
                //Printing out the Student Information
                studentList.push_front(student);
                std::cout << "Do you want to enter another student: ";
                std::cin >> answer;
            }
        }
        else if (mainMenuChoice == "B" || mainMenuChoice == "b") {
            student.adminMode();
        }
        else if (mainMenuChoice == "C" || mainMenuChoice == "c") {
            student.printInfo(mainMenuChoice, studentList);
            string menuChoice = formatMenu();
        }
        else if (mainMenuChoice == "D" || mainMenuChoice == "d") {
            writeData(studentList);
            exit(EXIT_FAILURE);
        }

    }
    //student.printInfo(mainMenuChoice, student.getStudentList());
   
}