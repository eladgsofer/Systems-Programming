//
// Created by Elad Sofer on 1/9/21.
//
#include <vector>
#include "Pupil.h"
#include "Worker.h"
#include "Layer.h"

#ifndef CPP_3_SCHOOL_H
#define CPP_3_SCHOOL_H

//THIS CLASS IS NOT FINISHED
using namespace std;
class School {
public:
    School(int layersAmount, Layer **layers);

    static School* createSchool(int layersAmount, Layer **layers, const vector<Pupil *> &pupilsDb, const vector<Worker *> &workersDb);
    virtual ~School();
    void deleteSchool();
    void schoolMenu();
    void addPupil(Pupil*);
    void addWorker(Worker*);

private:
    static School* currentSchool;
    static bool schoolExists;
    static bool doesSchoolExists();
    School(int layersAmount, Layer **layers, const vector<Pupil *> &pupilsDb, const vector<Worker *> &workersDb);

protected:
    int layersAmount;
    Layer** Layers;
    vector<Pupil*> pupilsDB;
    vector<Worker*> workersDB;

    School *createSchool(int layersAmount, Layer **layers);
};


#endif //CPP_3_SCHOOL_H
