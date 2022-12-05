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

    std::ifstream file("test.txt");
    std::string line{};
    while (std::getline(file, line)) {
        std::vector<char> storage{};
        if (!line.empty()) {
            for (int i = 0; i <= line.size()/2  ; i++) {
                storage.push_back(line[i]);
            }
            auto middle_of_line = line.begin() + line.size()/2;
            for (char c : storage) {

                if (std::find(middle_of_line, line.end(), c) != line.end()) {
                    int char_store{};
                    char_store = *std::find(middle_of_line, line.end(), c);
                    duplicates_count += char_store >= 97 ? char_store - 96 : char_store - 38 ;
                }
            }
        }
    }


    std::cout << "Das Endergebnis ist: " << duplicates_count << std::endl;

    return 0;
};