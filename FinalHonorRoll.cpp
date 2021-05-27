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

using namespace std;

int main()
{
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
}
