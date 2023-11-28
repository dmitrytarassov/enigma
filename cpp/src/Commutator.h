//
// Created by Dmitrii Tarasov on 15/10/2023.
//

#ifndef CPP_COMMUTATOR_H
#define CPP_COMMUTATOR_H

#include "iostream"
#include "Ring.h"

class Commutator {
private:
    std::vector<std::vector<int>> pairs = {};
    std::string config;

    std::string join(const std::vector<std::string>& vec) {
        std::string result;
        for (const auto& word : vec) {
            if (!result.empty()) {
                result += " ";
            }
            result += word;
        }
        return result;
    }

public:
    Commutator(std::vector<std::string> pairs): pairs(Ring::transform(pairs)), config(join(pairs)) {}

    int transform(int input) {
        int output = input;
        for (std::vector<int> config : pairs) {
            if (config[0] == input) {
                output = config[1];
            } else if (config[1] == input) {
                output = config[0];
            }
        }

        return output;
    }
};


#endif //CPP_COMMUTATOR_H
