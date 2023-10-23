//
// Created by Dmitrii Tarasov on 11/10/2023.
//

#ifndef CPP_ROTOR_H
#define CPP_ROTOR_H

#include <iostream>
#include <string>
#include <algorithm>

#include "abstract/IRotor.h"
#include "Ring.h"
#include "Log.h"

class Rotor : public IRotor {
private:
    std::vector<int> baseConfig;
    std::vector<int> config;
    int basePosition = 0;
    int ringRotation = 0;

public:
    int position = 0;
    std::string type;

    Rotor (
        const std::string& _config,
        const int position,
        const std::string type,
        const int _ringRotation
    ):
        baseConfig(Ring::transform(_config)),
        config(Ring::transform(_config)),
        position(position - 1),
        basePosition(position - 1),
        type(type),
        ringRotation(_ringRotation - 1)
    {
        if (ringRotation > 0) {
            std::rotate(config.begin(), config.end() - ringRotation, config.end());
        }
    }

    static Rotor factory(std::string type, const int position, const int ringRotation) {
        if (type == "I") {
            //           ABCDEFGHIJKLMNOPQRSTUVWXYZ
            //           EKMFLGDQVZNTOWYHXUSPAIBRCJ
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", position, type, ringRotation);
        } else if (type == "II") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", position, type, ringRotation);
        } else if (type == "III") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", position, type, ringRotation);
        } else if (type == "IV") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB", position, type, ringRotation);
        } else if (type == "V") {
            //            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            return Rotor("VZBRGITYUPSDNHLXAWMJQOFECK", position, type, ringRotation);
        }

        throw std::invalid_argument("Unknown rotor type");
    }

    bool madeFullRotation() const override {
        return position == config.size();
    }

    void rotate() override {
        position = position + 1;

        if (position > config.size()) {
            position = 0;
        }
    }

    void reset() override {
        position = basePosition;
    }

    int transform(const int input) const override {
        int pos = (input + position) % config.size();
        return config[pos];
    }

    int reverseTransform(int input) const override {
        auto it = std::find(config.begin(), config.end(), input);
        int index = std::distance(config.begin(), it);
        return (config.size() + index - position) % config.size();
    }
};

#endif //CPP_ROTOR_H
