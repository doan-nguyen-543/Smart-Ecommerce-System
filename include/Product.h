#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    string category;
    double price;
    int stock;
    int viewCount;
    int soldCount;

public:
    // Constructor
    Product();
    Product(int id, string name, string category, double price, int stock);

    // Methods
    void display() const;
    void increaseView();
    void increaseSold(int quantity = 1);

    // Getters
    int getId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getStock() const;
    int getViewCount() const;
    int getSoldCount() const;

    // Setters
    void setPrice(double price);
    void setStock(int stock);
};

#endif