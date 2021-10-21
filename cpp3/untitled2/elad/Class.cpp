/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#include <iostream>
#include "Tutor.h"
#include "Class.h"
using namespace std;


Class::Class(char className, int classNumber, int classSize, const vector<Pupil *> &pupilVector, Tutor *classTutorPtr)
        :className(className), classNumber(classNumber), pupilVector(pupilVector), classSize(classSize),
          classTutor_ptr(classTutorPtr) {}

Class::Class(){}
Class::~Class(){}

void Class::printClass(){
    cout << "Class name:\t" << className << endl;
    cout << "Class number:\t" << classNumber << endl;
    cout << "Class size:\t" << classSize << endl;

    if(classSize > 0){
        cout << "Pupil list:" << endl;
        for(int i=0; i<classSize; i++)
            pupilVector[i]->printFullName();
    }
}

int Class::getClassSize() const {
    return classSize;
}
