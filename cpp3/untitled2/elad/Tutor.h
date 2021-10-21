/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#pragma once
#include <iostream>
#include "Teacher.h"


using namespace std;

class Class;

class Tutor : public Teacher{

    private:
        Class* classPtr;

    public:
        Tutor();
        Tutor(char* firstName, char* lastName, double tSeniority, const vector<string> &teacherCourses, Class* classPtr, int coursesAmount);
        ~Tutor();

        virtual double getSalary();
        bool isExcellent();
        void printWorker();
};