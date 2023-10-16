//
// Created by Dmitrii Tarasov on 15/10/2023.
//

#ifndef CPP_COMMUTATOR_H
#define CPP_COMMUTATOR_H

#include "iostream"
#include "Log.h"

class Commutator {
private:
    std::vector<std::string> pairs = {};

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
    Commutator(std::vector<std::string> pairs): pairs(pairs) {}

    char transform(char input) {
        char output = input;
        for (std::string config: pairs) {
            if (config[0] == input) {
                output = config[1];
            } else if (config[1] == input) {
                output = config[0];
            }
        }

        Log::log("Commutator", join(pairs), input, output, true);
        return output;
    }
};


#endif //CPP_COMMUTATOR_H
