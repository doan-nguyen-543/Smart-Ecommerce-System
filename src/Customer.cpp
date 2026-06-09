#include "../include/Customer.h"
#include <iostream>

using namespace std;

//Constructor initializing Customer via Base class User
Customer::Customer(int id, string username, string password) 
    : User(id, username, password) {}

// Simulates product browsing behavior.
void Customer::browseProducts(Product* prod) {
    if (prod == nullptr) {
        cout << "[Error] Product does not exist!" << endl;
        return;
    }

    // Call the exact view increment method from friend's Product class
    prod->increaseView(); 
    
    // Track metrics into Customer's viewedProducts map
    viewedProducts[prod->getId()]++;

    cout << "\n--- PRODUCT DETAILS ---" << endl;
    prod->display(); 
    cout << "------------------------" << endl;
}

//Adds product and its requested amount into the inner Cart
void Customer::addToCart(Product* prod, int qty) {
    if (prod == nullptr || qty <= 0) {
        cout << "[Error] Invalid product information or quantity!" << endl;
        return;
    }

    cart.addProduct(prod, qty);
}

// Checks out the cart, records history, and empties the cart.
void Customer::checkout() {
    const vector<CartItem>& itemsInCart = cart.getItems();

    if (itemsInCart.empty()) {
        cout << "[Error] Your cart is empty, cannot checkout!" << endl;
        return;
    }

    cout << "\n--- Processing Order Checkout ---" << endl;
    
    // Loop through cart items to execute system side-effects
    for (size_t i = 0; i < itemsInCart.size(); i++) {
        Product* prod = itemsInCart[i].getProduct();
        int qty = itemsInCart[i].getQuantity();

        // Pass the full quantity directly into friend's increaseSold function
        prod->increaseSold(qty);

        // Accumulate inside history tracker map
        purchasedProducts[prod->getId()] += qty;
    }

    cout << "[Success] Order total of " << cart.calculateTotal() 
         << " VND has been paid!" << endl;
    
    cart.clear(); 
}

// Outputs the customer's purchase log history
void Customer::viewOrderHistory() {
    cout << "\n================= YOUR ORDER HISTORY =================" << endl;
    if (purchasedProducts.empty()) {
        cout << "You have not made any purchases yet." << endl;
        cout << "=======================================================" << endl;
        return;
    }

    for (auto const& pair : purchasedProducts) {
        cout << "-> Product ID: " << pair.first << " | Total Quantity Bought: " << pair.second << endl;
    }
    cout << "=======================================================" << endl;
}

Cart& Customer::getCart() {
    return this->cart;
}

//Interface menu for Customer actions
void Customer::displayMenu() {
    cout << "\n================= CUSTOMER MENU =================" << endl;
    cout << "Welcome: " << getUsername() << " (ID: " << getID() << ")" << endl;
    cout << "1. Browse Products" << endl;
    cout << "2. Add to Cart" << endl;
    cout << "3. View Cart Details" << endl;
    cout << "4. Checkout Order" << endl;
    cout << "5. Order Purchase History" << endl;
    cout << "6. Logout System" << endl;
    cout << "=================================================" << endl;
}