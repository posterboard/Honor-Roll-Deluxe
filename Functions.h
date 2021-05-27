#pragma once FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <list>

using namespace std;

//Student Class
class Student {
private:
	//Private Varibale of the Student Class
	string studentName = "";
	int numCourses = 0;
	std::list<class Course> courses;
	bool disciplineIssue = false;
	int average = 0;
	bool honorRoll = false;
public:
	//Creating the Constructor of the Class
	Student();
	Student(string studentName, int numCourses);
	//Defining all of the functions used in the class
	void setName();
	string getName();
	void setCourses();
	int getCourses();
	void getCourseList();
	bool getDisciplineIssue();
	int getAverage();
	bool getHonorRoll();
	void printInfo();
	bool getValidInt(int& t_int);
};
//Course Class
class Course {
private:
	//Private Variables of the Course Name and Grade
	string courseName;
	int courseGrade = -1;
public:
	//Creating the Class Constructor
	Course();
	Course(string courseName, int courseGrade);
	//Defining all of the functions used in the class
	string setCourseName();
	string getCourseName();
	int setCourseGrade();
	int getCourseGrade();
	bool getValidInt(int& t_int);
};
