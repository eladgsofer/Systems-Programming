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
    char* get_firstName() { return firstName;}
    char* get_lastName() { return lastName;}
    // Abstract class
    virtual ~Person()=0;
    void printFullName();
    virtual bool isExcellent() = 0;
};


#endif //CPP_3_PERSON_H
