#ifndef RECOMMENDATIONENGINE_H
#define RECOMMENDATIONENGINE_H

#include <vector>
#include "ProductManager.h"

class RecommendationEngine {
private:
    ProductManager* productManager;

public:
    RecommendationEngine(ProductManager* pm);

    double calculateScore(const Product& product) const;

    std::vector<Product> getTopRecommendations(int topN = 5) const;
};

#endif