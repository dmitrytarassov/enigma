//
// Created by Dmitrii Tarasov on 12/10/2023.
//

#include "iostream"

#ifndef CPP_REFLECTOR_H
#define CPP_REFLECTOR_H

#include "Ring.h"
#include "abstract/IReflector.h"

class Reflector : public IReflector {
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string reflector = "";

    std::vector<int> config;

public:
    std::string type = "";

    Reflector(const std::string& config, const std::string& type) : config(Ring::transform(config)), type(type) {}

    Reflector static factory(std::string type) {
        if (type == "UKW-A") {
            //                ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Reflector("EJMZALYXVBWFCRQUONTSPIKHGD", type);
        } else if (type == "UKW-B") {
            return Reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT", type);
        } else if (type == "UKW-C") {
            return Reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL", type);
        }

        throw std::invalid_argument("Unknown reflector type");
    }

    int reflect(int input) const override {
        return config[input];
    }
};


#endif //CPP_REFLECTOR_H
