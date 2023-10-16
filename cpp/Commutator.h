//
// Created by Dmitrii Tarasov on 15/10/2023.
//

#ifndef CPP_COMMUTATOR_H
#define CPP_COMMUTATOR_H

#include "iostream"

class Commutator {
private:
    std::vector<std::string> pairs = {};
public:
    Commutator(std::vector<std::string> pairs): pairs(pairs) {}

    char transform(char letter) {
        for (std::string config: pairs) {
            if (config[0] == letter) {
//                std::cout << "Commutator " << letter << " -> " << config[1] << std::endl;
                return config[1];
            } else if (config[1] == letter) {
//                std::cout << "Commutator " << letter << " -> " << config[0] << std::endl;
                return config[0];
            }
        }

//        std::cout << "Commutator " << letter << " = " << letter << std::endl;
        return letter;
    }
};


#endif //CPP_COMMUTATOR_H
