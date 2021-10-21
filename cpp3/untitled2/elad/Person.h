//
// Created by Elad Sofer on 1/3/21.
//

#ifndef CPP_3_PERSON_H
#define CPP_3_PERSON_H


class Person {
protected:
    char* firstName;
    char* lastName;
public:
    Person();
    Person(char *firstName, char *lastName);
    Person(const Person& other);
    // Abstract class

    virtual ~Person();
    void printFullName();
};


#endif //CPP_3_PERSON_H
