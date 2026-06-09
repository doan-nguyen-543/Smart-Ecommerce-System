#include "RecommendationEngine.h"
#include <algorithm>

using namespace std;

RecommendationEngine::RecommendationEngine(ProductManager* pm)
    : productManager(pm) {}

double RecommendationEngine::calculateScore(const Product& product) const {
    double categoryBonus = 0.0;

    // Example bonus rule
    if (product.getCategory() == "Electronics")
        categoryBonus = 5.0;
    else if (product.getCategory() == "Books")
        categoryBonus = 2.0;

    return product.getViewCount() * 0.2
         + product.getSoldCount() * 0.8
         + categoryBonus;
}

vector<Product> RecommendationEngine::getTopRecommendations(int topN) const {
    vector<Product> recommendations =
        productManager->getProducts();

    sort(recommendations.begin(),
         recommendations.end(),
         [this](const Product& a, const Product& b) {
             return calculateScore(a) >
                    calculateScore(b);
         });

    if ((int)recommendations.size() > topN) {
        recommendations.resize(topN);
    }

    return recommendations;
}