//
// Created by Elad Sofer on 1/3/21.
//

#include "Person.h"
#include <iostream>

using namespace std;

void Person::printFullName()
{
    cout << this->firstName << " " << this->lastName << endl;
}
Person::Person() {}

Person::Person(const Person& other){

    delete [] this->firstName;
    delete [] this->lastName;

    this->firstName = new char[strlen(other.firstName)];
    this->lastName = new char[strlen(other.lastName)];

    strcpy(this->firstName, firstName);
    strcpy(this->lastName, lastName);
}

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
