#define EQUAL 0

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Client.h"
using namespace std;

Client::Client(const String& client_id, const String& client_name, const char client_gender, const double client_age, \
        const int client_number_of_hobbies, const char* const* client_list_of_hobbies) :

        id(client_id), name(client_name), gender(client_gender), age(client_age), \
        number_of_hobbies(client_number_of_hobbies){
    allocate_list_of_hobbies(client_list_of_hobbies);
}

Client::Client(const Client& other) : id(other.id), name(other.name), gender(other.gender), age(other.age), \
        number_of_hobbies(other.number_of_hobbies){
    allocate_list_of_hobbies(other.list_of_hobbies);
}

Client::~Client(){
    delete_list_of_hobbies();
}

Client& Client::operator =(const Client& other){
    if(this != &other){
        id = other.id;
        name = other.name;
        gender = other.gender;
        age = other.age;
        number_of_hobbies = other.number_of_hobbies;
        delete_list_of_hobbies();
        allocate_list_of_hobbies(other.list_of_hobbies);
    }
    return *this;
}

bool Client::operator ==(const Client& other) const{
    return (gender != other.gender) && (abs(age-other.age) < 6.0) && common_hobby(other);
}

void Client::allocate_list_of_hobbies(const char* const* client_list_of_hobbies){
    list_of_hobbies = new char*[number_of_hobbies];
    for(int i=0; i<number_of_hobbies; i++){
        list_of_hobbies[i] = new char[strlen(client_list_of_hobbies[i])+1];
        strcpy(list_of_hobbies[i], client_list_of_hobbies[i]);
    }
}

void Client::delete_list_of_hobbies(){
    for(int i=0; i<number_of_hobbies; i++){
        delete[] list_of_hobbies[i];
    }
    delete[] list_of_hobbies;
}

bool Client::common_hobby(const Client& other) const{
    for(int i=0; i<number_of_hobbies; i++){
        if(also_has_hobbie(list_of_hobbies[i], other))
            return true;
    }
    return false;
}

bool Client::also_has_hobbie(const char* hobby, const Client& other) const{
    for(int i=0; i<other.number_of_hobbies; i++){
        if(strcmp(hobby, other.list_of_hobbies[i]) == EQUAL)
            return true;
    }
    return false;
}

String& Client::getId(){
    return id;
}

String& Client::getName(){
    return name;
}

std::ostream& operator<<(std::ostream& os, const Client& other){
    os << "\nId:\t" << other.name << "\nName:\t" << other.id << "\nGender:\t" << other.gender << \
    "\nAge:\t" << other.age << "\nList of hobbies:\n";
    for(int i=0; i<other.number_of_hobbies; i++){
        os << '(' << i << ')' << other.list_of_hobbies[i];
        if(i < other.number_of_hobbies-1)
            os << ", ";
        else
            os << endl;
    }
    return os;
}