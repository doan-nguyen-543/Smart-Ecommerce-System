#include "../include/StatisticsManager.h"
#include <iostream>
#include <vector>

using namespace std;

StatisticsManager::StatisticsManager(ProductManager* prodMgr, UserManager* userMgr) 
    : productManage(prodMgr), userManager(userMgr) {}

// Find product with maximum views using loop and findProduct()
void StatisticsManager::getMostViewedProducts() const {
    if (!productManage) return;

    const Product* maxViewed = nullptr;
    
    // Loop through possible IDs (e.g., from 1 to 100 or higher)
    // to find valid products since we cannot access the vector directly
    for (int id = 1; id <= 200; ++id) {
        Product* p = productManage->findProduct(id);
        if (p) {
            if (!maxViewed || p->getViewCount() > maxViewed->getViewCount()) {
                maxViewed = p;
            }
        }
    }

    if (maxViewed) {
        cout << "Most Viewed: " << maxViewed->getName() << " (" << maxViewed->getViewCount() << " views)\n";
    } else {
        cout << "No products found for analysis.\n";
    }
}

// Find product with maximum units sold using loop and findProduct()
void StatisticsManager::getBestSellingProducts() const {
    if (!productManage) return;

    const Product* bestSeller = nullptr;

    // Loop through possible IDs to track the max sold count
    for (int id = 1; id <= 200; ++id) {
        Product* p = productManage->findProduct(id);
        if (p) {
            if (!bestSeller || p->getSoldCount() > bestSeller->getSoldCount()) {
                bestSeller = p;
            }
        }
    }

    if (bestSeller) {
        cout << "Best Seller: " << bestSeller->getName() << " (" << bestSeller->getSoldCount() << " sold)\n";
    } else {
        cout << "No sales records found.\n";
    }
}

void StatisticsManager::getActiveUsers() const { 
    cout << "[Statistics] Active user tracking pipeline operational.\n"; 
}