/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/

#include <iostream>
#include <cstring>
#include <array>
#include "Layer.h"
#include "School.h"

using namespace std;

bool School::schoolExists=false;
School* School::currentSchool = nullptr;

School::School(int layersAmount, Layer **layers, const vector<Pupil *> &pupilsDb, const vector<Worker *> &workersDb)
        : layersAmount(layersAmount), Layers(layers), pupilsDB(pupilsDb), workersDB(workersDb) {

    this->Layers = new Layer*[6];

    for(int i=0; i<6; i++)
        if (i<layersAmount)
            this->Layers[i] = layers[i];
        else
            this->Layers[i] = nullptr;

    School::schoolExists = true;
}

School::School(int layersAmount, Layer **layers) : layersAmount(layersAmount), Layers(layers) {

    this->Layers = new Layer*[6];

    for(int i=0; i<6; i++)
        if (i<layersAmount)
            this->Layers[i] = layers[i];
        else
            this->Layers[i] = nullptr;

    School::schoolExists = true;
}

void School::addPupil(Pupil * pupil) {
    this->pupilsDB.push_back(pupil);
}

void School::addWorker(Worker* worker) {
    this->workersDB.push_back(worker);
}

School::~School() {
    // check valgrind - deleting a singletone should performed outside
}

void School::deleteSchool()
{
    // contemplate the singletone deletion method...
    if (School::schoolExists)
        delete School::currentSchool;
}

bool School::doesSchoolExists() {

    // Singleton design pattern
    if (School::schoolExists)
    {
        cerr << "A manager already exists, cannot appoint another one." << endl;
    }

    return School::schoolExists;
}

School* School::createSchool(int layersAmount, Layer **layers, const vector<Pupil *> &pupilsDb, const vector<Worker *> &workersDb) {

    if (!School::doesSchoolExists())
    {
        School::currentSchool = new School(layersAmount, layers, pupilsDb, workersDb);
    }
    return School::currentSchool;
}

School* School::createSchool(int layersAmount, Layer **layers) {

    if (!School::doesSchoolExists())
    {
        School::currentSchool = new School(layersAmount, layers);
    }
    return School::currentSchool;
}

void School::schoolMenu()
{
    // need to complete the menu
    cout << "Please choose one of the following options:" << endl;
    cout << "==========================================================" << endl;
    cout << "1) Add a new pupil to the database." << endl;
    cout << "2) Add a new teacher to the database." << endl;
    cout << "3) Add a new tutor." << endl;
    cout << "4) Add a new manager." << endl;
    cout << "5) Add a new secretary." << endl;
    cout << "6) Print person details." << endl;
    cout << "7) Print outstanding people." << endl;
    cout << "8) Print tutor's class." << endl;
    cout << "9) Print highest paid worker." << endl;
    cout << "10) Exit" << endl;
    cout << "==========================================================" << endl;
}