/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/

#include <iostream>
#include "string.h"
#include <array>
#include <iostream>
#include <vector>
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


void School::addPupil(Pupil* pupil) {
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

/*School* School::createSchool() {

    if (!School::doesSchoolExists())
    {
        School::currentSchool = new School
    }
    return School::currentSchool;
}*/

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

void School::menu(){
    int choose;

    while(true){
        schoolMenu();
        cout << "\nPlease choose an option from the menu: ";
        cin >> choose;
        cout << endl;
        switch(choose){
            case 1: //  Add a new pupil to the database.
                addNewPupil();
                break;

            case 2: //  Add a new teacher to the database.
                addNewTeacher();
                break;

            case 3: //  Add a new tutor.
                addNewTutor();
                break;

            case 4: //  Add a new manager.
                addNewManager();
                break;

            case 5: //  Add a new secretary.
                addNewSecretary();
                break;
            
            case 6: //  Print person details.
                // printAllPersonnel();
                cout << "Printing all pupils:" << endl;
                VecAnalyser<Pupil*>(pupilsDB).printAll();
                cout << endl; 
                cout << "Printing all workers:" << endl;
                VecAnalyser<Worker*>(workersDB).printAll();
                cout << endl;
                break;
            
            case 7: //  Print outstanding people.
                printOutstandingPeople();
                break;
            
            case 8: //  Print tutor's class.
                printTutorClass();
                break;
            
            case 9: //  Print highest paid worker.
                // printHighestPaidWorker();
                if(workersDB.size()){
                    cout << "Highest paid worker:" << endl;
                    VecAnalyser<Worker*>(workersDB).printMax();
                }
                else
                    cout << "No workers in this school" << endl;
                break;
            
            case 10: //  Exit
                cout << "Exiting Menu..." << endl;
                return;
                break;

            default:
                cout << "Choice isn't available, try again.\n" << endl;
                continue;
        }
    }
}

void School::printTutorClass(){
    cin.ignore(INT64_MAX, '\n');
    string firstName, lastName;

    cout << "Please enter an existing tutor's first name: ";
    cin >> firstName;
    cout << "Now please enter his last name: ";
    cin >> lastName;
    for(int i=0; i<workersDB.size(); i++){
        
        if(VecAnalyser<Worker*>(workersDB).getIndex(i)->get_firstName() ==  firstName && \
            VecAnalyser<Worker*>(workersDB).getIndex(i)->get_lastName() == lastName && \
            typeid(VecAnalyser<Worker*>(workersDB).getIndex(i)) == typeid(Tutor*)){
                cout << VecAnalyser<Worker*>(workersDB).getIndex(i);
                return;
            }
    }
    cout << "Requested tutor not found" << endl;
}

void School::printOutstandingPeople(){
    bool no_outstanding_pupil = true;
    bool no_outstanding_worker = true;
    for(int i=0; i<pupilsDB.size(); i++){
        if(VecAnalyser<Pupil*>(pupilsDB).getIndex(i)->isExcellent()){
            if(no_outstanding_pupil){
                cout << "Printing all outstanding people:" << endl;
                no_outstanding_pupil = false;
            }
            cout << VecAnalyser<Pupil*>(pupilsDB).getIndex(i);
        }
    }
    if(no_outstanding_pupil == false)
        cout << endl;
    for(int i=0; i<workersDB.size(); i++){
        if(VecAnalyser<Worker*>(workersDB).getIndex(i)->isExcellent()){
            if(no_outstanding_worker){
                cout << "Printing all outstanding workers:" << endl;
                no_outstanding_worker = false;
            }
            cout << VecAnalyser<Pupil*>(pupilsDB).getIndex(i);
        }
    }
    if(no_outstanding_worker == true && no_outstanding_pupil == true)
        cout << "This pathetic school has no excellent pupil and teachers, reality is often disappointing" << endl;
    cout << endl;
}

void School::addNewPupil(){
    cin.ignore(INT64_MAX, '\n');
    Pupil* newPupil_ptr = getPupilInput();
    addPupil(newPupil_ptr);
}

Pupil* School::getPupilInput(){
    char *firstName, *lastName;
    int numberOfGrades, gradeInput;
    vector<int> gradesList;
    char classLayer;
    int classNumber;

    getPersonInput(firstName, lastName);
    cout << "Please enter how many grades the student has already received: ";
    cin >> numberOfGrades;
    cout << endl;
    if(numberOfGrades)
        cout << "Please enter all the student's grades:" << endl;
    for(int i=0; i<numberOfGrades; i++){
        cout << "Grade" << i << ") ";
        cin >> gradeInput;
        cout << endl;
        gradesList.push_back(gradeInput);
    }
    cout << "Please enter class layer: ";
    cin >> classLayer;
    cout << endl;
    cout << "Please enter class number: ";
    cin >> classNumber;
    cout << endl;

    Pupil* newPupil_ptr = new Pupil(firstName, lastName, gradesList, classLayer, classNumber);
    delete[] firstName;
    delete[] lastName;
    return newPupil_ptr;
}

void School::getPersonInput(char* &firstName, char* &lastName){ // dont forget to delete them
    string buffer;

    cout << "Please enter first name: ";
    cin >> buffer;
    cout << endl;
    firstName = new char[buffer.length()];
    strcpy(firstName, buffer.c_str());

    cout << "Please enter last name: ";
    cin >> buffer;
    cout << endl;
    lastName = new char[buffer.length()];
    strcpy(lastName, buffer.c_str());
}

void School::addNewTeacher(){
    cin.ignore(INT64_MAX, '\n');
    Teacher* newTeacher_ptr = getTeacherInput();
    addWorker(newTeacher_ptr);
}

Teacher* School::getTeacherInput(){
    char *firstName, *lastName;
    double seniority; 
    vector<string> teacherCourses;
    int coursesAmount;
    string courseInput;

    getPersonInput(firstName, lastName);
    cout << "Please enter the teacher's seniority: (0 for none)";
    cin >> seniority;
    cout << endl;
    cout << "Please enter the amount of courses this teacher teaches: ";
    cin >> coursesAmount;
    cout << endl;
    if(coursesAmount)
        cout << "Please enter all the teacher's courses:" << endl;
    for(int i=0; i<coursesAmount; i++){
        cout << "Course " << i << "'s name: ";
        cin >> courseInput;
        cout << endl;
        teacherCourses.push_back(courseInput);
    }

    Teacher* newTeacher_ptr = new Teacher(firstName, lastName, seniority, teacherCourses, coursesAmount);
    delete[] firstName;
    delete[] lastName;
    return newTeacher_ptr;
}

void School::addNewTutor(){
    cin.ignore(INT64_MAX, '\n');
    Tutor* newTutor_ptr = getTutorInput();
    addWorker(newTutor_ptr);
}

Tutor* School::getTutorInput(){
    char *firstName, *lastName;
    double tSeniority;
    vector<string> teacherCourses;
    string courseInput;
    Class* classPtr;
    int coursesAmount;
    char classLayer;
    int classNumber;

    getPersonInput(firstName, lastName);
    cout << "Please enter the tutor's seniority: (0 for none)";
    cin >> tSeniority;
    cout << endl;
    cout << "Please enter the amount of courses this tutor teaches: ";
    cin >> coursesAmount;
    cout << endl;
    if(coursesAmount)
        cout << "Please enter all the tutor's courses:" << endl;
    for(int i=0; i<coursesAmount; i++){
        cout << "Course " << i << "'s name: ";
        cin >> courseInput;
        cout << endl;
        teacherCourses.push_back(courseInput);
    }
    cout << "Please enter this tutor's class layer: ";
    cin >> classLayer;
    cout << endl;
    cout << "Please enter this tutor's class number: ";
    cin >> classNumber;
    cout << endl;
    findClass(classLayer, classNumber, &classPtr);

    Tutor* newTutor_ptr = new Tutor(firstName, lastName, tSeniority, teacherCourses, classPtr, coursesAmount);
    delete[] firstName;
    delete[] lastName;
    return newTutor_ptr;
}

void School::addNewManager(){
    cin.ignore(INT64_MAX, '\n');
    Manager* newManager_ptr = getManagerInput();
    addWorker(newManager_ptr);
}

Manager* School::getManagerInput(){
    char *firstName, *lastName;
    double tSeniority;
    double aSeniority;
    vector<string> teacherCourses;
    int coursesAmount;
    string officeLocation;
    string courseInput;

    getPersonInput(firstName, lastName);
    cout << "Please enter the manager's teaching seniority: (0 for none)";
    cin >> tSeniority;
    cout << endl;
    cout << "Please enter the manager's administrating seniority: (0 for none)";
    cin >> aSeniority;
    cout << endl;
    cout << "Please enter the amount of courses this manager teaches: ";
    cin >> coursesAmount;
    cout << endl;
    if(coursesAmount)
        cout << "Please enter all the manager's courses:" << endl;
    for(int i=0; i<coursesAmount; i++){
        cout << "Course " << i << "'s name: ";
        cin >> courseInput;
        cout << endl;
        teacherCourses.push_back(courseInput);
    }
    cout << "Please enter the manager's office's location: ";
    cin >> officeLocation;
    cout << endl;

    Manager* newManager_ptr = new Manager(firstName, lastName, tSeniority, aSeniority, teacherCourses, coursesAmount, officeLocation);
    delete[] firstName;
    delete[] lastName;
    return newManager_ptr;
}

void School::addNewSecretary(){
    cin.ignore(INT64_MAX, '\n');
    Secretary* newSecretary_ptr = getSecretaryInput();
    addWorker(newSecretary_ptr);
}

Secretary* School::getSecretaryInput(){
    int childrenInSchool;
    double aSeniority;
    char* firstName;
    char* lastName;
    string officeLocation;

    getPersonInput(firstName, lastName);
    cout << "Please enter the amount of the secretary's children in school: (0 for none)";
    cin >> childrenInSchool;
    cout << endl;
    cout << "Please enter the secretary's administrating seniority: (0 for none)";
    cin >> aSeniority;
    cout << endl;
    cout << "Please enter the secretary's office's location: ";
    cin >> officeLocation;
    cout << endl;

    Secretary* newSecretary_ptr = new Secretary(childrenInSchool, aSeniority, firstName, lastName, officeLocation);
    delete[] firstName;
    delete[] lastName;
    return newSecretary_ptr;
}

bool School::findClass(char classLayer, int classNumber, Class** classPtr){
    for(int i=0; i<layersAmount; i++)
        if(Layers[i]->getLayerName() == classLayer){
            *classPtr = &(Layers[i]->getClass(classNumber));
            return true;
        }
    return false;
}