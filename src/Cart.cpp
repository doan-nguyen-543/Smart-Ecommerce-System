#include "../include/Cart.h"
#include "../include/Product.h"
#include <iostream>

using namespace std;

// Adds a product to the cart. 
void Cart::addProduct(Product* prod, int qty) {
    if (prod == nullptr || qty <= 0) return;

    // Check if the product already exists in the cart using getId()
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getProduct()->getId() == prod->getId()) {
            items[i].updateQuantity(items[i].getQuantity() + qty);
            cout << "[Cart] Updated quantity for existing product." << endl;
            return;
        }
    }

    // If it's a new product, create a CartItem and push it to the vector
    CartItem newItem(prod, qty);
    items.push_back(newItem);
    cout << "[Cart] Added new product to the cart successfully." << endl;
}

//Removes a product completely from the cart by its ID.
void Cart::removeProduct(int productID) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getProduct()->getId() == productID) {
            items.erase(it); // Remove from vector
            cout << "[Cart] Product removed from cart." << endl;
            return;
        }
    }
    cout << "[Cart] Product not found in cart." << endl;
}

//Updates the quantity of a product. Removes it if new quantity is 0 or less.
void Cart::updateQuantity(int productID, int newQty) {
    if (newQty <= 0) {
        removeProduct(productID); // Default behavior: 0 quantity means removal
        return;
    }

    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getProduct()->getId() == productID) {
            items[i].updateQuantity(newQty);
            cout << "[Cart] Quantity updated successfully." << endl;
            return;
        }
    }
}

// Sums up the subtotals of all CartItems.
double Cart::calculateTotal() const {
    double total = 0.0;
    for (size_t i = 0; i < items.size(); i++) {
        total += items[i].getSubTotal();
    }
    return total;
}

// Clears all items from the vector.
void Cart::clear() {
    items.clear();
}

//Displays the current state of the cart to the terminal.
void Cart::displayCart() const {
    cout << "\n------------ CURRENT SHOPPING CART ------------" << endl;
    if (items.empty()) {
        cout << "Your cart is empty!" << endl;
        cout << "-----------------------------------------------" << endl;
        return;
    }

    for (size_t i = 0; i < items.size(); i++) {
        Product* p = items[i].getProduct();
        cout << i + 1 << ". ID: " << p->getId() 
             << " | Qty: " << items[i].getQuantity()
             << " | Subtotal: " << items[i].getSubTotal() << " VND" << endl;
    }
    cout << "=> TOTAL AMOUNT: " << calculateTotal() << " VND" << endl;
    cout << "-----------------------------------------------" << endl;
}

const vector<CartItem>& Cart::getItems() const {
    return this->items;
}