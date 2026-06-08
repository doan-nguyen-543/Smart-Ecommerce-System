#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <vector>
#include <string>
#include "Order.h"

using namespace std;

class OrderManager {
private:
    vector<Order> orders;

public:
    OrderManager();

    // Create a new order and add to system
    void createOrder(const Order& order);

    // Get all orders of a specific customer
    vector<Order> getCustomerOrders(int customerID) const;

    // Load orders from file
    void loadOrders(const string& filename);

    // Save orders to file
    void saveOrders(const string& filename) const;

    // Optional helper
    void displayAllOrders() const;
};

#endif