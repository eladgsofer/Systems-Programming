//
// Created by Elad Sofer on 1/5/21.
//

#ifndef CPP_3_TEACHER_H
#define CPP_3_TEACHER_H
#include <vector>
#include "Worker.h"

using namespace std;


class Teacher : virtual public Worker{

protected:
    vector<string> teacherCourses;
    int coursesAmount;

public:

    // if a Manager was constructed, the Worker isn skipped!
    Teacher(char* firstName, char* lastName, double seniority, const vector<string> &teacherCourses,
            int coursesAmount);

    Teacher(const vector<string> &teacherCourses, int coursesAmount);
    Teacher();

    const vector<string> &getTeacherCourses() const;
    int getCoursesAmount() const;

    void setTeacherCourses(const vector<string> &teacherCourses);

    void setCoursesAmount(int coursesNumber);
    virtual double getSalary();
    virtual void printWorker();
    virtual bool isExcellent();
    virtual ~Teacher();
    void printTeacher();
    void printCourses();
};

#endif //CPP_3_TEACHER_H
