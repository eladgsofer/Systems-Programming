//
// Created by Elad Sofer on 1/5/21.
//

#include "AdministrationPersonal.h"
#include <iostream>




const string &AdministrationPersonal::getOfficeLocation() const {
    return officeLocation;
}

void AdministrationPersonal::setOfficeLocation(const string &officeLocation) {
    AdministrationPersonal::officeLocation = officeLocation;
}

AdministrationPersonal::AdministrationPersonal(const string &officeLocation) : Worker(), officeLocation(officeLocation) {}

AdministrationPersonal::AdministrationPersonal(char *firstName, char *lastName, double aSeniority,
                                               const string &officeLocation) : Person(firstName, lastName), Worker(0, aSeniority), officeLocation(officeLocation) {}
AdministrationPersonal::AdministrationPersonal() = default;

void AdministrationPersonal::printAdministrationPersonal()
{
    Worker::printWorker();
    cout << "Office Location is " << this->officeLocation << endl;
}