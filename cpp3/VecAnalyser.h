//
// Created by Elad Sofer on 1/10/21.
//




#pragma once

#include <iostream>
#include <string.h>
#include <vector>

#include "Worker.h"
#include "Pupil.h"
#include "Person.h"
#include "Manager.h"


using namespace std;

template <class T> class VecAnalyser {
private:
    vector<T> currentVector;
    char type;

public:
    VecAnalyser() {};

    VecAnalyser(const vector<T> &entityVector) : currentVector(entityVector) {

        if (typeid(T) == typeid(Worker *))
            this->type = 'W';
        else if (typeid(T) == typeid(Pupil *))
            this->type = 'P';
        else
            throw "Object type isn't supported!";
    }

    T getIndex(int index) {
        this->generateIndexException(index);
        return this->currentVector[index];
    }

    void swap(int indexA, int indexB) {
        this->generateIndexException(indexA, indexB);
        T tmp = this->currentVector[indexA];
        this->currentVector[indexA] = this->currentVector[indexB];
        this->currentVector[indexB] = tmp;
    }
    bool RTTI(int index)
    {
        this->generateIndexException(index);
        if (typeid(*this->currentVector[index])== typeid(Manager))
        {
            cout << "Index " << index << " is a manager!" << endl;
            return true;
        }
        cout << "Index " << index << " is not a manager!" << endl;
        return false;
    }
    bool isIndexValid(int index) {
        return (index >= 0 && index < (int)this->currentVector.size());
    }
    void generateIndexException(int indexA, int indexB=-1) {
        string ex;
        if (this->currentVector.size() == 0) {
            ex = "the vector is empty!";
            cerr << ex;
            throw ex;
        }
        ex = "Indexs:";
        if (!this->isIndexValid(indexA))
            ex += " " + to_string(indexA);
        if (!this->isIndexValid(indexB) && indexB!=-1)
            ex += " " + to_string(indexB);

        if (ex != "Indexs:") {
            ex += (" - aren't valid! valid index range is 0 to " + to_string(this->currentVector.size()));
            cerr << ex << endl;
            throw ex;
        }
    }
    void printElement(int index){
        this->generateIndexException(index);
        if (typeid(this->currentVector[index])== typeid(Worker*)) {
            Worker *worker = dynamic_cast<Worker *>(this->currentVector[index]);
            worker->printWorker();
        }
        else {
            Pupil *pupil = dynamic_cast<Pupil *>(this->currentVector[index]);
            pupil->printPupil();
        }
    }
    void printMax() {
        if (this->currentVector.empty()) {
            cout << "The vector is empty!" << endl;
            return;
        }
        double maxSalaryOrGrades = 0.0;
        double personExcellencyParam;
        int bestPersonIndex;

        for (int i = 0; i < (int)this->currentVector.size(); i++) {
            if (this->type == 'W') {
                Worker *worker = dynamic_cast<Worker *>(this->getIndex(i));
                personExcellencyParam = worker->getSalary();

            }
            else {
                Pupil *pupil = dynamic_cast<Pupil *>(this->getIndex(i));
                personExcellencyParam = pupil->getGradesAverage();
            }

            if (personExcellencyParam > maxSalaryOrGrades) {
                maxSalaryOrGrades = personExcellencyParam;
                bestPersonIndex = i;
            }

        }

        cout << "==========================================================" << endl;
        cout << "The most highest value person is " << endl;
        this->printElement(bestPersonIndex);
    }
    void printAll()
    {
        for (int i=0;i<(int)this->currentVector.size();i++) {
            cout << "==========================================================" << endl;
            cout << "Element " << i << ": " <<endl;
            this->printElement(i);
        }

    }
};