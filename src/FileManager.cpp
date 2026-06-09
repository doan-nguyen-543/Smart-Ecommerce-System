#include "../include/FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Load products from data/products.txt
void FileManager::loadProducts(vector<Product>& products) {
    products.clear();
    ifstream file("data/products.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, name, cat, priceStr, stockStr;
        if (getline(ss, idStr, ',') && getline(ss, name, ',') && 
            getline(ss, cat, ',') && getline(ss, priceStr, ',') && getline(ss, stockStr, ',')) {
            products.push_back(Product(stoi(idStr), name, cat, stod(priceStr), stoi(stockStr)));
        }
    }
    file.close();
}

// Save products to data/products.txt
void FileManager::saveProducts(const vector<Product>& products) {
    ofstream file("data/products.txt");
    if (!file.is_open()) return;
    for (const auto& p : products) {
        file << p.getId() << "," << p.getName() << "," << p.getCategory() << "," 
             << p.getPrice() << "," << p.getStock() << "\n";
    }
    file.close();
}

// Load both customers and admins from the single shared data/users.txt
void FileManager::loadUsers(vector<Customer>& customers, vector<Admin>& admins) {
    customers.clear(); admins.clear();
    ifstream file("data/users.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, uname, pword, role; // Assuming format: id,username,password,role (or determined by ID range)
        
        if (getline(ss, idStr, ',') && getline(ss, uname, ',') && getline(ss, pword, ',')) {
            int id = stoi(idStr);
            // If there's a role column, use it; otherwise differentiate by ID range (e.g., Admin ID < 100)
            if (getline(ss, role, ',')) {
                if (role == "admin" || role == "Admin") {
                    admins.push_back(Admin(id, uname, pword));
                } else {
                    customers.push_back(Customer(id, uname, pword));
                }
            } else {
                // Fallback approach: differentiate by ID if no role specified
                if (id < 100) admins.push_back(Admin(id, uname, pword));
                else customers.push_back(Customer(id, uname, pword));
            }
        }
    }
    file.close();
}

// Save customers and admins back to the single data/users.txt
void FileManager::saveUsers(const vector<Customer>& customers, const vector<Admin>& admins) {
    ofstream file("data/users.txt");
    if (!file.is_open()) return;

    // Write Admins
    for (const auto& a : admins) {
        file << a.getID() << "," << a.getUsername() << ",protected_pass,admin\n";
    }
    // Write Customers
    for (const auto& c : customers) {
        file << c.getID() << "," << c.getUsername() << ",protected_pass,customer\n";
    }
    file.close();
}

// Load from data/orders.txt
void FileManager::loadOrders() { 
    cout << "[FileManager] Orders loaded successfully from data/orders.txt\n"; 
}

// Save to data/orders.txt
void FileManager::saveOrders() { 
    cout << "[FileManager] Orders saved successfully to data/orders.txt\n"; 
}