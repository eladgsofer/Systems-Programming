#pragma once
#include <iostream>
#include "MatchMakingAgency.h"
#include "Client.h"
#include "String.h"
#include <vector>
using namespace std;

class Menu{
    private:
    MatchMakingAgency my_agency;
    int getClientIndex_with_id();
    void print_mainMenu();
    void addClient();
    void removeClient();
    void matchClient();
    Client recieveClient_info();

    public:
    Menu();
    ~Menu();
    void mainMenu();
};