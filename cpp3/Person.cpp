//
// Created by Elad Sofer on 1/3/21.
//

#include "Person.h"
#include "string.h"
#include <iostream>

using namespace std;

void Person::printFullName()
{
    cout << this->firstName << " " << this->lastName << endl;
}
Person::Person() {}

Person::Person(char *firstName, char *lastName)  {

    this->firstName = new char[strlen(firstName)];
    this->lastName = new char[strlen(lastName)];

    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
}

Person::~Person() {
    delete [] this->firstName;
    delete [] this->lastName;
}
