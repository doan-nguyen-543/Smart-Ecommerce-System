#include "../include/CartItem.h"
#include "../include/Product.h"

using namespace std;

// Constructor
CartItem::CartItem() {
    this->product = nullptr;
    this->quantity = 0;
}

// Parameterized constructor
CartItem::CartItem(Product* product, int quantity) {
    this->product = product;
    this->quantity = quantity;
}

//Calculates the total cost for this specific item.
double CartItem::getSubTotal() const {
    if (this->product == nullptr) return 0.0;
    return this->product->getPrice() * this->quantity;
}

/// Updates the quantity if the new value is valid.
void CartItem::updateQuantity(int newQty) {
    if (newQty > 0) {
        this->quantity = newQty;
    }
}

Product* CartItem::getProduct() const {
    return this->product;
}

int CartItem::getQuantity() const {
    return this->quantity;
}