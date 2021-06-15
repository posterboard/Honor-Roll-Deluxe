#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "Functions.h"
#include "GetData.h"

using namespace std;
string mainMenu() {

	string menuMode;
	while (true) {
		cout << "Menu:\nA: Enter Student Data\nB:Enter Admin Mode\nC: Run Reports\nD: Exit Program\n";
		getline(cin, menuMode);
		if (menuMode == "A" || menuMode == "B" || menuMode == "C" || menuMode == "D" || menuMode == "a" || menuMode == "b" || menuMode == "c" || menuMode == "d") {
			break;
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
	return menuMode;
}
string formatMenu() {
	cin.ignore();
	string menuMode;
	while (true) {
		cout << "Menu:\nA:Full Honor Roll Report\nB: Honor Roll Report for 1 student\nC:Full GPA report\nD:GPA Report for 1 student\n E: Disciplinary Infractions Report";
		getline(cin, menuMode);
		if (menuMode == "A" || menuMode == "B" || menuMode == "C" || menuMode == "D" || menuMode == "E" || menuMode == "a" || menuMode == "b" || menuMode == "c" || menuMode == "d" || menuMode == "e") {
			break;
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
	return menuMode;
}
/*void writeData(list<Student> gpa, list<string> lastName, list<bool>infraction) {
	ofstream fout;
	fout.open("save.txt");
	std::vector<int> gradeVector{ std::begin(gpa), std::end(gpa) };
	std::vector<std::string>  name{ std::begin(lastName),std::end(lastName) };
	std::vector<bool> infractionVector{ std::begin(infraction),std::end(infraction) };
	for (int i = 0; i < gradeVector.size(); i++) {
		fout << gradeVector[i] << endl;
		fout << name[i] << endl;
		fout << infractionVector[i] << endl;
	}
	fout.close();
}
*/
void writeData(list<Student> gpa) {
	
	ofstream fout;
	fout.open("save.txt");
	std::vector<Student> studentVector{ std::begin(gpa), std::end(gpa) };
	for (int i = 0; i < studentVector.size(); i++) {
		fout << studentVector[i].getName() << endl;
		/*for (int i = 0; i < studentVector[i].getCourses(); i++) { //No sure how to implement yet, but this should be used for getting courses
			fout<<studentVector[i].
		}
		*/
		fout << studentVector[i].getGPA() << endl;
		fout << studentVector[i].getInfraction() << endl;;
	}
	fout.close();
}
//Empty Student Class Constructor 
Student::Student() {

}
//Student Class Constructor with Name and # of Courses
Student::Student(string studentName, int numCourses) {
	this->studentName = studentName;
	this->numCourses = numCourses;
}
void Student::adminMode() {
	std::cout << "Enter admin password: ";
	string password;
	cin >> password;
	if (password == "1111") {
		cout << "Welcome Admin\n";
		cout << "Do you want the student to have a disciplinary issue (y/n): ";
		string issue;
		cin >> issue;
		if ((issue == "y") || (issue == "Y")) {
			this->disciplineIssue = true;
		}
		else {
			this->disciplineIssue = false;
		}
	}
	else {
		cout << "Incorrect Password\n";
	}
}
//Function to ask for the name of the student
void Student::setName() {
	while (true) {
		std::cout << "Please enter your full name: ";
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
			std::cout << "How  many courses are you taking? (1-8): ";
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

//Function to get the name of the student
double Student::getGPA() {
	return GPA;
}

/*list<Student> Student::getStudentList() {
	return studentList;
}
*/
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
bool Student::getInfraction() {// returns whether or not the student has a disipline issue.
	return disciplineIssue;
}
//Function to Print the Information of the Student
void Student::printInfo(std::string report, list<Student> studentList) {
	if (report == "a" || report == "A") {
		for (int i = 0; i < studentList.size(); i++) {
			list<Student>::iterator it = studentList.begin();
			advance(it, i);
			Student student = *it;
			cout << student.getName() << "\n";
			cout << "\nClass                         Grade\n";
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
			std::cout << "GPA: " << student.getAverage() << "\n";
			if (disciplineIssue == true) {
				std::cout << "Discipline Issue: YES\n";
			}
			else {
				std::cout << "Discipline Issue: NO\n";
			}
			if (honorRoll == true) {
				std::cout << "Congratulations " << student.getName() << "! You have made the honor roll.\n";
			}
			else {
				std::cout << "I'm sorry " << student.getName() << " but you didn't qualify for the honor roll.\n";
			}
		}
	}
	else if (report == "b" || report == "B") {

	}
	else if (report == "c" || report == "C") {

	}
	else if (report == "d" || report == "D") {

	}
	else if (report == "e") {

	}
}


list<std::string> Student::alphabetize(list<std::string> unsortedList) {//might change to pass by reference
	std::vector <string> sortedVector{ std::begin(unsortedList),std::end(unsortedList) };
	sort(std::begin(sortedVector), std::end(sortedVector));
	std::list<std::string> sortedList(sortedVector.begin(), sortedVector.end());

	return sortedList;
}
list<int> Student::sortGrades(list<int> grades) {
	//grades.sort(); //another option, sorts the list in ascending order
	std::vector<int> sortedVector{ std::begin(grades), std::end(grades) };
	int i, j;
	int temp;
	int listLength = grades.size();
	for (i = 0; i < (listLength - 1); i++) {//exchange sort algorithm that sorts in desending order.
		for (j = (i + 1); j < listLength; j++) {
			if (sortedVector[i] < sortedVector[j]) {
				temp = sortedVector[i];
				sortedVector[i] = sortedVector[j];
				sortedVector[j] = temp;
			}
		}
	}

	std::list<int> sortedList(sortedVector.begin(), sortedVector.end());
	for (auto v : sortedList) {
		std::cout << v << "\n";
	}
	return sortedList;
}
void Student::readData() {

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
	while (true) {
		std::cout << "Course Name (1-20 characters): ";
		getline(cin, tempName);
		if (tempName.empty()) {
			std::cout << "\nInvalid Input";
		}
		else {
			break;
		}
	}
	if (tempName.length() > 20) {
		tempName = tempName.substr(0, 20);
		this->courseName = tempName;
	}
	else {
		this->courseName = tempName;
	}
	return courseName;
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
			std::cout << "What was your grade for " + courseName + " (0-120): ";
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
