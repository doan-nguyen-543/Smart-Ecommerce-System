#include "OrderManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

OrderManager::OrderManager() {}

void OrderManager::createOrder(const Order& order) {
    orders.push_back(order);
}

vector<Order> OrderManager::getCustomerOrders(int customerID) const {
    vector<Order> result;

    for (const auto& order : orders) {
        if (order.getCustomerID() == customerID) {
            result.push_back(order);
        }
    }

    return result;
}

void OrderManager::loadOrders(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Cannot open file\n";
        return;
    }

    orders.clear();

    string line;

    while (getline(file, line)) {

        if (line == "ORDER") {

            int orderID, customerID;
            string date;
            int itemCount;

            file >> orderID;
            file >> customerID;
            file >> date;
            file >> itemCount;

            vector<CartItem> items;

            for (int i = 0; i < itemCount; i++) {
                int productID, qty;
                file >> productID >> qty;

                // ⚠️ simplified CartItem (no Product restore)
                CartItem temp(nullptr, qty);
                items.push_back(temp);
            }

            Order order(orderID, customerID, items, date);
            order.calculateTotal();

            orders.push_back(order);

        } else if (line == "END") {
            // skip separator
        }
    }

    file.close();
}

void OrderManager::saveOrders(const string& filename) const {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Cannot open file\n";
        return;
    }

    for (const auto& order : orders) {
        file << "ORDER\n";
        file << order.getOrderID() << "\n";
        file << order.getCustomerID() << "\n";
        file << order.getDate() << "\n";

        vector<CartItem> items = order.getItems();
        file << items.size() << "\n";

        for (const auto& item : items) {
            file << item.getProduct()->getId() << " "
                 << item.getQuantity() << "\n";
        }

        file << "END\n\n";
    }

    file.close();
}

void OrderManager::displayAllOrders() const {
    for (const auto& order : orders) {
        order.displayOrder();
        cout << "----------------------\n";
    }
}