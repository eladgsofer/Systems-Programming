/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#pragma once
#include <iostream>
#include "AdministrationPersonal.h"
using namespace std;

class Secretary : public AdministrationPersonal{
    private:
        int childrenInSchool;
    
    public:
        Secretary();
        ~Secretary();
        Secretary(int childrenInSchool, double aSeniority, char* firstName, char* lastName, const string &officeLocation);
        double getSalary();
        bool isExcellent();
        void printWorker();
};