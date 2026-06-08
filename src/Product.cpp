#include "Product.h"
#include <iostream>
using namespace std;

// Constructor
Product::Product() {
    id = 0;
    name = "";
    category = "";
    price = 0.0;
    stock = 0;
    viewCount = 0;
    soldCount = 0;
}

Product::Product(int id, string name, string category, double price, int stock) {
    this->id = id;
    this->name = name;
    this->category = category;
    this->price = price;
    this->stock = stock;
    this->viewCount = 0;
    this->soldCount = 0;
}

// Methods
void Product::display() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "Price: " << price << endl;
    cout << "Stock: " << stock << endl;
    cout << "Views: " << viewCount << endl;
    cout << "Sold: " << soldCount << endl;
}

void Product::increaseView() {
    viewCount++;
}

void Product::increaseSold(int quantity) {
    if (quantity > 0 && quantity <= stock) {
        soldCount += quantity;
        stock -= quantity;
    }
}

// Getters
int Product::getId() const {
    return id;
}

string Product::getName() const {
    return name;
}

string Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

int Product::getViewCount() const {
    return viewCount;
}

int Product::getSoldCount() const {
    return soldCount;
}

// Setters
void Product::setPrice(double price) {
    if (price >= 0)
        this->price = price;
}

void Product::setStock(int stock) {
    if (stock >= 0)
        this->stock = stock;
}