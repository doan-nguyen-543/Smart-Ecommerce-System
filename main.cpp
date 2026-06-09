#include <iostream>
#include "include/Product.h"
#include "include/Admin.h"
#include "include/User.h"
#include "include/ProductManager.h"
#include "include/RecommendationEngine.h"
#include "include/CartItem.h"
#include "include/Order.h"
#include "include/OrderManager.h"
#include "include/Cart.h"
#include "include/Customer.h"
#include "include/ECommerceSystem.h"
#include "include/FileManager.h"
#include "include/StatisticsManager.h"
#include "include/UserManager.h"

using namespace std;

int main() {
    ECommerceSystem system;
    system.run();
    return 0;
}