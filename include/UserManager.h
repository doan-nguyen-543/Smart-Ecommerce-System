#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "Customer.h"
#include "Admin.h"
#include <vector>
#include <string>

using namespace std;

// Singleton-like manager class handling authentication and user data persistence.
class UserManager {
private:
    vector<Customer> customers; // List of registered customers
    vector<Admin> admins;       // List of system administrators

public:
    // Constructor
    UserManager() = default;

    //Authenticates a user based on credentials.
    User* login(string username, string password);

    //Registers a brand new Customer into the system.
    bool registerCustomer(string username, string password);

    // Searches for a customer by their unique ID.
    Customer* findCustomer(int id);

    //Loads all users' data from text files into system vectors.
    void loadUsers();

    //Saves all current users' data from vectors out to text files.
    void saveUsers();
};

#endif