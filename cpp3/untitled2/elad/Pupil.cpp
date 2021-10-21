//
// Created by Elad Sofer on 1/3/21.
//

#include "Pupil.h"
#include <iostream>
using namespace std;


Pupil::Pupil() {}

bool Pupil::isExcellent() {

    return this->getGradesAverage()> 85;
}
double Pupil::getGradesAverage()
{
    int sum=0;
    for (int g : this->gradesList) {
        if (g < 65)
            return false;
        sum += g;
    }
    return sum/(double)this->gradesList.size();
}

void Pupil::printPupil() {
    Person::printFullName();
    cout<< "Layer: \"" << this->classLayer << "\" Class number: " << this->classNumber << endl;
    cout << "GRADE LIST:" << endl;
    for(int i=0;i<this->gradesList.size();i++)
        cout << gradesList[i] << " ";
}

Pupil::Pupil(char *firstName, char *lastName, const vector<int> &gradesList, char classLayer, int classNumber) : Person(
        firstName, lastName), gradesList(gradesList), classLayer(classLayer), classNumber(classNumber) {}

Pupil::~Pupil() {}



