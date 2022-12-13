#include <algorithm>
#include <cstdint>
//#include <format>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <regex>

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


std::vector<std::string> readAllCrateLinesToVector(std::ifstream &file) {
    bool end_of_crates{false};
    std::string line{};
    std::vector<std::string> rtrn_vector{};
    while (!end_of_crates && std::getline(file, line)) {
        if (std::isdigit(line[1])) {
            end_of_crates = true;
            break;
        }
        rtrn_vector.push_back(line);
    }
    return rtrn_vector;
}

std::vector<std::vector<char>> readStacksOfCratesFromInput(std::ifstream &file) {
    std::vector<std::vector<char>> crates{};
    std::vector<std::string> crates_line_by_line{readAllCrateLinesToVector(file)};
    bool end_of_crates{false};
    //for (auto it = crates_line_by_line.rbegin(); it != crates_line_by_line.rend(); it++) {
    for (auto it = crates_line_by_line.begin(); it != crates_line_by_line.end(); it++) {
        std::vector<char> puffer_vector{};
        std::string line{*it};
        for (size_t i = 0; i < line.length(); i++) {
            if (!std::isupper(line[i])) continue;
            size_t stack = (i-1)/4;
            if (crates.size() <= stack) crates.resize(stack + 1);
            crates[stack].push_back(line[i]);
       }
    }
    // Vektoren umdrehen
    for (auto it = crates.begin(); it != crates.end(); it++) {
        std::vector<char> puffer{*it};
        std::reverse(puffer.begin(),puffer.end());
        *it = puffer;
    }
    return crates;
}

std::vector<std::vector<int>> readMoveOrders(std::ifstream &file) {
    std::string line{};
    std::vector<std::vector<int>> move_orders{};
    while (std::getline(file, line)) {
        std::vector<int> puffer_orders_of_one_line{};
        bool last_char_was_number{false};
        for (char c : line) {
            if ( '0' <= c && c <= '9' && last_char_was_number) { //dieser Code kann aus irgendwelchen Gründen nicht erreicht werden
                int i = puffer_orders_of_one_line.size();
                puffer_orders_of_one_line[i-1] += c -48;
            }
            if ( '0' <= c && c <= '9' && !last_char_was_number) {
                last_char_was_number = true;
                puffer_orders_of_one_line.push_back(c - 48);
            }
            last_char_was_number = false;
        }
        move_orders.push_back(puffer_orders_of_one_line);

    }
    return move_orders;
}


int main() {
    std::ifstream file("stacks_of_crates.txt");
    std::ofstream check_file("check.txt");
    std::string line{};
    std::vector<std::vector<char>> crate_stacks{};

    // Regex stuff
    std::string crate_regex{"((...)|(\\[[A-Z]\\]))"};
    std::stringstream ss{};
    ss << "{" << crate_regex << "} {" << crate_regex << "} {" << crate_regex << "} {" << crate_regex << "} {"
                    << crate_regex << "} {" << crate_regex << "} {" << crate_regex << "} {" << crate_regex << "} {"
                    << crate_regex << "}";
    //std::regex crate_line_regex{std::format{"{0} {0} {0} {0} {0} {0} {0} {0} {0}", crate_regex}};

    crate_stacks = readStacksOfCratesFromInput(file);

    auto stuff = readMoveOrders(file);

    while (std::getline(file, line)) {


        /*
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
           */

    }

    //std::cout << "Das Endergebnis ist: " << pairs_inside_pairs_counter << std::endl;
    //std::cout << "Das Endergebnis ist: " << pairs_overlap_pairs_counter << std::endl;
    //std::cout << "Hallo";
    return 0;
};