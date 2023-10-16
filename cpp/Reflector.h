//
// Created by Dmitrii Tarasov on 12/10/2023.
//

#include "iostream"
#include "Log.h"

#ifndef CPP_REFLECTOR_H
#define CPP_REFLECTOR_H

class Reflector {
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string reflector = "";
    std::string type = "";

public:
    Reflector(const std::string& config, const std::string& type) : reflector(config), type(type) {}

    Reflector static factory(std::string type) {
        if (type == "UKW-A") {
            return Reflector("EJMZALYXVBWFCRQUONTSPIKHGD", type);
        } else if (type == "UKW-B") {
            return Reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT", type);
        } else if (type == "UKW-C") {
            return Reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL", type);
        }

        throw std::invalid_argument("Unknown reflector type");
    }

    char reflect(char input, bool isEncryption) {
        if (isEncryption) {
            Log::log("Reflector", type, input, reflect(input), true);
            return reflect(input);
        } else {
            Log::log("Reflector", type, input, reflectBack(input), true);
            return reflectBack(input);
        }
    }

private:
    int findIndex (std::string& _alphabet, char input) {
        return std::distance(_alphabet.begin(), std::find(_alphabet.begin(), _alphabet.end(), input));
    }

    char reflect(char input) {
        return reflector[findIndex(alphabet, input)];
    }

    char reflectBack(char input) {
        return alphabet[findIndex(reflector, input)];
    }
};


#endif //CPP_REFLECTOR_H
