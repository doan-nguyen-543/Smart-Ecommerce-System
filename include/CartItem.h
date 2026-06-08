#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

using namespace std; 

//The class represents an annual item in the shopping cart.
class CartItem {
private:
    Product* product; // Pointer to the actual product in the system
    int quantity;     // Quantity of this product in the cart

public:
    CartItem();
    CartItem(Product* product, int quantity);

    // Calculate the total price for this item only (Product Price * Quantity)
    double getSubTotal() const;

    // Update the new quantity for the item
    void updateQuantity(int newQty);

    // Get the product pointer for another class to use
    Product* getProduct() const;

    // Get the current quantity
    int getQuantity() const;
};

#endif // CARTITEM_H