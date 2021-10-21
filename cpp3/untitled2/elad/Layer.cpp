/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/

#include <iostream>
#include "string.h"
#include <array>
#include "Layer.h"

using namespace std;

Layer::Layer(char* layerName, Class** classPtrArray, size_t layerSize): layerSize(layerSize){

    this->layerName = new char[strlen(layerName)];
    strcpy(this->layerName, layerName);

    // notice that - int sizeOfArray = sizeof(classPtrArray) / sizeof(classPtrArray[0]);
    // will always return a size of 1 because sizeof a pointer devide by the size of another pointer is 1

    this->classPtrArray = new Class*[3];

    // in that way we can use one classArray, instead of reallocating the size when a class object is being added.
    // max size is 3 (pdf)

    for(int i=0; i<3; i++)
        if (i<layerSize)
            this->classPtrArray[i] = classPtrArray[i];
        else
            this->classPtrArray[i] = nullptr;
}

Layer::~Layer(){
    delete[] layerName;
    delete[] classPtrArray;
}

Class& Layer::getClass(size_t classIndex){
    return *this->classPtrArray[classIndex];
}