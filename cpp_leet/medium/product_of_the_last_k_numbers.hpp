#pragma once

#include "./../imports.hpp"

class ProductOfNumbers {
private:
    vector<int> products;
    size_t size;
public:
    ProductOfNumbers() {
        this->products.assign({1});
        this->size = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            this->products.assign({1});
            this->size = 0;
        } else {
            this->products.push_back(num * products.back());
            ++this->size;
        }
    }
    
    int getProduct(int k) {
        if (k > this->size) {
            return 0;
        }
        return this->products.back() / this->products[products.size() - k - 1];
    }
};