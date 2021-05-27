#pragma once
class honorRoll {
private:
	int MAX_GRADE = 120;
	std::string courseNames[8] = {};
	int courseGrades[8] = {};
	std::string name;
	int courses;
	int average;
	bool hasInfraction;
	bool madeHonorRoll;
public:
	//methods
	honorRoll();
	void setName();
	void getCourses();
	void infraction();
	bool getValidInt(int& t_int);
	void print();
};