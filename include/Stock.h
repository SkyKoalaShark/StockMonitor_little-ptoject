#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <string>
#include <memory> // 必須包含這個！
#include "Observer.h"

class Stock {
private:
    std::string symbol;
    float price;
    // 使用 shared_ptr 管理，確保物件在還有訂閱者時不會被回收
    std::vector<std::shared_ptr<IObserver>> observers; 

public:
    Stock(std::string sym, float p) : symbol(sym), price(p) {}

    // 參數也改成 shared_ptr
    void attach(std::shared_ptr<IObserver> obs) {
        observers.push_back(obs);
    }

    void setPrice(float newPrice) {
        price = newPrice;
        notify();
    }

    void notify() {
        for (auto& obs : observers) {
            obs->update(this); 
        }
    }

    std::string getSymbol() const { return symbol; }
    float getPrice() const { return price; }
};

#endif