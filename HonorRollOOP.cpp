/*
Name: Brian Huang and Kush Soni
Program Name: Honor Roll Deluxe Baseline
Date: 6/1/21
This is an improvement of Kush's Honor Roll OOP program. I have implemented the data validation function as well as the ability to run the program again.
*/
#include <iostream>
#include "Functions.h"
#include <string>
#include <list>
#include <sstream>

using namespace std;

int main()
{
    bool runAgain = false;
    string answer = "n";
    string name1 = "Honor Roll Deluxe";
    do {
        //Creating a Student Object
        Student student;
        //Asking user for the Name and # of Course taken
        student.setName();
        student.setCourses();
        //Calculating the Average
        student.getCourseList();
        student.getAverage();
        //Getting the Discipline Issue and Eligibility for Honor Roll
        student.getDisciplineIssue();
        student.getHonorRoll();
        //Printing out the Student Information
        student.printInfo();
        cout << "Press y/Y to run again. Any other character to proceed: ";
        getline(cin, answer);
        if (answer == "y" || answer == "Y") {
            runAgain = true;
        }
        else {
            runAgain = false;
        }
    } while (runAgain);
}

