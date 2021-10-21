#define EQUAL 0

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "MatchMakingAgency.h"
#include "Client.h"
using namespace std;

MatchMakingAgency::MatchMakingAgency(): number_of_clients(0) {}

MatchMakingAgency::~MatchMakingAgency(){}

MatchMakingAgency& MatchMakingAgency::operator =(const MatchMakingAgency& other){
    if(this != &other){
        number_of_clients = other.number_of_clients;
        client_vector = other.client_vector;
    }
    return *this;
}

void MatchMakingAgency::all_Client_matches(const String& id){
    if(isId_in_client_vector(id) == false)
        return;
    Client current_client(client_vector[find_byId_in_client_vector(id)]);
    cout << "All matches found for " << current_client.getName() << ":" << endl;
    for(int i; i<number_of_clients; i++){
        if(!(client_vector[i].getId() == id) && current_client == client_vector[i])
            cout << client_vector[i].getName() << "\t" << client_vector[i].getId() << endl;
    }
}

std::ostream& operator<<(std::ostream& os, const MatchMakingAgency& other){
    if(other.number_of_clients != 0)
        for(int i=0; i<other.number_of_clients; i++){
            // Client current_client(other.client_vector[i]);
            os << other.client_vector[i] << "\n~~~~~~~" << endl;
        }
    return os;
}

bool MatchMakingAgency::operator +=(Client other){
    if(isId_in_client_vector(other.getId()) == false){
        client_vector.push_back(other);
        number_of_clients++;
        return true;
    }
    return false;
}

bool MatchMakingAgency::operator -=(Client other){
    if(isId_in_client_vector(other.getId()) == true){
        vector<Client>::iterator client_iteration = client_vector.begin() + find_byId_in_client_vector(other.getId());
        client_vector.erase(client_iteration);
        number_of_clients--;
        return true;
    }
    return false;
}


bool MatchMakingAgency::isId_in_client_vector(const String& id){
    for(int i=0; i<number_of_clients; i++){
        if(client_vector[i].getId() == id)
            return true;
    }
    return false;
}

size_t MatchMakingAgency::find_byId_in_client_vector(const String& id){
    for(int i=0; i<number_of_clients; i++){
        if(client_vector[i].getId() == id)
            return (size_t)i;
    }
    cerr << "no such client" << endl;
    exit(1);
}

Client& MatchMakingAgency::getClient(size_t client_index){
    return client_vector[client_index];
}