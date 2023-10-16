//
// Created by Dmitrii Tarasov on 11/10/2023.
//
#include <iostream>
#include "Rotor.h"
#include "Reflector.h"
#include "Commutator.h"

#ifndef CPP_ENIGMA_H
#define CPP_ENIGMA_H


class Enigma {
private:
    Reflector reflector;
    Commutator commutator;
    std::vector<Rotor> rotors;

public:
    Enigma(
        std::vector<Rotor> rotors,
        Reflector reflector,
        Commutator commutator
    ): rotors(rotors), reflector(reflector), commutator(commutator) {}

    char encrypt(char input) {
        char encrypted = transform(input, true);
        rotateRotors();
        return encrypted;
    }

    void reset() {
        for (Rotor& rotor : rotors) {
            rotor.reset();
        }
    }

private:
    char transform(char input, bool isEncryption) {
        input = commutator.transform(input);

        // Прямое преобразование через все роторы
        for (Rotor& rotor : rotors) {
            input = rotor.transform(input);
        }

        // Отражение от рефлектора
        input = reflector.reflect(input, isEncryption);

        // Обратное преобразование через все роторы в обратном порядке
        for (auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
            input = it->reverseTransform(input);
        }

        input = commutator.transform(input);

        return input;
    }

    void rotateRotors() {
        rotors[0].rotate();
        for (size_t i = 0; i < rotors.size() - 1; ++i) {
            if (rotors[i].madeFullRotation()) {
                rotors[i + 1].rotate();
            }
        }
    }
};


#endif //CPP_ENIGMA_H
