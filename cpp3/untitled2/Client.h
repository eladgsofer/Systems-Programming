#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Client{
    private:
    String id;
    String name;
    char gender; // 'M' = male, 'F' = female
    double age; // minimal age = 18
    int number_of_hobbies;
    char** list_of_hobbies;
    
    void allocate_list_of_hobbies(const char* const* client_list_of_hobbies);
    void delete_list_of_hobbies();
    bool common_hobby(const Client& other) const;
    bool also_has_hobbie(const char* hobby, const Client& other) const;

    public:
    Client(const String& client_id, const String& client_name, const char client_gender, const double client_age, \
        const int client_number_of_hobbies, const char* const* client_list_of_hobbies);
    Client(const Client& other);
    ~Client();
    Client& operator =(const Client& other);
    bool operator ==(const Client& other) const;
    String& getId();
    String& getName();
    friend std::ostream& operator<<(std::ostream& os, const Client& other);
};