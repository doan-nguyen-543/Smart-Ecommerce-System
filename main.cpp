#include <iostream>
#include "Product.h"
#include "Admin.h"
#include "User.h"
#include "ProductManager.h"
#include "RecommendationEngine.h"
#include "CartItem.h"
#include "Order.h"
#include "OrderManager.h"
#include "Cart.h"
#include "Customer.h"
#include "ECommerceSystem.h"
#include "FileManager.h"
#include "StatisticsManager.h"
#include "UserManager.h"

using namespace std;

int main() {
    ECommerceSystem system;
    system.run();
    return 0;
}