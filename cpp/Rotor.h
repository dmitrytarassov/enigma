//
// Created by Dmitrii Tarasov on 11/10/2023.
//

#ifndef CPP_ROTOR_H
#define CPP_ROTOR_H

#include <iostream>
#include <string>
#include <algorithm>

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
        } else if (type == "test-1") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("ABCDEFGHIJKLMNOPQRSTUVWXYZ", position, type);
        } else if (type == "test-2") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("UVWXYZKLMNOPQRSTABCDEFGHIJ", position, type);
        } else if (type == "test-3") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("HGFEDCBAYXWVUZIJTSRQPONMLK", position, type);
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
        position = (position + 1) % configuration.length();
        std::rotate(configuration.begin(), configuration.begin() + 1, configuration.end());
    }

    char transform(char input) {
        int index = alphabet.find(input);
//        std::cout << alphabet << std::endl;
//        std::cout << configuration << std::endl;
//        std::cout << "Rotor " << type << ": " << input << " -> " << configuration[index] << std::endl;
        return configuration[index];
    }

    char reverseTransform(char input) {
        int index = configuration.find(input);
//        std::cout << "Rotor back: " << input << " -> " << alphabet[index] << std::endl;
        return alphabet[index];
    }

    void setPosition(int pos) {
        while (position != pos) {
            rotate();
        }
    }
};


#endif //CPP_ROTOR_H
