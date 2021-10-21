//
// Created by Elad Sofer on 1/5/21.
//

#ifndef CPP_3_MANAGER_H
#define CPP_3_MANAGER_H
#include "Teacher.h"
#include "AdministrationPersonal.h"

class Manager: public Teacher, public AdministrationPersonal {
public:
    static bool managerExists;

    static bool doesManagerExists();
    static Manager* createManager(char *firstName, char *lastName, double tSeniority, double aSeniority,
                                  const vector<string> &teacherCourses, int coursesAmount,
                                  const string &officeLocation);
    void static deleteManager();

    double getSalary() override;
    bool isExcellent() override;
    void printWorker();

    virtual ~Manager();

private:
    static Manager* currentManager;
    Manager(char *firstName, char *lastName, double tSeniority,  double aSeniority, const vector<string> &teacherCourses,
            int coursesAmount, const string &officeLocation);
    };


#endif //CPP_3_MANAGER_H
