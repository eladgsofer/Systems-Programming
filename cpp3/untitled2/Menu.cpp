#define EQUAL 0
#define SIZE 256
#define NOT_FOUND -1

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Menu.h"
#include "MatchMakingAgency.h"
#include "Client.h"
#include "String.h"
using namespace std;

Menu::Menu(){}

Menu::~Menu(){}

void Menu::mainMenu(){
    int choose;

    while(true){
        print_mainMenu();
        cout << "\nPlease choose an option from the menu: ";
        cin >> choose;
        cout << endl;
        switch(choose){
            case 1:
                addClient();
                break;

            case 2:
                removeClient();
                break;

            case 3:
                cout << "Printing all clients' information:\n" << my_agency << endl;
                break;

            case 4:
                matchClient();
                break;

            case 5:
                cout << "Exiting Menu..." << endl;
                return;
                break;

            default:
                cout << "Choice isn't available, try again.\n" << endl;
                continue;
        }
    }
}

void Menu::print_mainMenu(){
    cout << "Please choose one of the following options:" << endl;
    cout << "==========================================================" << endl;
    cout << "1) Add a new client to the database." << endl;
    cout << "2) Remove an existing client from the database." << endl;
    cout << "3) Print all clients." << endl;
    cout << "4) Print all matches for a client." << endl;
    cout << "5) Quit the program." << endl;
    cout << "==========================================================" << endl;    
}

void Menu::addClient(){
    Client new_client = recieveClient_info();
    if(my_agency += new_client)
        cout << "Client added successfully!\n" << endl;
    else
        cout << "Client already in this agency.\n" << endl;
}

void Menu::removeClient(){
    int client_index = getClientIndex_with_id();
    if(client_index != NOT_FOUND){
        Client client2remove(my_agency.getClient((size_t)client_index));
        my_agency -= client2remove;
        cout << "Client removed successfully!\n" << endl;
    }
    else
        cout << "Client doesn't exist in this agency.\n" << endl;
}

void Menu::matchClient(){
    int client_index = getClientIndex_with_id();
    if(client_index != NOT_FOUND){
        Client client_found(my_agency.getClient((size_t)client_index));
        my_agency.all_Client_matches(client_found.getId());
    }
    else
        cout << "Client doesn't exist in this agency.\n" << endl;
}

int Menu::getClientIndex_with_id(){
    char buffer[SIZE];
    cout << "Please enter existing client id: ";
    cin.ignore(INT64_MAX, '\n');
    cin >> buffer;
    int index = NOT_FOUND;
    if (my_agency.isId_in_client_vector(buffer) == true)
        index = (int)my_agency.find_byId_in_client_vector(buffer);
    return index;
}

Client Menu::recieveClient_info(){
    char buffer[SIZE];
    char gender;
    double age;
    int number_of_hobbies;

    cout << "Please enter new client information next:" << endl;
    cout << "id:\t";
    cin.ignore(INT64_MAX, '\n');
    cin >> buffer;
    String id(buffer);

    cout << "name:\t";
    cin.ignore(INT64_MAX, '\n');
    cin >> buffer;
    String name(buffer);

    while(true){
        cout << "gender: ('M' for male, 'F' for female)\t"; // 'M' = male, 'F' = female
        cin.ignore(INT64_MAX, '\n');
        cin >> gender;
        if(gender == 'M' || gender == 'F')
            break;
        cout << "Wrong input, please choose gender from with a correct input" << endl;
    }

    while(true){
        cout << "age:\t"; // minimal age = 18
        cin.ignore(INT64_MAX, '\n');
        cin >> age;
        if(age >= 18)
            break;
        cout << "Wrong input, please choose age from the correct range" << endl;
    }

    while(true){
        cout << "number of hobbies:\t";
        cin.ignore(INT64_MAX, '\n');
        cin >> number_of_hobbies;
        if(number_of_hobbies >= 0)
            break;
        cout << "Wrong input, please choose a positive number of hobbies" << endl;
    }
    
    cout << "hobbies: (enter exactly " << number_of_hobbies << " hobbies)" << endl;
    char** list_of_hobbies = new char*[number_of_hobbies];
    cin.ignore(INT64_MAX, '\n');

    char* hobbie;
    for(int i = 0; i<number_of_hobbies; i++){
        hobbie = new char[strlen(buffer)+1];
        cout << i+1 << ") ";
        cin >> buffer;
        strcpy(hobbie, buffer);
        list_of_hobbies[i] = hobbie;
    }
    Client new_client(id, name, gender, age, number_of_hobbies, list_of_hobbies);
    for(int i = 0; i<number_of_hobbies; i++){
        delete[] list_of_hobbies[i];
    }
    delete[] list_of_hobbies;
    
    return new_client;
}