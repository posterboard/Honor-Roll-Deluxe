#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>
#include <regex>
#include <sstream>
#include "GetData.h"
#include "Functions.h"

using namespace std;

bool Student::getValidInt(int& t_int) {
    std::string intScratch = "";
    bool isValid = true;
    std::getline(std::cin, intScratch);
    //remove all whitespace
    regex r("\\s+");
    intScratch = regex_replace(intScratch, r, "");
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

bool Course::getValidInt(int& t_int) {
    std::string intScratch = "";
    bool isValid = true;
    std::getline(std::cin, intScratch);
    //remove all whitespace
    regex r("\\s+");
    intScratch = regex_replace(intScratch, r, "");
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