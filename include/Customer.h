#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Cart.h"
#include "Product.h" 
#include <unordered_map>

using namespace std; 

//THIS FILE NEED PRODUCT FILE
class Customer : public User {
private:
    Cart cart;                                // Customer personal cart
    unordered_map<int, int> viewedProducts;   // Key: productID, Value: number of views
    unordered_map<int, int> purchasedProducts;// Key: productID, Value: quantity purchased

public:
    // Initialize customer objects
    Customer(int id, string username, string password);

    //Function to view product details
    void browseProducts(Product* prod);

    //Add a product and the desired quantity to the shopping cart.
    void addToCart(Product* prod, int qty);

    //Pay for the entire cart, update the information in purchasedProducts, and clear the cart.
    void checkout();

    //Review the entire purchase history of this account.
    void viewOrderHistory();

    // Getter function sets the value of the row
    Cart& getCart();

    //// Display the menu interface of Customer functions
    void displayMenu() override;
};

#endif 