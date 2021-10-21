/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#pragma once
#include <iostream>
#include <vector>
#include "Pupil.h"
using namespace std;

class Tutor;

class Class{

protected:
        char className;
        int classNumber;
        vector<Pupil*> pupilVector;
        int classSize;
        Tutor* classTutor_ptr;
    
public:
    Class();
    Class(char className, int classNumber, int classSize, const vector<Pupil *> &pupilVector, Tutor *classTutorPtr);
    ~Class();

    int getClassSize() const;

    // inline doesn't support inheritence although we don't inherit from Class
    Pupil& getPupil(size_t index) {return *pupilVector[index];}
    void addPupil(Pupil* pupil_ptr) {pupilVector.push_back(pupil_ptr);}
    void printClass();
};