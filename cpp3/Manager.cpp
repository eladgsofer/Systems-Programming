//
// Created by Elad Sofer on 1/5/21.
//

#include "Manager.h"
#include "Worker.h"


bool Manager::managerExists=false;
Manager* Manager::currentManager = nullptr;

Manager::Manager(char *firstName, char *lastName, double tSeniority,  double aSeniority, const vector<string> &teacherCourses,
                 int coursesAmount, const string &officeLocation) : Person(firstName,lastName), Worker(tSeniority, aSeniority),
                 Teacher(teacherCourses, coursesAmount), AdministrationPersonal(officeLocation) {

    Manager::managerExists=true;
}

Manager::~Manager() {
    cout << "How to delete the manager or it is being deleted in the default dtor?";
}
void Manager::deleteManager()
{
    // contemplate the singletone deletion method...
    if (Manager::managerExists)
        delete Manager::currentManager;
}
bool Manager::doesManagerExists() {

    // Singleton design pattern
    if (Manager::managerExists)
    {
        cerr << "A manager already exists, cannot appoint another one." << endl;
    }

    return Manager::managerExists;
}
Manager* Manager::createManager(char *firstName, char *lastName, double tSeniority, double aSeniority,
                                 const vector<string> &teacherCourses, int coursesAmount,
                                 const string &officeLocation) {

    if (!Manager::doesManagerExists())
    {
        Manager::currentManager = new Manager(firstName, lastName, tSeniority, aSeniority,
                                              teacherCourses, coursesAmount, officeLocation);
    }
    return Manager::currentManager;
}

double Manager::getSalary() {
    double salary=0;

    if (this->coursesAmount > 0)
    {
        salary+=Teacher::getSalary();
    }
    salary+= (Worker::basis*2) + this->AdministrationPersonal::Worker::aSeniority;
    return salary;
}
bool Manager::isExcellent() {
    return (Manager::AdministrationPersonal::aSeniority>3);
}
void Manager::printWorker() {

    AdministrationPersonal::printAdministrationPersonal();

    if (this->coursesAmount > 0)
    {
        // prints teacher details only, without worker details - Worker details is printed via printAdministrationPersonal();
        Teacher::printTeacher();
    }

}

