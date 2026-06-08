#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <vector>
#include <string>
#include "Product.h"

class ProductManager {
private:
    std::vector<Product> products;

public:
    ProductManager();

    void addProduct(const Product& product);
    bool deleteProduct(int id);
    bool editProduct(int id, const Product& newProduct);
    Product* findProduct(int id);

    void displayProducts() const;

    void loadProducts(const std::string& filename);
    void saveProducts(const std::string& filename) const;
};

#endif