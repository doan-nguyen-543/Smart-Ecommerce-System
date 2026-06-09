#include "../include/Admin.h"
#include <iostream>

using namespace std;

// Default constructor
Admin::Admin()
    : User(0, "", "")
{
}

// Parameterized constructor
Admin::Admin(int id, string username, string password)
    : User(id, username, password)
{
}

// Override displayMenu()
void Admin::displayMenu() {
    cout << "\n===== ADMIN MENU =====" << endl;
    cout << "1. Manage Products" << endl;
    cout << "2. View Statistics" << endl;
    cout << "0. Exit" << endl;
}

// Manage products
void Admin::manageProducts() {
    cout << "Admin is managing products..." << endl;
}

// View statistics
void Admin::viewStatistics() {
    cout << "Admin is viewing statistics..." << endl;
}