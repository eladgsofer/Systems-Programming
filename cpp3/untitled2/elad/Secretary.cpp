/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#include <iostream>
#include "Worker.h"
#include "Secretary.h"
#include "Person.h"
using namespace std;

Secretary::Secretary(int childrenInSchool, double aSeniority, char* firstName, char* lastName, const string &officeLocation) :
AdministrationPersonal(officeLocation), Worker(0, aSeniority), Person(firstName, lastName), childrenInSchool(childrenInSchool){}
Secretary::Secretary() {}

Secretary::~Secretary(){}
void Secretary::printWorker(){
    AdministrationPersonal::printAdministrationPersonal();
    cout << "Number of secretary's children in school: " << childrenInSchool << endl;
}

bool Secretary::isExcellent() {
    return this->aSeniority > 10;
}
double Secretary::getSalary() {
    return Worker::basis + childrenInSchool * 200;
}