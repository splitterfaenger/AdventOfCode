#include <algorithm>
#include <cstdint>
//#include <format>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
    int total_result{};
    std::ifstream file("rock_paper_scissor_results.txt");
    std::string line{};
    while (std::getline(file, line)) {
        if (!line.empty()) {
            switch (line[0]) {
                case 'A':
                    total_result += (line[2] == 'Y') ? 1 + 3 :
                                    (line[2] == 'X') ? 3 + 0 :
                                    (line[2] == 'Z') ? 2 + 6 :
                                    0;
                    break;
                case 'B':
                    total_result += (line[2] == 'Y') ? 2 + 3 :
                                    (line[2] == 'X') ? 1 + 0 :
                                    (line[2] == 'Z') ? 3 + 6 :
                                    0;
                    break;
                case 'C':
                    total_result += (line[2] == 'Y') ? 3 + 3 :
                                    (line[2] == 'X') ? 2 + 0 :
                                    (line[2] == 'Z') ? 1 + 6 :
                                    0;
                    break;
            }
        }
    }
    std::cout << "Das Endergebnis ist: " << total_result << std::endl;

    return 0;
};