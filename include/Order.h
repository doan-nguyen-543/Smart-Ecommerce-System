#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "CartItem.h"

using namespace std;

class Order {
private:
    int orderID;
    int customerID;
    vector<CartItem> items;
    double totalPrice;
    string date;

public:
    Order();
    Order(int orderID, int customerID,
          const vector<CartItem>& items,
          const string& date);

    void calculateTotal();
    void displayOrder() const;

    // Getter
    int getOrderID() const;
    int getCustomerID() const;
    double getTotalPrice() const;
    string getDate() const;
    vector<CartItem> getItems() const;

    // Setter
    void setOrderID(int orderID);
    void setCustomerID(int customerID);
    void setDate(const string& date);
};

#endif