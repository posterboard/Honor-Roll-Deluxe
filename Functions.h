#pragma once
#include <string>
#include <list>

using namespace std;

//external methods
void writeData(list<class Student>);
string mainMenu();
string formatMenu();


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
	double GPA = average / 25;
	//for reading data from a text file
	list<int> gpaStudentList;
	list<std::string> lastNamesList;
	list<bool> infractionsList;
public:
	//Creating the Constructor of the Class
	Student();
	Student(string studentName, int numCourses);
	//Defining all of the functions used in the class
	void adminMode();
	void setName();
	string getName();
	void setCourses();
	bool getInfraction();
	int getCourses();
	void getCourseList();
	int getAverage();
	bool getHonorRoll();
	void printInfo(string, list<Student>);
	bool getValidInt(int& t_int);
	void readData();
	list<std::string> alphabetize(list<std::string>);
	list<int> sortGrades(list<int>);
	double getGPA();
	list<Student> getStudentList();
};
//Course Class
class Course {
private:
	//Private Variables of the Course Name and Grade
	string courseName = "";
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