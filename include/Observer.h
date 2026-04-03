// include/Observer.h
#ifndef OBSERVER_H
#define OBSERVER_H

// 前向宣告，告訴編譯器 Stock 類別存在
class Stock; 

class IObserver {
public:
    // 傳入 Stock 指標，讓觀察者可以自行讀取股價、代號等資訊
    virtual void update(Stock* stock) = 0; 
    virtual ~IObserver() {}
};

#endif