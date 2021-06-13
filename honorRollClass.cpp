#include<iomanip>
#include<string>
#include <regex>
#include <stdlib.h>     
#include <time.h>
#include <iostream>
#include <array>
#include "Header.h"

honorRoll::honorRoll() {
}


void honorRoll::setName() {
    while (true) {
        std::cout << "Please enter your full name" << std::endl;
        std::getline(std::cin, name);
        if (name.size() > 0) {
            break;
        }
        else {
            std::cout << "Invalid Input" << std::endl;
        }
    }
}
bool honorRoll::getValidInt(int& t_int) {
    std::string intScratch = "";
    bool isValid = true;


    std::getline(std::cin, intScratch);

 
    
    //remove all whitespace
    std::regex r("\\s+");
    intScratch = std::regex_replace(intScratch, r, "");
    isValid = intScratch.find_first_not_of("-0123456789") == std::string::npos;
    if (std::count(intScratch.begin(), intScratch.end(), '-') > 1) {
        isValid = false;
    }
    else if (std::count(intScratch.begin(), intScratch.end(), '-') > 0) {
        if (intScratch.at(0) != '-') {
            isValid = false;
        }
    }
    // all errors caught
    try {
        t_int = stoi(intScratch);
    }
    catch (...) {
        isValid = false;
        std::cout << "invalid input" << std::endl;
    }
    return isValid;
}
void honorRoll::getCourses() {
    bool isDecimal = false;
    int totalGrades = 0;
    int grade;
    std::string courseName;
    std::string temp;
    while (true) {//limits courses to 1-8

        do {
            std::cout << "How  many courses are you taking?" << std::endl;
            std::cout << "The minimum number of courses is 1, and maximum is 8" << std::endl;
        } while (!getValidInt(courses));

        if (isDecimal == false) {
            if (courses > 0 && courses <= 8) {

                break;
            }
            else {
                std::cout << "Number of courses must be between 1-8" << std::endl;
            }
        }

    }

    for (int i = 0; i < courses; i++) {//gets name and grade of each course
        std::cout << "What is the name of the course? (Note: Course names over 20 characters will be truncated)" << std::endl;
        std::getline(std::cin, courseName);
        if (courseName.length() > 20) {
            temp = courseName.substr(0, 20);
            courseName = temp;
            courseNames[i] = courseName;
        }
        courseNames[i] = courseName;
        while (true) {//cases 8-11
            do {
                std::cout << "What was your grade for class " + courseName + "?" << std::endl;
                std::cout << "The minimum grade is 0 and the maximum is " + std::to_string(MAX_GRADE) << std::endl;
            } while (!getValidInt(grade));
            temp = std::to_string(grade);

            if (isDecimal == false) {
                if (grade >= 0 && (grade <= MAX_GRADE || grade <= 120)) {
                    totalGrades += grade;
                    courseGrades[i] = grade;
                    break;
                }
                else {
                    std::cout << "Invalid Input" << std::endl;
                }
            }
        }
        courseGrades[i] = grade;
    }
    average = totalGrades / courses;

}
void honorRoll::infraction() {
    int randomNumber;

    //random case 13
    srand(time(NULL));
    randomNumber = rand() % 100 + 1;
    if (randomNumber <= 5) {
        hasInfraction = true;
    }
    else {
        hasInfraction = false;
    }
}
void honorRoll::print() {
    std::cout << courses;
    if (hasInfraction == false && average >= 90 && courses >= 5) {
        madeHonorRoll = true;
    }
    else {
        madeHonorRoll = false;
    }

    //case 16
    std::cout << name << std::endl;
    std::cout << std::endl;
    std::cout << "Class";
    for (int i = 0; i < 25; i++) {

        std::cout << " ";
    }
    std::cout << "Grade" << std::endl;
    for (int i = 0; i < courses; i++) {
        std::cout << "#" + std::to_string(i + 1) + ".  ";
        std::cout << courseNames[i];
        for (int j = 0; j < 25 - courseNames[i].length(); j++) {
            std::cout << " ";
        }
        std::cout << courseGrades[i] << std::endl;
    }
    std::cout << "Average: " + std::to_string(average) << std::endl;
    if (hasInfraction == true) {
        std::cout << "Disciplinary Infraction: YES" << std::endl;
    }
    else if (hasInfraction == false)
    {
        std::cout << "Disciplinary Infraction: NO" << std::endl;
    }
    if (madeHonorRoll == true) {
        std::cout << "Congratulations " + name + "! You have made the honor roll." << std::endl;
    }
    else if (madeHonorRoll == false) {
        std::cout << "I'm sorry " + name + " but you didn't qualify for the honor roll." << std::endl;
    }

}

void honorRoll::adminMode() {
	std::cout << "Enter admin password: ";
	string password;
	cin >> password;
	if (password == "1111") {
		cout << "Welcome Admin\n";
		cout << "Do you want the student to have a disciplinary issue (y/n): ";
		string issue;
		cin >> issue;
		if ((issue == "y") || (issue == "Y")){
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
