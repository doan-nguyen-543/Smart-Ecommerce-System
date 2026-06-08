#ifndef CART_H
#define CART_H

#include "CartItem.h"
#include <vector>

using namespace std;

///Manages the user's shopping cart.
class Cart {
private:
    vector<CartItem> items; // List of items currently in the cart

public:
    // Default constructor
    Cart() = default;

    // Adds a product to the cart. Increases quantity if it already exists.
    void addProduct(Product* prod, int qty);

    // Removes a product entirely from the cart based on its ID
    void removeProduct(int productID);

    // Updates the quantity of an existing product in the cart
    void updateQuantity(int productID, int newQty);

    // Calculates the total price of all items combined
    double calculateTotal() const;

    // Empties the cart (used after a successful checkout)
    void clear();

    // Outputs the cart interface and item list to the terminal
    void displayCart() const;

    // Getter allowing the Customer class to process items during checkout
    const vector<CartItem>& getItems() const;
};

#endif // CART_H