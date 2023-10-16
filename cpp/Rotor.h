//
// Created by Dmitrii Tarasov on 11/10/2023.
//

#ifndef CPP_ROTOR_H
#define CPP_ROTOR_H

#include <iostream>
#include <string>
#include <algorithm>

#include "Log.h"

class Rotor {
private:
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string configuration = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int basePosition = 1;
    int position = 0;
    std::string type;

public:
    static Rotor factory(std::string type, const int position) {
        if (type == "I") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", position, type);
        } else if (type == "II") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", position, type);
        } else if (type == "III") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", position, type);
        } else if (type == "IV") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB", position, type);
        } else if (type == "V") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("VZBRGITYUPSDNHLXAWMJQOFECK", position, type);
        }

        throw std::invalid_argument("Unknown rotor type");
    }

    Rotor (
        const std::string& config,
        const int _basePosition,
        const std::string type
    ):
        configuration(config),
        basePosition(_basePosition - 1),
        type(type)
    {
        setPosition(_basePosition - 1);
    }

    void reset() {
        setPosition(basePosition);
    }

    bool madeFullRotation() const {
        return position == 0;
    }

    void rotate() {
        position = (position + 1) % alphabet.length();
        std::rotate(alphabet.begin(), alphabet.begin() + 1, alphabet.end());
    }

    char transform(char input) {
        int index = alphabet.find(input);
        Log::log("Rotor", type, input, configuration[index], true);
        return configuration[index];
    }

    char reverseTransform(char input) {
        int index = configuration.find(input);
        Log::log("Rotor back", type, input, alphabet[index], false);
        return alphabet[index];
    }

    void setPosition(int pos) {
        while (position != pos) {
            rotate();
        }
    }
};


#endif //CPP_ROTOR_H
