#ifndef STATISTICSMANAGER_H
#define STATISTICSMANAGER_H

#include "ProductManager.h"
#include "UserManager.h"

using namespace std;

/**
 * @brief Generates business analytical insights from products and users data.
 */
class StatisticsManager {
private:
    ProductManager* productManage; ///< Pointer to friend's ProductManager module
    UserManager* userManager;       ///< Pointer to your UserManager module

public:
    StatisticsManager(ProductManager* prodMgr, UserManager* userMgr);

    void getMostViewedProducts() const;
    void getBestSellingProducts() const;
    void getActiveUsers() const;
};

#endif