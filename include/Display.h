#ifndef DISPLAY_H
#define DISPLAY_H
// include/Display.h
#include <iostream>
#include "Observer.h"
#include "Stock.h" // 確保這裡能看到 Stock 類別

class PriceDisplay : public IObserver {
public:
    void update(Stock* stock) override {
        // 使用 std::cout 前確保有 #include <iostream>
        std::cout << "[即時看板] " << stock->getSymbol() 
                  << " 價格: " << stock->getPrice() << std::endl;
    }
};

class PriceAlert : public IObserver {
private:
    float threshold;
public:
    PriceAlert(float t) : threshold(t) {}
    void update(Stock* stock) override {
        if (stock->getPrice() >= threshold) {
            std::cout << "[警報] " << stock->getSymbol() << " 達標！" << std::endl;
        }
    }
};

#endif