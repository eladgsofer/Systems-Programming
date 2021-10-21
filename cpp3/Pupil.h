//
// Created by Elad Sofer on 1/3/21.
//

#ifndef CPP_3_PUPIL_H
#define CPP_3_PUPIL_H


#include <ostream>
#include "Person.h"
#include <vector>

using namespace std;

class Pupil : public Person{
protected:
    vector<int> gradesList;
    char classLayer;
    int classNumber;


public:

    Pupil();
    Pupil(char *firstName, char *lastName, const vector<int> &gradesList, char classLayer, int classNumber);
    void printPupil();
    double getGradesAverage();
    ~Pupil();

    bool isExcellent();
};


#endif //CPP_3_PUPIL_H
