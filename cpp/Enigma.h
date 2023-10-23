//
// Created by Dmitrii Tarasov on 11/10/2023.
//
#include <iostream>
#include "abstract/IRotor.h"
#include "abstract/IReflector.h"
#include "Commutator.h"

#ifndef CPP_ENIGMA_H
#define CPP_ENIGMA_H


class Enigma {

private:
    std::unique_ptr<IReflector> reflector;
    Commutator commutator;
    std::vector<std::unique_ptr<IRotor>> rotors;

public:
    Enigma(
        std::vector<std::unique_ptr<IRotor>> _rotors,
        std::unique_ptr<IReflector> _reflector,
        Commutator commutator
    ): rotors(std::move(_rotors)), reflector(std::move(_reflector)), commutator(commutator) {}

    int encrypt(int input) {
        int encrypted = transform(input, true);
        rotateRotors();
        return encrypted;
    }

    std::string encryptMessage(std::string& inputLine) {
        std::vector<int> indexes = Ring::transform(inputLine);
        std::vector<int> result;

        for (int index : indexes) {
            int value = encrypt(index);
            result.push_back(value);
        }

        std::string encryptedMessage = Ring::transform(result);

        return encryptedMessage;
    }

    void reset() {
        for (auto& rotorPtr : rotors) {
            rotorPtr->reset();
        }
    }

private:
    int transform(int input, bool isEncryption) {
        int result = input;

        result = commutator.transform(result);

        // Прямое преобразование через все роторы
        for (std::unique_ptr<IRotor>& rotor : rotors) {
            result = rotor -> transform(result);
        }

        // Отражение от рефлектора
        result = reflector -> reflect(result);

        // Обратное преобразование через все роторы в обратном порядке
        for (int i = rotors.size() - 1; i >= 0; i--) {
            result = rotors[i] -> reverseTransform(result);
        }

        result = commutator.transform(result);

        return result;
    }

    void rotateRotors() {
        rotors[0] -> rotate();
        for (size_t i = 0; i < rotors.size() - 1; ++i) {
            if (rotors[i] -> madeFullRotation()) {
                rotors[i + 1] -> rotate();
            }
        }
    }
};


#endif //CPP_ENIGMA_H
