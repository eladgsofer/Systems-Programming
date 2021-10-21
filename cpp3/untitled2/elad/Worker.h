/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Worker : virtual public Person{
protected:
    double tSeniority;
    double aSeniority;
public:
    static double basis;

    Worker();
    Worker(double tSeniority, double aSeniority);
    ~Worker();

    // ABSTRACT class, constructors are only for inheritance usage, gettr/settr aren't needed.
    // no need for Worker(char *firstName, char *lastName, double tSeniority, double aSeniority); - because object cannot be initialize from "main.cpp" anyway.
    virtual double getSalary()=0;
    virtual void printWorker()=0;



};


