/* Assignment C++: 3
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherer, ID: 315932608
*/
#pragma once
#include <iostream>
#include <vector>
#include "Class.h"
using namespace std;

class Layer{
    protected:
        char* layerName;
        size_t layerSize;
        Class** classPtrArray;
    
    public:
        Layer() = default;;
        Layer(char* layerName, Class** classPtrArray, size_t layerSize);

        ~Layer();
        Class& getClass(size_t index);
};