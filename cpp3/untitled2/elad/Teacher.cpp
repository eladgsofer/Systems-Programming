//
// Created by Elad Sofer on 1/5/21.
//

#include "Teacher.h"
#include "Manager.h"


const vector<string> &Teacher::getTeacherCourses() const {
    return teacherCourses;
}

Teacher::~Teacher() = default;

int Teacher::getCoursesAmount() const {
    return coursesAmount;
}

Teacher::Teacher(const vector<string> &teacherCourses, int coursesAmount) : Worker(), teacherCourses(teacherCourses),
                                                                            coursesAmount(coursesAmount) {}

Teacher::Teacher(char* firstName, char* lastName, double seniority, const vector<string> &teacherCourses,
        int coursesAmount): Person(firstName,lastName), Worker(seniority,0), teacherCourses(teacherCourses), coursesAmount(coursesAmount) {}

Teacher::Teacher() =default;

void Teacher::setTeacherCourses(const vector<string> &courses) {
    this->teacherCourses = courses;
}
double Teacher::getSalary(){
    return Worker::basis*(1 + this->coursesAmount/10.0) + 300*this->tSeniority;
}
void Teacher::setCoursesAmount(int coursesNumber) {
    this->coursesAmount = coursesNumber;
}
void Teacher::printCourses() {
    cout << "TEACHERS' COURSES ARE:\n";
    for (int c=0;c<this->coursesAmount;c++)
    {
        cout << this->teacherCourses[c] << ", ";
    }
    cout << endl;
}
void Teacher::printWorker() {
    // RTTI - IF IT IS A MANAGER SKIP THE PRINT WORKER
    Worker::printWorker();
    this->printCourses();
}

void Teacher::printTeacher() {
    this->printCourses();
}

bool Teacher::isExcellent() {
    return this->coursesAmount>=5;
}
