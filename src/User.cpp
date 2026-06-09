#include "../include/User.h"
#include <iostream>

using namespace std; 

//Constructor
User::User(int id, string username, string password) {
    this->id = id;
    this->username = username;
    this->password = password;
}

bool User::login(string uname, string pwd) {
    if (this->username == uname && this->password == pwd) {
        return true; 
    }
    return false;   
}

// Getter function to retrieve user ID number
int User::getID() const {
    return this->id;
}

//Getter function to retrieve user login name
string User::getUsername() const {
    return this->username;
}