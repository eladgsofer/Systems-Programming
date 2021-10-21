//
// Created by Elad Sofer on 1/9/21.
//
#include <vector>
#include "Pupil.h"
#include "Worker.h"
#include "Layer.h"
#include "VecAnalyser.h"

#ifndef CPP_3_SCHOOL_H
#define CPP_3_SCHOOL_H

//THIS CLASS IS NOT FINISHED
using namespace std;

class Secretary;
class Class;

class School {
public:
    School(int layersAmount, Layer **layers, const vector<Pupil *> &pupilsDb, const vector<Worker *> &workersDb);
    School(int layersAmount, Layer **layers);
    virtual ~School();
    void menu();
    static School* createSchool(int layersAmount, Layer **layers, const vector<Pupil *> &pupilsDb, const vector<Worker *> &workersDb);
    static School* createSchool(int layersAmount, Layer **layers);

private:
    void deleteSchool();
    void addPupil(Pupil*);
    void addWorker(Worker*);
    void schoolMenu();
    void addNewPupil();
    Pupil* getPupilInput();
    void getPersonInput(char* &firstName, char* &lastName);
    void addNewTeacher();
    Teacher* getTeacherInput();
    void addNewTutor();
    Tutor* getTutorInput();
    void addNewManager();
    Manager* getManagerInput();
    void addNewSecretary();
    Secretary* getSecretaryInput();
    bool findClass(char classLayer, int classNumber, Class** classPtr);
    void printOutstandingPeople();
    void printTutorClass();

    static School* currentSchool;
    static bool schoolExists;
    static bool doesSchoolExists();

protected:
    int layersAmount;
    Layer** Layers;
    vector<Pupil*> pupilsDB;
    vector<Worker*> workersDB;
};


#endif //CPP_3_SCHOOL_H
