#include "../include/Order.h"
#include <iostream>
#include <iomanip>

using namespace std;

Order::Order() {
    orderID = 0;
    customerID = 0;
    totalPrice = 0.0;
    date = "";
}

Order::Order(int orderID, int customerID,
             const vector<CartItem>& items,
             const string& date) {
    this->orderID = orderID;
    this->customerID = customerID;
    this->items = items;
    this->date = date;

    calculateTotal();
}

void Order::calculateTotal() {
    totalPrice = 0;

    for (const CartItem& item : items) {
        totalPrice += item.getSubTotal();
    }
}

void Order::displayOrder() const {
    cout << "\n===== ORDER =====\n";
    cout << "Order ID: " << orderID << endl;
    cout << "Customer ID: " << customerID << endl;
    cout << "Date: " << date << endl;

    cout << "\nItems:\n";
    for (const CartItem& item : items) {
        Product* product = item.getProduct();
        if (product) {
            cout << "  " << product->getName()
                 << " x" << item.getQuantity()
                 << " = $" << fixed << setprecision(2)
                 << item.getSubTotal() << endl;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Price: $" << totalPrice << endl;
}

int Order::getOrderID() const {
    return orderID;
}

int Order::getCustomerID() const {
    return customerID;
}

double Order::getTotalPrice() const {
    return totalPrice;
}

string Order::getDate() const {
    return date;
}

vector<CartItem> Order::getItems() const {
    return items;
}

void Order::setOrderID(int orderID) {
    this->orderID = orderID;
}

void Order::setCustomerID(int customerID) {
    this->customerID = customerID;
}

void Order::setDate(const string& date) {
    this->date = date;
}