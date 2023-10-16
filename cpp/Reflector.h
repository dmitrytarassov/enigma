//
// Created by Dmitrii Tarasov on 12/10/2023.
//

#include "iostream"

#ifndef CPP_REFLECTOR_H
#define CPP_REFLECTOR_H


class Reflector {
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string reflector = "";

public:
    Reflector(const std::string& config) : reflector(config) {}

    char reflect(char input, bool isEncryption) {
        if (isEncryption) {
//            std::cout << "Reflector: " << input << " -> " << reflect(input) << std::endl;
            return reflect(input);
        } else {
            return reflectBack(input);
        }
    }

private:
    int findIndex (std::string _alphabet, char input) {
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
