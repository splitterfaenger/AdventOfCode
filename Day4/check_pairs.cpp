#include <algorithm>
#include <cstdint>
//#include <format>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


bool checkIfPairIsInsidePair(const std::pair<int,int> &p1,const std::pair<int,int> &p2 ) {
    if(p2.first <= p1.first && p1.first <= p2.second) {
        if (p2.first <= p1.second && p1.second <= p2.second ) {
            return true;
        }
    }
    return false;
};

bool checkIfPairsOverlap(const std::pair<int,int> &p1,const std::pair<int,int> &p2 ) {
    if(p2.first <= p1.first && p1.first <= p2.second) {
        return true;
    }
    if (p2.first <= p1.second && p1.second <= p2.second ) {
        return true;
    }
    return false;
};

bool checkIfcheckIfPairIsInsidePairIsWrong(const std::pair<int,int> &p1,const std::pair<int,int> &p2 ) {
    return p2.first <= p1.first & p1.second <= p2.second;
}


int main() {
    std::ifstream file("pairs.txt");
    std::ofstream check_file("pairs_check.txt");
    std::ofstream check_file_stdpair("stdpair_check.txt");
    std::string line{};

    int pairs_inside_pairs_counter{0};
    int pairs_overlap_pairs_counter{0};
    int counter{};
    while (std::getline(file, line)) {
        std::pair<int,int> first_pair{};
        std::pair<int,int> second_pair{};
        if(check_file.is_open()) {
            check_file << line << std::endl;
        }
        counter++;
        const auto first_minus {line.find('-')};
        const auto comma{line.find(',')};

        first_pair.first = std::stoi(line.substr(0,first_minus));
        first_pair.second = std::stoi(line.substr(first_minus+1,comma - (first_minus +1)  ));

        const auto second_minus{line.find('-', comma)};
        second_pair.first = std::stoi(line.substr(comma +1, second_minus));
        second_pair.second = std::stoi(line.substr(second_minus +1 ,line.size()));
        if(check_file_stdpair.is_open()) {
            check_file_stdpair << first_pair.first << '-' << first_pair.second << ','
                                << second_pair.first << '-' << second_pair.second << std::endl;
        }

        if (first_pair == second_pair) {
            pairs_inside_pairs_counter += 1;
            pairs_overlap_pairs_counter +=1;
        } else {
            if (checkIfPairsOverlap(first_pair,second_pair)) {
                pairs_overlap_pairs_counter += 1;
            } else if (checkIfPairsOverlap(second_pair,first_pair)) {
                pairs_overlap_pairs_counter += 1;
            }

            if (checkIfcheckIfPairIsInsidePairIsWrong(first_pair,second_pair)) {
                pairs_inside_pairs_counter += 1;
            } else if (checkIfcheckIfPairIsInsidePairIsWrong(second_pair,first_pair)) {
                pairs_inside_pairs_counter += 1;
            }
        }

    }

    std::cout << "Das Endergebnis ist: " << pairs_inside_pairs_counter << std::endl;
    std::cout << "Das Endergebnis ist: " << pairs_overlap_pairs_counter << std::endl;
    //std::cout << "Hallo";
    return 0;
};