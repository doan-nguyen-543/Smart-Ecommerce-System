#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>

class Admin : public User {
public:
    // Constructors
    Admin();
    Admin(int id, string username, string password);

    // Destructor
    ~Admin() override = default;

    // Override pure virtual function
    void displayMenu() override;

    // Admin functions
    void manageProducts();
    void viewStatistics();
};

#endif