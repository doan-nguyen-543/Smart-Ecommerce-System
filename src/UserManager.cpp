#include "../include/UserManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Authenticates login requests by leveraging User::login method.
User* UserManager::login(string username, string password) {
    // 1. Scan through Admin database first using friend's login function
    for (size_t i = 0; i < admins.size(); i++) {
        if (admins[i].login(username, password)) {
            cout << "[Login] Administrator authentication successful!" << endl;
            return &admins[i]; 
        }
    }

    // 2. Scan through Customer database next using friend's login function
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].login(username, password)) {
            cout << "[Login] Customer authentication successful!" << endl;
            return &customers[i]; 
        }
    }

    cout << "[Login Error] Invalid username or password!" << endl;
    return nullptr;
}

//Creates a new Customer account with an auto-incremented ID.
bool UserManager::registerCustomer(string username, string password) {
    // Check if username is already taken by a Customer
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getUsername() == username) {
            cout << "[Register Error] Username '" << username << "' already exists!" << endl;
            return false;
        }
    }
    
    // Check if username is already taken by an Admin
    for (size_t i = 0; i < admins.size(); i++) {
        if (admins[i].getUsername() == username) {
            cout << "[Register Error] Username '" << username << "' already exists!" << endl;
            return false;
        }
    }

    // Auto-generate a unique ID based on size, starting from 1001
    int newId = 1001 + customers.size() + admins.size();
    
    // Instantiate and push back the new customer object
    Customer newCustomer(newId, username, password);
    customers.push_back(newCustomer);
    
    cout << "[Register] Registration successful! Your User ID is: " << newId << endl;
    return true;
}

// Performs a linear search to locate a customer by ID.
Customer* UserManager::findCustomer(int id) {
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getID() == id) {
            return &customers[i];
        }
    }
    return nullptr; 
}

// Parses user records from external database files.
void UserManager::loadUsers() {
    customers.clear();
    admins.clear();

    // 1. Load Customers data
    ifstream custFile("customers.txt");
    if (custFile.is_open()) {
        string line;
        while (getline(custFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string idStr, uname, pword;
            
            if (getline(ss, idStr, ',') && getline(ss, uname, ',') && getline(ss, pword, ',')) {
                customers.push_back(Customer(stoi(idStr), uname, pword));
            }
        }
        custFile.close();
    }

    // 2. Load Admins data
    ifstream adminFile("admins.txt");
    if (adminFile.is_open()) {
        string line;
        while (getline(adminFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string idStr, uname, pword;
            
            if (getline(ss, idStr, ',') && getline(ss, uname, ',') && getline(ss, pword, ',')) {
                admins.push_back(Admin(stoi(idStr), uname, pword));
            }
        }
        adminFile.close();
    }
    
    if (admins.empty()) {
        admins.push_back(Admin(1, "admin", "admin123"));
    }
}

void UserManager::saveUsers() {
    // 1. Save Customers data
    ofstream custFile("customers.txt");
    if (custFile.is_open()) {
        for (size_t i = 0; i < customers.size(); i++) {
            custFile << customers[i].getID() << ","
                     << customers[i].getUsername() << ",default_pass\n";
        }
        custFile.close();
    }

    // 2. Save Admins data
    ofstream adminFile("admins.txt");
    if (adminFile.is_open()) {
        for (size_t i = 0; i < admins.size(); i++) {
            adminFile << admins[i].getID() << ","
                      << admins[i].getUsername() << ",default_pass\n";
        }
        adminFile.close();
    }
}