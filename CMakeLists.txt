# cmake_minimum_required(VERSION 3.10.0)
# project(StockMonitor VERSION 0.1.0 LANGUAGES C CXX)

# add_executable(StockMonitor main.cpp)

cmake_minimum_required(VERSION 3.10)
project(StockMonitor)

# 使用 C++17 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 告訴編譯器去哪裡找 .h 檔案
include_directories(include)

# 自動搜尋 src 資料夾下所有的 .cpp 檔案，並包含 main.cpp
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# 產出的執行檔名稱
add_executable(StockMonitor ${SOURCES})