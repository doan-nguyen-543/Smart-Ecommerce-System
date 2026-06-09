#include "../include/ProductManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

ProductManager::ProductManager() {}

// ADD
void ProductManager::addProduct(const Product& product) {
    products.push_back(product);
}

// FIND
Product* ProductManager::findProduct(int id) {
    for (auto& p : products) {
        if (p.getId() == id) {
            return &p;
        }
    }
    return nullptr;
}

// DELETE
bool ProductManager::deleteProduct(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;
}

// EDIT
bool ProductManager::editProduct(int id, const Product& newProduct) {
    Product* p = findProduct(id);
    if (!p) return false;

    *p = newProduct;
    return true;
}

// DISPLAY
void ProductManager::displayProducts() const {
    cout << left
         << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Price"
         << setw(8) << "Stock"
         << setw(8) << "Views"
         << setw(8) << "Sold"
         << endl;

    cout << "\n";

    for (const auto& p : products) {
        cout << left
             << setw(5) << p.getId()
             << setw(20) << p.getName()
             << setw(15) << p.getCategory()
             << setw(10) << p.getPrice()
             << setw(8) << p.getStock()
             << setw(8) << p.getViewCount()
             << setw(8) << p.getSoldCount()
             << endl;
    }
}

// SAVE FILE
// Format: id,name,category,price,stock,viewCount,soldCount
void ProductManager::saveProducts(const string& filename) const {
    ofstream out(filename);

    for (const auto& p : products) {
        out << p.getId() << ","
            << p.getName() << ","
            << p.getCategory() << ","
            << p.getPrice() << ","
            << p.getStock() << ","
            << p.getViewCount() << ","
            << p.getSoldCount()
            << "\n";
    }

    out.close();
}

// LOAD FILE
void ProductManager::loadProducts(const string& filename) {
    ifstream in(filename);
    products.clear();

    string line;

    while (getline(in, line)) {
        stringstream ss(line);

        int id, stock, viewCount, soldCount;
        string name, category;
        double price;

        string temp;

        getline(ss, temp, ','); id = stoi(temp);
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, temp, ','); price = stod(temp);
        getline(ss, temp, ','); stock = stoi(temp);
        getline(ss, temp, ','); viewCount = stoi(temp);
        getline(ss, temp, ','); soldCount = stoi(temp);

        Product p(id, name, category, price, stock);

        // set thêm 2 field
        for (int i = 0; i < viewCount; i++) p.increaseView();
        p.increaseSold(soldCount);

        products.push_back(p);
    }

    in.close();
}

const std::vector<Product>& ProductManager::getProducts() const {
    return products;
}