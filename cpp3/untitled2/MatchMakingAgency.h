#pragma once
#include <iostream>
#include "Client.h"
#include "String.h"
#include <vector>
using namespace std;

class MatchMakingAgency{
    private:
    int number_of_clients;
    vector<Client> client_vector;

    public:
    MatchMakingAgency();
    ~MatchMakingAgency();
    MatchMakingAgency& operator =(const MatchMakingAgency& other);
    void all_Client_matches(const String& id);
    bool operator +=(Client other);
    bool operator -=(Client other);
    bool isId_in_client_vector(const String& id);
    size_t find_byId_in_client_vector(const String& id);
    Client& getClient(size_t client_index);
    friend std::ostream& operator<<(std::ostream& os, const MatchMakingAgency& other);
};