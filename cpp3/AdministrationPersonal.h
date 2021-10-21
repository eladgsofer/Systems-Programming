//
// Created by Elad Sofer on 1/5/21.
//

#ifndef CPP_3_ADMINISTRATIONPERSONAL_H
#define CPP_3_ADMINISTRATIONPERSONAL_H
#include <iostream>
#include "Worker.h"

using namespace std;
class AdministrationPersonal: virtual public Worker {
public:
    AdministrationPersonal();
    explicit AdministrationPersonal(const string &officeLocation);

    AdministrationPersonal(char *firstName, char *lastName, double aSeniority,
                           const string &officeLocation);

    const string &getOfficeLocation() const;
    virtual double getSalary()=0;
    virtual bool isExcellent()=0;
    virtual void printAdministrationPersonal();
    void setOfficeLocation(const string &officeLocation);

private:
    string officeLocation;


};



#endif //CPP_3_ADMINISTRATIONPERSONAL_H
