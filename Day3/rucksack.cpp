#include <algorithm>
#include <cstdint>
//#include <format>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>





int main() {


    int duplicates_count{};

    std::ifstream file("rucksacks.txt");
    std::string line{};
    int counter{0};
    std::string storage{};
    while (std::getline(file, line)) {
        std::sort(line.begin(), line.end());
        line.erase(std::unique(line.begin(), line.end()), line.end());
        storage += line;
        counter++;
        if (counter ==  3) {
            counter = 0;
            std::sort(storage.begin(), storage.end());
            char b{' '};
            int triple_counter{0};
            for (char c: storage) {
                if (b == c) {
                    triple_counter++;
                }
                if ( b != c) {
                    triple_counter = 0;
                }
                b = c;
                if (triple_counter == 2) {
                    triple_counter = 0;
                    if (c >= 'a' && c <= 'z') {
                        duplicates_count += c - 'a' + 1;
                    }
                    if (c >= 'A' && c <= 'Z') {
                        duplicates_count += c - 'A' + 27;
                    }
                    storage.clear();
                    break;
                }
            }
        }
    }


    std::cout << "Das Endergebnis ist: " << duplicates_count << std::endl;

    return 0;
};