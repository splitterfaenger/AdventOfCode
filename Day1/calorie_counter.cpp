#include <algorithm>
#include <cstdint>
//#include <format>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
    int counter{0};
    int store_calories{};
    std::vector<int> elfs{};
    std::ifstream file("calories.txt");
    std::string line{};
    while(std::getline(file, line)) {
        if (line.empty()) {
            elfs.push_back(store_calories);
            store_calories = 0;
            counter++;
        } else {
            store_calories += std::stoi(line);
        }

    }
    auto it = std::max_element(elfs.begin(),elfs.end());
    std::cout << "Der Elf mit den meisten Kalorien ist " << it - elfs.begin() << std::endl;
    std::cout << "Dieser Elf trägt " << *std::max_element(elfs.begin(),elfs.end()) << std::endl;

    std::sort(elfs.begin(),elfs.end(),std::greater<int>());
    store_calories = 0;
    for (int i = 0; i <= 2; i++) {
        store_calories += elfs[i];
    }
    std::cout << "Die drei Elfen mit den meisten Kalorien tragen zusammen: " << store_calories << std::endl;
    return 0;
};