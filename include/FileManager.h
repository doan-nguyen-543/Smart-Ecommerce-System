#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Product.h"
#include "Customer.h"
#include "Admin.h"
#include <vector>

using namespace std;

// Handles file persistent storage for products, users, and orders.
class FileManager {
public:
    FileManager() = default;

    void loadProducts(vector<Product>& products);
    void saveProducts(const vector<Product>& products);

    void loadUsers(vector<Customer>& customers, vector<Admin>& admins);
    void saveUsers(const vector<Customer>& customers, const vector<Admin>& admins);

    void loadOrders();
    void saveOrders();
};

#endif