/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/

#include <iostream>
#include <cstring>
#include "Worker.h"
#include "Person.h"
using namespace std;

double Worker::basis = 25;


Worker::~Worker() {}

Worker::Worker() : tSeniority(0), aSeniority(0) {}
Worker::Worker(double tSeniority, double aSeniority) : tSeniority(tSeniority), aSeniority(aSeniority) {}

void Worker::printWorker(){
    this->printFullName();
    cout << "Worker teaching seniority:\t" << this->tSeniority << endl;
    cout << "Worker administrative seniority:\t" << this->aSeniority << endl;
    cout << "Worker salary is " << this->getSalary() << endl;
}


