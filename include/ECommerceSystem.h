#ifndef ECOMMERCESYSTEM_H
#define ECOMMERCESYSTEM_H

#include "ProductManager.h"
#include "UserManager.h"
#include "OrderManager.h"
#include "RecommendationEngine.h"
#include "StatisticsManager.h"
#include "Customer.h"
#include "Admin.h"

class ECommerceSystem {
private:
    ProductManager productManager;
    UserManager userManager;
    OrderManager orderManager;

    RecommendationEngine recommender;
    StatisticsManager statistics;
    int nextOrderId;

public:
    ECommerceSystem();

    void run();

    void customerMenu(Customer* customer);
    void adminMenu(Admin* admin);
};

#endif