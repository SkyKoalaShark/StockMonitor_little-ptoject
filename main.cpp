#include <iostream>
#include <memory> // 必須包含
#include "Stock.h"
#include "Display.h"

int main() {
    Stock tsmc("TSM", 140.0f);

    // 使用 make_shared 建立智慧指標物件
    auto board = std::make_shared<PriceDisplay>();
    auto alert = std::make_shared<PriceAlert>(150.0f);

    tsmc.attach(board);
    tsmc.attach(alert);

    std::cout << "--- 模擬智慧指標版股價變動 ---" << std::endl;
    tsmc.setPrice(145.0f);
    tsmc.setPrice(155.0f);

    return 0; // 程式結束時，智慧指標會自動釋放記憶體，完全不需要手動 delete
}