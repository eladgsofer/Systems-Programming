#include <iostream>
#include "AdministrationPersonal.h"
#include "Layer.h"
#include "Pupil.h"
#include "Secretary.h"
#include "Tutor.h"
#include "Worker.h"        
#include "Class.h"
#include "Manager.h"
#include "Person.h"
#include "School.h"
#include "Teacher.h"
#include "VecAnalyser.h"

#include <vector>
using namespace std;


int main()
{
    vector<int> grades;
    grades.push_back(95);
    grades.push_back(83);

    Pupil* p1 = new Pupil("Assaf", "George", grades, 'a', 2);
    vector<Pupil*> pupil_vec;
    pupil_vec.push_back(p1);

    vector<string> course_vec;
    course_vec.push_back("Algebra");
    course_vec.push_back("Geomtry");

    Teacher t("Nimrod", "Sherer", 22, course_vec, 2);

    Worker* nimrod_teacher = &t;

    Worker* elad_manager = Manager::createManager("Elad", "Sofer", 2, 5, course_vec, 2, "BeerSheva");

    Tutor* tutor = nullptr;
    Class* cl = new Class('a', 1, 1,pupil_vec, tutor);
    cout << endl;
    tutor = new Tutor("Assaf","Sharabi", 4.0, course_vec,cl, 2);
    Worker* assaf_tutor = tutor;

    Class** classList = new Class*[3];
    classList[0] = cl;
    Layer* layer1 = new Layer('a', classList, 1);

    Layer** layerList = new Layer*[1];
    layerList[0] = layer1;

    vector<Worker*> workerVec;
    workerVec.push_back(elad_manager);
    workerVec.push_back(assaf_tutor);
    workerVec.push_back(nimrod_teacher);

    /*School* school = School::createSchool();*/
    School* school = School::createSchool(1,layerList,pupil_vec, workerVec);
    school->menu();


    // VecAnalyser<Worker*> workerVecAnalayzer(workerVec);
    // workerVecAnalayzer.printAll();

    // VecAnalyser<Pupil*> pupilVecAnalayzer(pupil_vec);
    // pupilVecAnalayzer.printMax();
}

