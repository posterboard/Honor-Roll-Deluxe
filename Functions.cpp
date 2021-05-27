#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>
#include <sstream>
#include "Functions.h"
#include "GetData.h"

using namespace std;

//Empty Student Class Constructor
Student::Student() {

}
//Student Class Constructor with Name and # of Courses
Student::Student(string studentName, int numCourses) {
	this->studentName = studentName;
	this->numCourses = numCourses;
}

//Function to ask for the name of the student
void Student::setName() {
	while (true) {
		std::cout << "Please enter your full name" << std::endl;
		getline(cin, studentName);
		if (studentName.size() > 0) {
			break;
		}
		else {
			std::cout << "Invalid Input" << std::endl;
		}
	}
}

//Function to get the name of the student
string Student::getName() {
	return studentName;
}

//Function to ask the user for the number of courses
void Student::setCourses() {
	bool isDecimal = false;
	int totalGrades = 0;
	int grade;
	string courseName;
	string temp;
	while (true) {//limits courses to 1-8

		do {
			std::cout << "How  many courses are you taking?" << std::endl;
			std::cout << "The minimum number of courses is 1, and maximum is 8" << std::endl;
		} while (!getValidInt(numCourses));

		if (isDecimal == false) {
			if (numCourses > 0 && numCourses <= 8) {

				break;
			}
			else {
				std::cout << "Number of courses must be between 1-8" << std::endl;
			}
		}

	}
}

//Function to get the # of courses
int Student::getCourses() {
	return numCourses;
}

//Function to create a list of Course Objects
void Student::getCourseList() {
	//Creating a Course object with Name and Grade
	Course course;
	for (int i = 0; i < numCourses; i++) {
		course.setCourseName();
		course.setCourseGrade();
		//Adding to the Object List
		courses.push_front(course);
	}
}

//Function to Generate a 5% chance of a Discipline Issue
bool Student::getDisciplineIssue() {
	srand(time(NULL));
	double randGen = ((rand() % 100) + 1);
	if (randGen > 95) {
		disciplineIssue = true;
	}
	else {
		disciplineIssue = false;
	}
	return disciplineIssue;
}

//Function to the Average of the Grades
int Student::getAverage() {
	int sum = 0;
	for (int i = 0; i < courses.size(); i++) {
		//Obtaining the object in the list
		list<Course>::iterator it = courses.begin();
		advance(it, i);
		Course course = *it;
		//Getting the Grade and Adding to the sum
		int grade = course.getCourseGrade();
		sum += grade;
	}
	//Calculating, Rounding, and Returning the Average
	double avg = sum / (courses.size());
	this->average = round(avg);
	return this->average;
}

//Function  to Check Elligibility for Honor Roll
bool Student::getHonorRoll() {
	if ((this->average >= 90) & (this->numCourses >= 5) & (this->disciplineIssue == 0)) {
		this->honorRoll = true;
		return 1;
	}
	else {
		this->honorRoll = false;
		return 0;
	}
}

//Function to Print the Information of the Student
void Student::printInfo() {
	std::cout << "\n";
	std::cout << "Name: " << studentName << "\n";
	std::cout << "\n";
	std::cout << "Class                   Grade\n";
	//Printing out the Table with Corresponding Courses and Grades
	for (int i = courses.size() - 1; i >= 0; i--) {
		list<Course>::iterator it = courses.begin();
		advance(it, i);
		Course course = *it;
		string name = course.getCourseName();
		std::cout << name;
		for (int j = 0; j < 25 - name.length(); j++) {
			std::cout << " ";
		}
		std::cout << course.getCourseGrade() << "\n";
	}
	//Printing out the Average, Disciplinary Infraction, and Honor Roll Elligibility
	std::cout << "\n";
	std::cout << "Average is: " << this->average << "\n";
	std::cout << "\n";
	if (this->disciplineIssue == 1) {
		std::cout << "Disciplinary Infraction: YES\n";
	}
	else {
		std::cout << "Disciplinary Infraction: NO\n";
	}
	std::cout << "\n";
	if (this->honorRoll == 1) {
		std::cout << "Congratulations " << this->studentName << "! You have made the honor roll.\n";
	}
	else {
		std::cout << "I'm sorry " << this->studentName << " but you didn't qualify for the honor roll.\n";
	}
}

//Course Contructor
Course::Course() {

}

//Course Contructor with Course Name and Grade
Course::Course(string courseName, int courseGrade) {
	this->courseName = courseName;
	this->courseGrade = courseGrade;
}

//Function to as the User for the Course Name
string Course::setCourseName() {
	string tempName = "";
	while (tempName.empty()) {
		std::cout << "Course Name (1-20 characters): ";
		getline(cin, tempName);
		if (tempName.length() > 20) {
			cout << "Above 20\n";
			tempName = tempName.substr(0, 20);
			this->courseName = tempName;
			return courseName;
		}
		else if (tempName.empty()) {
			cout << "Empty\n";
			std::cout << "\nInvalid Input";
		}
		else {
			cout << "Below 20\n";
			this->courseName = tempName;
		}
	}
}

//Function to get the Course Name
string Course::getCourseName() {
	return courseName;
}

//Function to as the User for the Course Grade
int Course::setCourseGrade() {
	string temp;
	bool isDecimal = false;
	while (true) {//cases 8-11
		do {
			std::cout << "What was your grade for class " + courseName + "?" << std::endl;
			std::cout << "The minimum grade is 0 and the maximum is " + std::to_string(120) << std::endl;
		} while (!getValidInt(courseGrade));
		temp = std::to_string(courseGrade);

		if (isDecimal == false) {
			if (courseGrade >= 0 && courseGrade <= 120) {
				break;
			}
			else {
				std::cout << "Invalid Input" << std::endl;
			}
		}
	}
	return courseGrade;
}

//Function to Return the Course Grade
int Course::getCourseGrade() {
	return courseGrade;
}
