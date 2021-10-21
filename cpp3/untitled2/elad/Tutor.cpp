/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#include <iostream>
#include "Pupil.h"
#include "Tutor.h"
#include "Class.h"

using namespace std;
Tutor::Tutor() {};

Tutor::Tutor(char* firstName, char* lastName, double tSeniority,
const vector<string> &teacherCourses, Class* classPtr, int coursesAmount) : Person(firstName, lastName), Worker(tSeniority,0),
Teacher(teacherCourses, coursesAmount) , classPtr(classPtr) {}

Tutor::~Tutor(){}

bool Tutor::isExcellent(){
    int count_excellent_pupils = 0;
    size_t total_pupil = this->classPtr->getClassSize();
    Pupil currentPupil;
    for(size_t i = 0; i < total_pupil; i++){
        currentPupil = this->classPtr->getPupil(i);
        if(currentPupil.isExcellent())
            count_excellent_pupils++;
    }
    return ((double)count_excellent_pupils/(double)total_pupil) >= 0.5;
}
double Tutor::getSalary(){
    return 1000 + Teacher::getSalary();
}
void Tutor::printWorker(){
    Teacher::printWorker();
    this->classPtr->printClass();
}
